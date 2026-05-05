#include "synapse/common/handlers.h"
#include "libcom/util.h"

NEX_WEAK
void
default_isr_handler(void)
{
#if defined(NEX_DEFAULT_ISR_HANDLER_BLOCKING)
  while (1);
#endif
}
