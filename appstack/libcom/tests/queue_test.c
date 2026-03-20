#include "data/queue.h"
#include "libtest/libtest.h"
#include "util.h"

struct queue queue;

#define BUFSZ (16)
#define QUEUESZ (4)

NEX_ALIGN_AS(u32)
char buf[BUFSZ] = {};

void
setup(void)
{
  nex_queue_init(
    &queue, 
    buf,
    QUEUESZ,
    4
  );
}

void
reset(void)
{
  nex_queue_init(
    &queue, 
    buf,
    QUEUESZ,
    4
  );
}

void
test_queue_init(void)
{
  u32 res;

  res = nex_queue_init(
    &queue,
    buf,
    4,
    4
  );
  ASSERT_EQ(res, NEX_SUCCESS);

  res = nex_queue_init(
    &queue,
    buf,
    3,
    4
  );
  ASSERT_EQ(res, NEX_FAILURE);
}

void
test_queue_alloc(void)
{
  u32* ptr = (u32*) nex_queue_alloc(&queue);
  ASSERT_EQ(queue.head, 0);
  ASSERT_EQ(queue.tail, 1);
  ASSERT_EQ(queue.size, 1);
  ASSERT_EQ(*ptr, 0);
  *ptr = 32;

  u32* val = nex_queue_peek_head(&queue);
  ASSERT_EQ(*val, *ptr);

  val = nex_queue_peek_tail(&queue);
  ASSERT_EQ(*val, *ptr);

  val = nex_queue_peek_nth(&queue, 0);
  ASSERT_EQ(*val, *ptr);

  u32 res = nex_queue_init(
    &queue,
    buf,
    4,
    4
  );
  ASSERT_EQ(res, NEX_SUCCESS);

  for (u32 i = 0; i < 4; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
    *ptr = 10 * i;
  }

  ASSERT_EQ(nex_queue_size(&queue), 4);

  ptr = nex_queue_alloc(&queue);
  ASSERT_NULL(ptr);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(nex_queue_size(&queue), 3);
  ASSERT_EQ(*ptr, 30);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(nex_queue_size(&queue), 2);
  ASSERT_EQ(*ptr, 20);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(nex_queue_size(&queue), 1);
  ASSERT_EQ(*ptr, 10);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(nex_queue_size(&queue), 0);
  ASSERT_EQ(*ptr, 0);
}

void
test_queue_peek_nth(void)
{
  u32* ptr;

  for (u32 i = 0; i < 4; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
    *ptr = 10 * i;
  }

  ptr = nex_queue_peek_nth(&queue, 0);
  ASSERT_EQ(*ptr, 0);

  ptr = nex_queue_peek_nth(&queue, 1);
  ASSERT_EQ(*ptr, 10);

  ptr = nex_queue_peek_nth(&queue, 2);
  ASSERT_EQ(*ptr, 20);
  
  ptr = nex_queue_peek_nth(&queue, 3);
  ASSERT_EQ(*ptr, 30);

  nex_queue_pop_head(&queue);

  ptr = nex_queue_peek_nth(&queue, 0);
  ASSERT_EQ(*ptr, 10);

  ptr = nex_queue_peek_nth(&queue, 1);
  ASSERT_EQ(*ptr, 20);
  
  ptr = nex_queue_peek_nth(&queue, 2);
  ASSERT_EQ(*ptr, 30);

  nex_queue_pop_head(&queue);

  ptr = nex_queue_peek_nth(&queue, 0);
  ASSERT_EQ(*ptr, 20);
  
  ptr = nex_queue_peek_nth(&queue, 1);
  ASSERT_EQ(*ptr, 30);

  nex_queue_pop_head(&queue);

  ptr = nex_queue_peek_nth(&queue, 0);
  ASSERT_EQ(*ptr, 30);
}

void
test_queue_peek_head(void)
{
  u32* ptr;

  for (u32 i = 0; i < 4; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
    *ptr = 10 * i;
  }

  // Doing it twice to make sure
  // peek_head doesn't pop elements.
  ptr = nex_queue_peek_head(&queue);
  ASSERT_EQ(*ptr, 0);
  ptr = nex_queue_peek_head(&queue);
  ASSERT_EQ(*ptr, 0);
  ASSERT_EQ(nex_queue_size(&queue), 4);

  ptr = nex_queue_peek_head(&queue);
  nex_queue_pop_head(&queue);
  ASSERT_EQ(*ptr, 0);
  ASSERT_EQ(nex_queue_size(&queue), 3);

  ptr = nex_queue_peek_head(&queue);
  nex_queue_pop_head(&queue);
  ASSERT_EQ(*ptr, 10);
  ASSERT_EQ(nex_queue_size(&queue), 2);

  ptr = nex_queue_peek_head(&queue);
  nex_queue_pop_head(&queue);
  ASSERT_EQ(*ptr, 20);
  ASSERT_EQ(nex_queue_size(&queue), 1);

  ptr = nex_queue_peek_head(&queue);
  nex_queue_pop_head(&queue);
  ASSERT_EQ(*ptr, 30);
  ASSERT_EQ(nex_queue_size(&queue), 0);
}

