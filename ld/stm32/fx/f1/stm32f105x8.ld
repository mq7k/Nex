INCLUDE "stm32f1.ld"

MEMORY
{
  ram (rw) : ORIGIN = 0x20000000, LENGTH = 64K
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 64K
}

INCLUDE "fx/stm32fx.ld"
