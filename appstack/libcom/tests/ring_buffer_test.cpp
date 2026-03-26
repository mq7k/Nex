#include "data/ring_buffer.h"
#include "errcodes.h"
#include "libtest/libtest.hpp"
#include "util.h"

#define BUFSZ (16)
u8 buf[BUFSZ];
struct nex_ring_buffer rb;

void
reset(void)
{
  nex_ring_buffer_init(&rb, buf, BUFSZ);
  memset(buf, 0, BUFSZ);
}

void
test_ring_buffer_write_bytes(void)
{
  u8 src[32];
  for (u32 i = 0; i < 16; ++i)
  {
    src[i] = (u8) (i << 2);
  }

  i32 res;
  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);
  ASSERT_EQ(rb.size, 16);

  for (u32 i = 0; i < 16; ++i)
  {
    ASSERT_EQ(buf[i], (i << 2));
  }

  // Pushing partial transfers.
  reset();
  res = nex_ring_buffer_write_bytes(&rb, src, 8);
  ASSERT_EQ(res, 8);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 8);
  ASSERT_EQ(rb.size, 8);

  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 8);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 16);

  // Trying to write more bytes than capacity.
  reset();
  memset(buf, 0, BUFSZ);
  for (u32 i = 0; i < 32; ++i)
  {
    src[i] = (u8) (i << 2);
  }

  res = nex_ring_buffer_write_bytes(&rb, src, 32);
  ASSERT_EQ(res, 16);
  ASSERT_EQ(rb.size, 16);
  ASSERT_EQ(rb.tail, 0);

  for (u32 i = 0; i < 16; ++i)
  {
    ASSERT_EQ(buf[i], (i << 2));
  }
}

void
test_ring_buffer_write(void)
{
  i32 res;
  for (u32 i = 0; i < 16; ++i)
  {
    res = nex_ring_buffer_write(&rb, (u8) (i << 1));
    ASSERT_EQ(res, NEX_SUCCESS);
    ASSERT_EQ(rb.head, 0);
    ASSERT_EQ(rb.tail, (i + 1) & (BUFSZ - 1));
    ASSERT_EQ(rb.size, i + 1);
  }

  for (u32 i = 0; i < 16; ++i)
  {
    res = nex_ring_buffer_write(&rb, (u8) (127 + (i << 1)));
    ASSERT_EQ(res, -NERR_FULL);
  }

  for (u32 i = 0; i < 16; ++i)
  {
    ASSERT_EQ(buf[i], (u8) (i << 1));
  }
}

void
test_ring_buffer_pop_head(void)
{
  i32 res;
  for (u32 i = 0; i < 16; ++i)
  {
    res = nex_ring_buffer_write(&rb, (u8) (i << 1));
    ASSERT_EQ(res, NEX_SUCCESS);
  }

  u8 byte;
  for (u32 i = 0; i < 16; ++i)
  {
    res = nex_ring_buffer_pop_head(&rb, &byte);
    ASSERT_EQ(byte, (u8) (i << 1));
    ASSERT_EQ(rb.head, (i + 1) & (BUFSZ - 1));
    ASSERT_EQ(rb.tail, 0);
    ASSERT_EQ(rb.size, 16 - i - 1);
  }
}

void
test_ring_buffer_copy(void)
{
  u8 src[32];
  for (u32 i = 0; i < 16; ++i)
  {
    src[i] = (u8) (i << 2);
  }

  i32 res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);

  u8 dst[32];
  res = nex_ring_buffer_copy(&rb, dst, 16);
  ASSERT_EQ(res, 16);
  for (u32 i = 0; i < 16; ++i)
  {
    ASSERT_EQ(dst[i], src[i]);
  }

  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 0);

  // Trying partial copy.
  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);

  res = nex_ring_buffer_copy(&rb, dst, 8);
  ASSERT_EQ(res, 8);

  for (u32 i = 0; i < 8; ++i)
  {
    ASSERT_EQ(dst[i], src[i]);
  }

  res = nex_ring_buffer_copy(&rb, dst, 8);
  ASSERT_EQ(res, 8);

  for (u32 i = 0; i < 8; ++i)
  {
    ASSERT_EQ(dst[i], src[i + 8]);
  }

  // Mixing copy + write.
  reset();
  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 16);

  res = nex_ring_buffer_copy(&rb, dst, 8);
  ASSERT_EQ(res, 8);
  ASSERT_EQ(rb.head, 8);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 8);

  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 8);
  ASSERT_EQ(rb.head, 8);
  ASSERT_EQ(rb.tail, 8);
  ASSERT_EQ(rb.size, 16);
}

