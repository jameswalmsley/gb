#include "memory.h"
#include "CPU.h"
#include "op_codes.h"
#include "emulator.h"
#include "ppu.h"

void emu_init(void) {
  CPU_init(gb_cpu);
  memory_init(memory);
  memory_load_cart(memory);
  ppu_init();
}

bool pause = true;
bool stepping = false;

void emu_pause(void) {
    if(pause) pause = false;
    else pause = true;
}

void emu_execute(void) {
  if(gb_cpu->cycles <= 0 && pause)  //done enough "clocks"
  {
      //fetch
      uint8_t op = memory_read8(memory, gb_cpu->PC);  //read OP code
      DEBUG_PRINTF("OP: 0x%04X:0x%02X::", gb_cpu->PC, op);
      gb_cpu->PC += 1; //inc pc

      //execute
      op_codes[op]();
      // if(gb_cpu->PC == 0x100 && !stepping) stepping = true;
      if(stepping) pause = false;
      DEBUG_PRINTF("PC: 0x%04X\nSP: 0x%04X\n\nAF:0x%04X\nBC:0x%04X\nDE:0x%04X\nHL:0x%04X\n", gb_cpu->PC,gb_cpu->SP,*gb_cpu->AF,*gb_cpu->BC,*gb_cpu->DE,*gb_cpu->HL);
      if(memory->memory[0xFF02] == 0x82) printf("%c\n", memory->memory[0xFF01]);
      CPU_handle_interrupt(gb_cpu);
  }

  ppu_run();

  if(pause) gb_cpu->cycles -= 1;
}

void emu_end(void) {
  ppu_close();
}
