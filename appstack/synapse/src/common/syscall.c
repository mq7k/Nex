#include "types.h"
#include "util.h"
#include <sys/types.h>

NEX_WEAK
void
_exit(
  int status
)
{
  (void) status;
  while (1);
}

NEX_WEAK
int 
_kill(
  pid_t pid,
  int sig
)
{
  (void) pid;
  (void) sig;
  return -1;
}

NEX_WEAK
pid_t 
_getpid(void)
{
  return -1;
}

NEX_WEAK
int 
_write(
  int fd,
  const void* buf,
  size_t count
)
{
  (void) fd;
  (void) buf;
  (void) count;
  return -1;
}

NEX_WEAK
void*
_sbrk(
  iptr inc
)
{
  (void) inc;
  return NULL;
}

NEX_WEAK
ssize_t
_read(
  int fd,
  void* buf,
  size_t count
)
{
  (void) fd;
  (void) buf;
  (void) count;
  return 0;
}

NEX_WEAK
int
_close(
  int fd
)
{
  (void) fd;
  return 0;
}

NEX_WEAK
off_t
_lseek(
  int fd,
  off_t offset,
  int whence
)
{
  (void) fd;
  (void) offset;
  (void) whence;
  return -1;
}
