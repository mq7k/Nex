#include "libcom/sys/devmode.h"
#include "libcom/util.h"

void
_devmode_warning(
  const char* file,
  const char* func,
  u32 line,
  const char* fmt,
  ...
)
{
  va_list list;
  va_start(list, fmt);
  _devmode_log(
    "[Warning] %s:%u in function %s(): ",
    file,
    (ttype) line,
    func
  );
  _devmode_logv(fmt, list);
  va_end(list);
}

void
_devmode_error(
  const char* file,
  const char* func,
  u32 line,
  const char* fmt,
  ...
)
{
  va_list list;
  va_start(list, fmt);
  _devmode_log(
    "[Error] %s:%u in function %s(): ",
    file,
    (ttype) line,
    func
  );
  _devmode_logv(fmt, list);
  va_end(list);

  struct devmode_trace trace = {
    .file = file,
    .func = func,
    .line = line
  };
  devmode_halt(&trace);
}

void
_devmode_assert(
  u32 condition,
  const char* file,
  const char* func,
  u32 line,
  const char* fmt,
  ...
)
{
  if (condition)
  {
    return;
  }

  va_list list;
  va_start(list, fmt);
  _devmode_log(
    "[Error] Assertion failed: %s:%u in function %s(): ",
    file,
    (ttype) line,
    func
  );
  _devmode_logv(fmt, list);
  va_end(list);

  struct devmode_trace trace = {
    .file = file,
    .func = func,
    .line = line
  };
  devmode_halt(&trace);
}

void
_devmode_log(
  const char* fmt,
  ...
) 
{
  va_list list;
  va_start(list, fmt);
  _devmode_logv(fmt, list);
  va_end(list);
}

void NEX_WEAK
_devmode_logv(
  const char* fmt,
  va_list args
)
{
  (void) fmt;
  (void) args;
}

void NEX_WEAK
_devmode_halt(
  const struct devmode_trace* trace
)
{
  (void) trace;
  while (1);
}

