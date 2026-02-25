#include "system/scheduler/task_history.h"
#include "libcom/util.h"

void
task_history_init(
  struct scheduler_task_exec_history* history
)
{
  history->count = 0;
  history->average = 0;
  history->ha = 140;
  history->tick_usage = 0;
}

void
task_history_add_sample(
  struct scheduler_task_exec_history* history,
  u64 sample
)
{
  u32 idx = FAST_MOD(history->count, SCHEDULER_EXEC_HISTORY_COUNT);

  if (history->count >= SCHEDULER_EXEC_HISTORY_COUNT)
  {
    u64 oldest = history->arr[idx];
    history->average -= oldest;
  }

  history->average += sample;
  history->arr[idx] = sample;
  ++history->count;
}

u64
task_history_get_average(
  struct scheduler_task_exec_history* history
)
{
  u32 count = MIN(history->count, SCHEDULER_EXEC_HISTORY_COUNT);
  return history->average / count;
}

u64
task_history_get_last_exec_time(
  struct scheduler_task_exec_history* history
)
{
  u32 idx = FAST_MOD(
    history->count + (SCHEDULER_EXEC_HISTORY_COUNT - 1),
    SCHEDULER_EXEC_HISTORY_COUNT
  );
  return history->arr[idx];
}
