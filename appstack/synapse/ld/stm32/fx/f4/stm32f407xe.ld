INCLUDE "fx/f4/stm32f4.ld"

MEMORY
{
  ccram (rw) : ORIGIN = 0x10000000, LENGTH = 64K
  ram (rw) : ORIGIN = 0x20000000, LENGTH = 128K
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 512K
}

INCLUDE "fx/stm32fx.ld"
