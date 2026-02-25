INCLUDE "stm32f7.ld"

MEMORY
{
  ram (rw) : ORIGIN = 0x20000000, LENGTH = 512K
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 2M
}

INCLUDE "fx/stm32fx.ld"
