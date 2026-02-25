#ifndef SYSTEM_SCHEDULER_TASK_EXEC_HISTORY_H
#define SYSTEM_SCHEDULER_TASK_EXEC_HISTORY_H

#include "libcom/types.h"
#include "libcom/util.h"

BEGIN_DECLARATIONS

#define SCHEDULER_EXEC_HISTORY_COUNT (8)

struct scheduler_task_exec_history
{
  u64 arr[SCHEDULER_EXEC_HISTORY_COUNT];
  u32 count;
  u64 average;

  u32 cpu_usage;
  u32 tick_usage;

  u32 ha;
};

void
task_history_init(
  struct scheduler_task_exec_history* history
);

void
task_history_add_sample(
  struct scheduler_task_exec_history* history,
  u64 sample
);

u64
task_history_get_average(
  struct scheduler_task_exec_history* history
);

u64
task_history_get_last_exec_time(
  struct scheduler_task_exec_history* history
);

END_DECLARATIONS

#endif
