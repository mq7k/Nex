INCLUDE "stm32f1.ld"

MEMORY
{
  ram (rw) : ORIGIN = 0x20000000, LENGTH = 6K
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 32K
}

INCLUDE "fx/stm32fx.ld"
