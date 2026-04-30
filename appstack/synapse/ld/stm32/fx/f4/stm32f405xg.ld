INCLUDE "fx/f4/stm32f4.ld"

MEMORY
{
  ram (rw) : ORIGIN = 0x20000000, LENGTH = 128K
  ccram (rw) : ORIGIN = 0x10000000, LENGTH = 64K
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
}

INCLUDE "fx/stm32fx.ld"
