INCLUDE "fx/f1/stm32f1.ld"

MEMORY
{
  ram (rw) : ORIGIN = 0x20000000, LENGTH = 96K
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
}

INCLUDE "fx/stm32fx.ld"
