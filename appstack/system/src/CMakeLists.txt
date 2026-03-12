nex_add_sources(nex_system
  profiler/profiler.c

  scheduler/backend/arch/arm.c
  scheduler/backend/ts/stm32_tim.c
  scheduler/scheduler.c
  scheduler/task_history.c

  time/backend/stm32_tim.c
  time/time.c
)

# nex_add_headers(nex_system
#   backends/crc/becrc.h
#
#   profiler/profiler.h
#
#   scheduler/backend/ts/stm32_tim.h
#   scheduler/backend/sif.h
#
#   scheduler/scheduler.h
#   scheduler/task_history.h
#
#   time/backend/stm32_tim.h
#   time/backend/timeif.h
#   time/time.h
# )