void
test_queue_peek_tail(void)
{
  u32* ptr;

  for (u32 i = 0; i < 4; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
    *ptr = 10 * i;
  }
  
  // Doing it twice to make sure
  // peek_tail doesn't pop elements.
  ptr = nex_queue_peek_tail(&queue);
  ASSERT_EQ(*ptr, 30);
  ptr = nex_queue_peek_tail(&queue);
  ASSERT_EQ(*ptr, 30);
  ASSERT_EQ(nex_queue_size(&queue), 4);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(*ptr, 30);
  ASSERT_EQ(nex_queue_size(&queue), 3);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(*ptr, 20);
  ASSERT_EQ(nex_queue_size(&queue), 2);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(*ptr, 10);
  ASSERT_EQ(nex_queue_size(&queue), 1);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(*ptr, 0);
  ASSERT_EQ(nex_queue_size(&queue), 0);
}

void
test_queue_pop_head(void)
{
  u32* ptr;

  for (u32 i = 0; i < 4; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
    *ptr = 10 * i;
  }

  ptr = nex_queue_peek_head(&queue);
  nex_queue_pop_head(&queue);
  ASSERT_EQ(queue.head, 1);
  ASSERT_EQ(queue.size, 3);
  ASSERT_EQ(*ptr, 0);

  ptr = nex_queue_peek_head(&queue);
  nex_queue_pop_head(&queue);
  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.size, 2);
  ASSERT_EQ(*ptr, 10);

  ptr = nex_queue_peek_head(&queue);
  nex_queue_pop_head(&queue);
  ASSERT_EQ(queue.head, 3);
  ASSERT_EQ(queue.size, 1);
  ASSERT_EQ(*ptr, 20);

  ptr = nex_queue_peek_head(&queue);
  nex_queue_pop_head(&queue);
  ASSERT_EQ(queue.head, 0);
  ASSERT_EQ(queue.size, 0);
  ASSERT_EQ(*ptr, 30);
}

void
test_queue_pop_tail(void)
{
  u32* ptr;

  for (u32 i = 0; i < 4; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
    *ptr = 10 * i;
  }

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(queue.tail, 3);
  ASSERT_EQ(queue.size, 3);
  ASSERT_EQ(*ptr, 30);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 2);
  ASSERT_EQ(*ptr, 20);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(queue.tail, 1);
  ASSERT_EQ(queue.size, 1);
  ASSERT_EQ(*ptr, 10);

  ptr = nex_queue_peek_tail(&queue);
  nex_queue_pop_tail(&queue);
  ASSERT_EQ(queue.tail, 0);
  ASSERT_EQ(queue.size, 0);
  ASSERT_EQ(*ptr, 0);
}

void
test_queue_wrap(void)
{
  u32* ptr;

  /*
   * Popping head
   */
  for (u32 i = 0; i < 2; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
  }

  ASSERT_EQ(queue.head, 0);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 2);

  nex_queue_pop_head(&queue);
  nex_queue_pop_head(&queue);

  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 0);

  for (u32 i = 0; i < 4; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
  }

  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 4);

  nex_queue_pop_head(&queue);
  ASSERT_EQ(queue.head, 3);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 3);

  nex_queue_pop_head(&queue);
  ASSERT_EQ(queue.head, 0);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 2);

  nex_queue_pop_head(&queue);
  ASSERT_EQ(queue.head, 1);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 1);

  nex_queue_pop_head(&queue);
  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 0);

  /*
   * Popping tail
   */
  nex_queue_clear(&queue);
  for (u32 i = 0; i < 2; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
  }

  ASSERT_EQ(queue.head, 0);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 2);

  nex_queue_pop_head(&queue);
  nex_queue_pop_head(&queue);

  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 0);

  for (u32 i = 0; i < 4; ++i)
  {
    ptr = nex_queue_alloc(&queue);
    ASSERT_NON_NULL(ptr);
  }

  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 4);

  nex_queue_pop_tail(&queue);
  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 1);
  ASSERT_EQ(queue.size, 3);

  nex_queue_pop_tail(&queue);
  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 0);
  ASSERT_EQ(queue.size, 2);

  nex_queue_pop_tail(&queue);
  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 3);
  ASSERT_EQ(queue.size, 1);

  nex_queue_pop_tail(&queue);
  ASSERT_EQ(queue.head, 2);
  ASSERT_EQ(queue.tail, 2);
  ASSERT_EQ(queue.size, 0);
}

int 
main() 
{
  const test_function_t tests[] = {
    TEST_FUNC(test_queue_init),
    TEST_FUNC(test_queue_alloc),
    TEST_FUNC(test_queue_peek_nth),
    TEST_FUNC(test_queue_peek_head),
    TEST_FUNC(test_queue_peek_tail),
    TEST_FUNC(test_queue_pop_head),
    TEST_FUNC(test_queue_pop_tail),
    TEST_FUNC(test_queue_wrap)
  };

  return TESTS_RUN(tests);
}

