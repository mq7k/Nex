#ifndef SYSL_SCHEDULER_H
#define SYSL_SCHEDULER_H

#include "libcom/data/queue.h"
#include "libcom/types.h"
#include "libcom/util.h"
#include "system/scheduler/backend/sif.h"
#include "system/scheduler/task_history.h"

BEGIN_DECLARATIONS

#define SCHEDULER_MAX_PERIODIC_TASKS (32)
#define SCHEDULER_MAX_STATIC_TASKS (32)

struct scheduler_task;
typedef void (*fn)(struct scheduler_task*, void*);

enum scheduler_task_flag : u32
{
  SCHEDULER_TASK_FLAG_ALLOCATED = (1u << 0),
  SCHEDULER_TASK_FLAG_ENABLED = (1u << 1),
  SCHEDULER_TASK_EXCLUDE_FROM_STATS = (1u << 2)
};

struct scheduler_task
{
  const char* name;
  void* ctx;
  fn callback;
  u32 priority;
  u32 idx;
  u32 delay_us;
  u32 ticks_delay;
  u32 ticks_delay_left;
  u32 flags;

  struct scheduler_task_exec_history history;
};

struct scheduler_backend
{
  struct scheduler_ts_backend_vtable* ts_vtable;
  void* ts_ctx;

  struct scheduler_arch_backend_vtable* arch_vtable;
};

struct system_scheduler
{
  struct scheduler_task allocated_tasks[SCHEDULER_MAX_PERIODIC_TASKS];
  u32 allocated_tasks_count;

  // Ordered by:
  // - Priority;
  u32 active_tasks[SCHEDULER_MAX_PERIODIC_TASKS];
  u32 active_tasks_count;

  u32 tick_ready;
  u32 max_tick_time_us;
  u32 max_tick_time_tt;
  u64 acc;

  struct scheduler_backend backend;
};

void
system_scheduler_init(
  struct system_scheduler* scheduler
);

void
system_scheduler_start(
  struct system_scheduler* scheduler
);

void
system_scheduler_stop(
  struct system_scheduler* scheduler
);

struct scheduler_task*
system_scheduler_task_alloc(
  struct system_scheduler* scheduler
);

void
system_scheduler_task_free(
  struct system_scheduler* scheduler,
  struct scheduler_task* task
);

u32
system_scheduler_task_enable(
  struct system_scheduler* scheduler,
  struct scheduler_task* task
);

void
system_scheduler_task_disable(
  struct system_scheduler* scheduler,
  struct scheduler_task* task
);

void
system_scheduler_tick(
  struct system_scheduler* scheduler
);

void
system_scheduler_wakeup(
  struct system_scheduler* scheduler
);

void
system_scheduler_loop(
  struct system_scheduler* scheduler
);

u32
system_scheduler_get_task_cpu_usage(
  struct scheduler_task* task
);

u32
system_scheduler_get_task_tick_usage(
  struct scheduler_task* task
);

END_DECLARATIONS

#endif
