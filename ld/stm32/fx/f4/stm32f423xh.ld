INCLUDE "fx/f4/stm32f4.ld"

MEMORY
{
  ram (rw) : ORIGIN = 0x20000000, LENGTH = 320K
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 1536K
}

INCLUDE "fx/stm32fx.ld"
