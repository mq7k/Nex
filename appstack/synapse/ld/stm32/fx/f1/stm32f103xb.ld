INCLUDE "fx/f1/stm32f1.ld"

MEMORY
{
  ram (rw) : ORIGIN = 0x20000000, LENGTH = 20K
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 128K
}

INCLUDE "fx/stm32fx.ld"
