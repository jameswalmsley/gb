#include "emulator.h"
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "CPU.h"

int main(int argc, const char * argv[])
{
  uint8_t exit = 1;
  uint8_t old_pc = 0;
  uint16_t step = 0;
  // DEBUG_PRINTF("GB emulator...\n");
  emu_init();
  for(;;)
  {
    emu_execute();
    if(gb_cpu->cycles == 144 || step)
    {
        scanf("%d\n", &exit);
        step = 1;
        if(exit == 0) break;
    }
  }
  emu_end();
  return 0;
}
