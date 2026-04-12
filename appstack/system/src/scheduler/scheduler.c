#include "system/scheduler/scheduler.h"
#include "libcom/util.h"
#include "synapse/backends/arch/cpu_instrinsic.h"
#include "system/scheduler/task_history.h"
#include "system/time/time.h"
#include "synapse/cpu/cortex/common/sys.h"

#include <string.h>

void
system_scheduler_init(
  struct system_scheduler* scheduler
)
{
  scheduler->active_tasks_count = 0;
  scheduler->allocated_tasks_count = 0;
  scheduler->active_tasks_count = 0;

  for (u32 i = 0; i < SCHEDULER_MAX_PERIODIC_TASKS; ++i)
  {
    scheduler->allocated_tasks[i].priority = 0xffff;
    scheduler->allocated_tasks[i].flags = 0;
    scheduler->allocated_tasks[i].ticks_delay_left = 0;
    scheduler->allocated_tasks[i].ticks_delay = 0;
    scheduler->active_tasks[i] = 0;
  }
}

struct scheduler_task*
system_scheduler_task_alloc(
  struct system_scheduler* scheduler
)
{
  if (scheduler->allocated_tasks_count + 1 >= SCHEDULER_MAX_PERIODIC_TASKS)
  {
    return NULL;
  }

  u32 idx = scheduler->allocated_tasks_count++;
  struct scheduler_task* task;

  task = &scheduler->allocated_tasks[idx];
  task->idx = idx;
  task->name = 0;
  task->flags = SCHEDULER_TASK_FLAG_ALLOCATED;

  return task;
}

void
system_scheduler_task_free(
  struct system_scheduler* scheduler,
  struct scheduler_task* task
)
{
  if (task->flags & SCHEDULER_TASK_FLAG_ENABLED)
  {
    system_scheduler_task_disable(scheduler, task);
  }

  task->flags = 0;
}

u32
system_scheduler_task_enable(
  struct system_scheduler* scheduler,
  struct scheduler_task* task
)
{
  const u32 active_tasks_count = scheduler->active_tasks_count;
  if (active_tasks_count >= SCHEDULER_MAX_PERIODIC_TASKS)
  {
    return NEX_FAILURE;
  }

  task->last_exec_time = 0;

  // delay_us > max_tick_time_us is a user configuration error. 
  // We can only perform a work-around.
  // There is no way to execute a task faster then the scheduler tick rate.
  task->ticks_delay = task->delay_us / scheduler->max_tick_time_us;
  if (task->ticks_delay == 0)
  {
    // By being an integer division, if delay_us > max_tick_time_us,
    // ticks_delays will always be 0.
    task->ticks_delay = 1;
  }

  // Executes in the next scheduler tick.
  task->ticks_delay_left = 1;

  struct scheduler_task* active_task;
  u32 priority = task->priority;

  for (u32 i = 0; i < active_tasks_count; ++i)
  {
    u32 idx = scheduler->active_tasks[active_tasks_count - i - 1];
    active_task = &scheduler->allocated_tasks[idx];
    if (active_task->priority >= priority)
    {
      scheduler->active_tasks[active_tasks_count - i] = idx;
      continue;
    }

    scheduler->active_tasks[active_tasks_count - i - 1] = task->idx;
    ++scheduler->active_tasks_count;
    task->flags |= SCHEDULER_TASK_FLAG_ENABLED;
    return NEX_SUCCESS;
  }

  // If this is the first task being scheduled,
  // or it has the highest priority (lower number),
  // add it to the head of the list.
  scheduler->active_tasks[0] = task->idx;
  ++scheduler->active_tasks_count;
  task->flags |= SCHEDULER_TASK_FLAG_ENABLED;

  return NEX_SUCCESS;
}

void
system_scheduler_task_disable(
  struct system_scheduler* scheduler,
  struct scheduler_task* task
)
{
  struct scheduler_task* target_task;
  const u32 active_tasks_count = scheduler->active_tasks_count;
  for (u32 i = 0; i < active_tasks_count; ++i)
  {
    u32 idx = scheduler->active_tasks[i];
    target_task = &scheduler->allocated_tasks[idx];
    if (target_task == task)
    {
      while (i < active_tasks_count - 1)
      {
        scheduler->active_tasks[i] = scheduler->active_tasks[i + 1];
      }

      --scheduler->active_tasks_count;
      task->flags &= ~SCHEDULER_TASK_FLAG_ENABLED;
    }
  }
}

void
system_scheduler_tick(
  struct system_scheduler* scheduler
)
{
  for (u32 i = 0; i < scheduler->active_tasks_count; ++i)
  {
    u32 idx = scheduler->active_tasks[i];
    struct scheduler_task* task = &scheduler->allocated_tasks[idx];
    if (--task->ticks_delay_left == 0)
    {
      task->callback(task, task->ctx);
      task->ticks_delay_left = task->ticks_delay;
    }
  }
}

void
system_scheduler_wakeup(
  struct system_scheduler* scheduler
)
{
  scheduler->tick_ready = 1;
}

static void
_wait_until_next_tick(
  struct system_scheduler* scheduler
)
{
  while (1)
  {
    syn_irq_disable();
    if (scheduler->tick_ready)
    {
      scheduler->tick_ready = 0;
      syn_irq_enable();
      return;
    }

    syn_irq_enable();
    syn_wait_for_interrupt();
  }
}

void
system_scheduler_loop(
  struct system_scheduler* scheduler
)
{
  while (1)
  {
    _wait_until_next_tick(scheduler);
    system_scheduler_tick(scheduler);
  }
}