void
test_ring_buffer_peek_copy(void)
{
  i32 res;

  u8 src[32];
  for (u32 i = 0; i < 16; ++i)
  {
    src[i] = (u8) (i << 2);
  }

  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 16);

  u8 dst[32];
  res = nex_ring_buffer_peek_copy(&rb, dst, 16);
  ASSERT_EQ(res, 16);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 16);

  u8 dst2[32];
  res = nex_ring_buffer_peek_copy(&rb, dst, 8);
  res = nex_ring_buffer_peek_copy(&rb, dst2, 8);
  ASSERT_EQ(res, 8);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 16);

  for (u32 i = 0; i < 8; ++i)
  {
    ASSERT_EQ(dst[i], dst2[i]);
  }

  reset();
  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);

  res = nex_ring_buffer_copy(&rb, dst, 12);
  ASSERT_EQ(res, 12);

  res = nex_ring_buffer_write_bytes(&rb, src, 8);
  ASSERT_EQ(res, 8);

  ASSERT_EQ(rb.head, 12);
  ASSERT_EQ(rb.tail, 8);
  ASSERT_EQ(rb.size, 12);

  res = nex_ring_buffer_copy(&rb, dst, 12);
  ASSERT_EQ(res, 12);

  for (u32 i = 0; i < 4; ++i)
  {
    ASSERT_EQ(dst[i], src[i + 12]);
  }
  
  for (u32 i = 0; i < 8; ++i)
  {
    ASSERT_EQ(dst[i + 4], src[i]);
  }
}

void
test_ring_buffer_find(void)
{
  u8 src[32];
  memset(src, 0, 32);
  src[9] = 1;

  i32 res;

  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);

  res = nex_ring_buffer_find(&rb, 1, 0);
  ASSERT_EQ(res, 9);

  u8 dst[32];
  res = nex_ring_buffer_copy(&rb, dst, 10);
  res = nex_ring_buffer_find(&rb, 1, 0);
  ASSERT_EQ(res, -NERR_NOT_FOUND);

  reset();
  memset(src, 0, 32);
  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);

  res = nex_ring_buffer_copy(&rb, dst, 8);
  ASSERT_EQ(res, 8);

  src[6] = 1;
  res = nex_ring_buffer_write_bytes(&rb, src, 8);
  ASSERT_EQ(res, 8);

  res = nex_ring_buffer_find(&rb, 1, 0);
  ASSERT_EQ(res, 14);

  nex_ring_buffer_consume(&rb, (u32) res);
  u8 byte;
  res = nex_ring_buffer_pop_head(&rb, &byte);
  ASSERT_EQ(res, NOK);
  ASSERT_EQ(byte, 1);
}

void
test_ring_buffer_consume(void)
{
  u8 src[32];
  for (u32 i = 0; i < 16; ++i)
  {
    src[i] = (u8) (i << 2);
  }

  i32 res;

  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(res, 16);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 16);

  nex_ring_buffer_consume(&rb, 8);
  ASSERT_EQ(rb.head, 8);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 8);

  nex_ring_buffer_consume(&rb, 8);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 0);

  res = nex_ring_buffer_write_bytes(&rb, src, 16);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 16);

  res = nex_ring_buffer_consume(&rb, 32);
  ASSERT_EQ(res, -NERR_INV_ARG);
  ASSERT_EQ(rb.head, 0);
  ASSERT_EQ(rb.tail, 0);
  ASSERT_EQ(rb.size, 16);
}

int 
main() 
{
  const test_function_t tests[] = {
    TEST_FUNC(test_ring_buffer_write_bytes),
    TEST_FUNC(test_ring_buffer_write),
    TEST_FUNC(test_ring_buffer_pop_head),
    TEST_FUNC(test_ring_buffer_copy),
    TEST_FUNC(test_ring_buffer_peek_copy),
    TEST_FUNC(test_ring_buffer_find),
    TEST_FUNC(test_ring_buffer_consume),
  };

  return TESTS_RUN(tests);
}
