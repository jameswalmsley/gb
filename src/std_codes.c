#include "CPU.h"
#include "instructions.h"
#include "memory.h"
#include "op_codes.h"
#include <stdio.h>

// 0x00 NOP
// 1 4
void NOP(void) { printf(" %s\n", __func__); gb_cpu->cycles += 4; }

//0x01 LD BC, d16
//3 12
void LD_BC_d16(void) { printf(" %s\n", __func__);
  gb_cpu->BC = memory_read16(memory, gb_cpu->PC);
  gb_cpu->PC += 2;
  gb_cpu->cycles += 12;
}

//0x02 LD (BC), A
// 1 8
void LD_mBC_A(void) {
    uint8_t val = *gb_cpu->A;
    memory_write8(memory, gb_cpu->BC, val);
     printf(" %s: (0x%04X) <- 0x%02X\n", __func__, gb_cpu->BC, val);
    gb_cpu->cycles += 8;
}

//0x03 INC BC
// 1 8
void INC_BC(void) { printf(" %s\n", __func__);
    instr_inc_nn(&gb_cpu->BC);
    gb_cpu->cycles += 8;
}

//0x04 INC B
// 1 4
void INC_B(void) { printf(" %s\n", __func__);
    instr_inc_n(gb_cpu->B);
    gb_cpu->cycles += 4;
}

//0x05 DEC B
// 1 4
void DEC_B(void) { printf(" %s\n", __func__);
  instr_dec_n(gb_cpu->B);
  gb_cpu->cycles += 4;
}

//0x06 LD B, d8
//2 8
void LD_B_d8(void) { printf(" %s\n", __func__);
  uint8_t d8 = memory_read8(memory, gb_cpu->PC);
  instr_load_ab(gb_cpu->B, d8);
  gb_cpu->PC += 1;
  gb_cpu->cycles += 8;
}

// 0x07 RLCA
// 1 4
void RLCA(void) { printf(" %s\n", __func__);
  instr_rlc(gb_cpu->A);
  gb_cpu->cycles += 4;
}

// 0x08 LD (a16), SP
// 3 20
void LD_a16_SP(void) { printf(" %s\n", __func__);
  instr_load_ab16(&gb_cpu->SP, memory_read16(memory, gb_cpu->PC));
  gb_cpu->PC += 2;
  gb_cpu->cycles += 20;
}

// 0x09 ADD HL, BC
// 1 8
void ADD_HL_BC(void) { printf(" %s\n", __func__);
  instr_add_HL(&gb_cpu->HL, gb_cpu->BC);
  gb_cpu->cycles += 4;
}

// 0x0A LD A, (BC)
// 1 8
void LD_A_BC(void) { printf(" %s\n", __func__);
  instr_load_ab(gb_cpu->A, memory_read8(memory, gb_cpu->BC));
  gb_cpu->cycles += 8;
}

// 0x0B DEC BC
// 1 8
void DEC_BC(void) { printf(" %s\n", __func__);
  instr_dec_nn(&gb_cpu->BC);
  gb_cpu->cycles += 8;
}

// 0x0C INC C
// 1 4
void INC_C(void) { printf(" %s\n", __func__);
  instr_inc_n(gb_cpu->C);
  gb_cpu->cycles += 4;
}

// 0x0D DEC C
// 1 3
void DEC_C(void) { printf(" %s\n", __func__);
  instr_dec_n(gb_cpu->C);
  gb_cpu->cycles += 4;
}

// 0x0E LD C, d8
// 2 8å
void LD_C_d8(void) {
  uint8_t val = memory_read8(memory, gb_cpu->PC);
  printf(" %s: Load C w/ 0x%02X\n", __func__, val);
  instr_load_ab(gb_cpu->C, val);
  gb_cpu->PC += 1;
  gb_cpu->cycles += 4;
}

// 0x0F RRCA
void RRCA(void) { printf(" %s\n", __func__);
  instr_rrc(gb_cpu->A);
  gb_cpu->cycles += 4;
}

// 0x10 STOP 0
void STOP(void) { printf(" %s\n", __func__);
  instr_stop();
  gb_cpu->PC += 2;
  gb_cpu->cycles += 4;
}

// 0x11 NAME
void LD_DE_d16(void) { printf(" %s\n", __func__);
  instr_load_ab16(&gb_cpu->DE, memory_read16(memory, gb_cpu->PC));
  gb_cpu->PC += 2;
  gb_cpu->cycles += 12;
}

// 0x12 LD (DE) A
void LD_DE_A(void) { printf(" %s\n", __func__);

  // instr_load_ab(memory_write8(memory, ))
  gb_cpu->cycles += 8;
}

// 0x13 INC DE
// 1 8
void INC_DE(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 8;
}

// 0x14 INC_D
// 1 4
void INC_D(void) { printf(" %s\n", __func__);
instr_inc_n(gb_cpu->D);
gb_cpu->cycles += 4;
}

// 0x15 DEC D
// 1 4
void DEC_D(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 4;
}

// 0x16 LD D, d8
// 2 8
void LD_D_d8(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 8;
}

// 0x17 RLA
// 1 4
void RLA(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 4;
}

// 0x18 JR r8
// 2 12
void JR_r8(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 12;
}

// 0x19 ADD HL, DE
// 1 8
void ADD_HL_DE(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 8;
}

// 0x1A LD A, (DE)
// 1 8
void LD_A_DE(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 8;
}

// 0x1B DEC DE
// 1 8
void DEC_DE(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 8;
}

// 0x1C INC_E
// 1 4
void INC_E(void) { printf(" %s\n", __func__);
instr_inc_n(gb_cpu->E);
gb_cpu->cycles += 4;
}

// 0x1D DEC E
// 1 4
void DEC_E(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 4;
}

// 0x1E LD e, d8
// 1 4
void LD_E_d8(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 4;
}

// 0x1F RRA
// 1 4
void RRA(void) { printf(" %s\n", __func__);
  gb_cpu->cycles += 4;
}


// 0x2....
// JR NZ,r8
// 2  12/8
void JR_NZ_r8(void) {
  if(CPU_check_flag(ZERO_FLAG) == 0) {
    uint8_t val = memory_read8(memory, gb_cpu->PC);
    instr_jr(val);
    printf(" %s: JR J 0x%04X to 0x%04X \n", __func__, val, gb_cpu->PC);
    gb_cpu->cycles += 12;
  }
  else {
    printf(" %s: JR, no jump\n", __func__);
    gb_cpu->cycles += 8;
    gb_cpu->PC += 1;
  }

}

// LD HL,d16
// 3  12
void LD_HL_d16(void){
  instr_load_ab16(&gb_cpu->HL, memory_read16(memory, gb_cpu->PC));
  printf(" %s: load HL w/ 0x%04X\n", __func__, gb_cpu->HL);
  gb_cpu->PC += 2;
}

//LD (HL+),A
// 1  8
void LD_HLp_A(void) { printf(" %s\n", __func__);

}

// INC HL
// 1  8
void INC_HL(void) { printf(" %s\n", __func__);
instr_inc_nn(&gb_cpu->HL);
gb_cpu->cycles += 8;
}

// INC H
// 1  4
void INC_H(void) { printf(" %s\n", __func__);
instr_inc_n(gb_cpu->H);
gb_cpu->cycles += 4;
}

// DEC H
// 1  4
void DEC_H(void) { printf(" %s\n", __func__);

}

// LD H,d8
// 2  8
void LD_H_d8(void) { printf(" %s\n", __func__); }

// DAA
// 1  4
void DAA(void) { printf(" %s\n", __func__); }

// JR Z,r8
// 2  12/8
void JR_Z_r8(void) { printf(" %s\n", __func__); }

// ADD HL,HL
// 1  8
void ADD_HL_HL(void) { printf(" %s\n", __func__); }

// LD A,(HL+)
// 1  8
void LD_A_HLp(void) { printf(" %s\n", __func__); }

// DEC HL
// 1  8
void DEC_HL(void) { printf(" %s\n", __func__); }

// INC L
// 1  4
void INC_L(void) { printf(" %s\n", __func__);     instr_inc_n(gb_cpu->L);
    gb_cpu->cycles += 4;}

// DEC L
// 1  4
void DEC_L(void) { printf(" %s\n", __func__); }

// LD L,d8
// 2  8
void LD_L_d8(void) { printf(" %s\n", __func__); }

// CPL
// 1  4
void CPL(void) { printf(" %s\n", __func__); }

//0x3....
// JR NC,r8
// 2  12/8
void JR_NC_r8(void) {
printf(" %s\n", __func__);
}

// LD SP,d16
// 3  12
void LD_SP_d16(void) {
  uint16_t x = memory_read16(memory, gb_cpu->PC);
  gb_cpu->SP = x;

  printf(" %s:  SP = %04X from %d\n", __func__, gb_cpu->SP, gb_cpu->PC);
  gb_cpu->PC += 2;
}

// LD (HL-),A
// 1  8
void LD_HLs_A(void) {
  memory_write8(memory, gb_cpu->HL, *gb_cpu->A);
  gb_cpu->HL -= 1;
  printf(" %s\n", __func__);
}

// INC SP
// 1  8
void INC_SP(void) {
printf(" %s\n", __func__);
instr_inc_nn(&gb_cpu->SP);
gb_cpu->cycles += 8;
}

// INC (HL)
// 1  12
void INC_aHL(void){printf(" %s\n", __func__);
}

// DEC (HL)
// 1  12
void DEC_aHL(void) {
printf(" %s\n", __func__);
}

// LD (HL),d8
// 2  12
void LD_mHL_d8(void) {
printf(" %s\n", __func__);
}

// SCF
// 1  4
void SCF(void) {
printf(" %s\n", __func__);
}

// JR C,r8
// 2  12/8
void JR_C_r8(void) {
printf(" %s\n", __func__);
}

// ADD HL,SP
// 1  8
void ADD_HL_SP(void) {
printf(" %s\n", __func__);
}

// LD A,(HL-)
// 1  8
void LD_A_HLs(void) {
printf(" %s\n", __func__);
}

// DEC SP
// 1  8
void DEC_SP(void) {
printf(" %s\n", __func__);
}

// INC A
// 1  4
void INC_A(void) {
    instr_inc_n(gb_cpu->A);
    gb_cpu->cycles += 4;
    printf(" %s\n", __func__);
}

// DEC A
// 1  4
void DEC_A(void) {
printf(" %s\n", __func__);
instr_dec_n(gb_cpu->A);
}

// LD A,d8
// 2  8
void LD_A_d8(void) {
    uint8_t d8 = memory_read8(memory, gb_cpu->PC);
    gb_cpu->PC += 1;
    instr_load_ab(gb_cpu->A, d8);
    printf(" %s: A <- 0x%02X\n", __func__, d8);
}

// CCF
// 1  4
void CCF(void) {
printf(" %s\n", __func__);
}


// 0x4...
// LD B,B
// 1  4
void LD_B_B(void) { printf(" %s\n", __func__); }

// LD B,C
// 1  4
void LD_B_C(void) { printf(" %s\n", __func__); }

// LD B,D
// 1  4
void LD_B_D(void) { printf(" %s\n", __func__); }

// LD B,E
// 1  4
void LD_B_E(void) { printf(" %s\n", __func__); }

// LD B,H
// 1  4
void LD_B_H(void) { printf(" %s\n", __func__); }

// LD B,L
// 1  4
void LD_B_L(void) { printf(" %s\n", __func__); }

// LD B,(HL)
// 1  8
void LD_B_HLm(void) { printf(" %s\n", __func__); }

// LD B,A
// 1  4
void LD_B_A(void) { printf(" %s\n", __func__); }

// LD C,B
// 1  4
void LD_C_B(void) { printf(" %s\n", __func__); }

// LD C,C
// 1  4
void LD_C_C(void) { printf(" %s\n", __func__); }

// LD C,D
// 1  4
void LD_C_D(void) { printf(" %s\n", __func__); }

// LD C,E
// 1  4
void LD_C_E(void) { printf(" %s\n", __func__); }

// LD C,H
// 1  4
void LD_C_H(void) { printf(" %s\n", __func__); }

// LD C,L
// 1  4
void LD_C_L(void) { printf(" %s\n", __func__); }

// LD C,(HL)
// 1  8
void LD_C_HLm(void) { printf(" %s\n", __func__); }

// LD C,A
// 1  4
void LD_C_A(void) { printf(" %s\n", __func__); }

//0x5...
// LD D,B
// 1  4
void LD_D_B(void) { printf(" %s\n", __func__); }

// LD D,C
// 1  4
void LD_D_C(void) { printf(" %s\n", __func__); }

// LD D,D
// 1  4
void LD_D_D(void) { printf(" %s\n", __func__); }

// LD D,E
// 1  4
void LD_D_E(void) { printf(" %s\n", __func__); }

// LD D,H
// 1  4
void LD_D_H(void) { printf(" %s\n", __func__); }

// LD D,L
// 1  4
void LD_D_L(void) { printf(" %s\n", __func__); }

// LD D,(HL)
// 1  8
void LD_D_HLm(void) { printf(" %s\n", __func__); }

// LD D,A
// 1  4
void LD_D_A(void) { printf(" %s\n", __func__); }
// LD E,B
// 1  4
void LD_E_B(void) { printf(" %s\n", __func__); }
// LD E,C
// 1  4
void LD_E_C(void) { printf(" %s\n", __func__); }
// LD E,D
// 1  4
void LD_E_D(void) { printf(" %s\n", __func__); }
// LD E,E
// 1  4
void LD_E_E(void) { printf(" %s\n", __func__); }
// LD E,H
// 1  4
void LD_E_H(void) { printf(" %s\n", __func__); }
// LD E,L
// 1  4
void LD_E_L(void) { printf(" %s\n", __func__); }
// LD E,(HL)
// 1  8
void LD_E_HLm(void) { printf(" %s\n", __func__); }
// LD E,A
// 1  4
void LD_E_A(void) { printf(" %s\n", __func__); }

//0x6....
// LD H,B
// 1  4
void LD_H_B(void) { printf(" %s\n", __func__); }

// LD H,C
// 1  4
void LD_H_C(void) { printf(" %s\n", __func__); }
// LD H,D
// 1  4
void LD_H_D(void) { printf(" %s\n", __func__); }

// LD H,E
// 1  4
void LD_H_E(void) { printf(" %s\n", __func__); }
// LD H,H
// 1  4
void LD_H_H(void) { printf(" %s\n", __func__); }
// LD H,L
// 1  4
void LD_H_L(void) { printf(" %s\n", __func__); }
// LD H,(HL)
// 1  8
void LD_H_HLm(void) { printf(" %s\n", __func__); }
// LD H,A
// 1  4
void LD_H_A(void) { printf(" %s\n", __func__); }
// LD L,B
// 1  4
void LD_L_B(void) { printf(" %s\n", __func__); }
// LD L,C
// 1  4
void LD_L_C(void) { printf(" %s\n", __func__); }
// LD L,D
// 1  4
void LD_L_D(void) { printf(" %s\n", __func__); }
// LD L,E
// 1  4
void LD_L_E(void) { printf(" %s\n", __func__); }
// LD L,H
// 1  4
void LD_L_H(void) { printf(" %s\n", __func__); }
// LD L,L
// 1  4
void LD_L_L(void) { printf(" %s\n", __func__); }
// LD L,(HL)
// 1  8
void LD_L_HLm(void) { printf(" %s\n", __func__); }
// LD L,A
// 1  4
void LD_L_A(void) { printf(" %s\n", __func__); }

//0x7...
// LD (HL),B
// 1  8
void LD_HLm_B(void) { printf(" %s\n", __func__); }
// LD (HL),C
// 1  8
void LD_HLm_C(void) { printf(" %s\n", __func__); }
// LD (HL),D
// 1  8
void LD_HLm_D(void) { printf(" %s\n", __func__); }
// LD (HL),E
// 1  8
void LD_HLm_E(void) { printf(" %s\n", __func__); }
// LD (HL),H
// 1  8
void LD_HLm_H(void) { printf(" %s\n", __func__); }
// LD (HL),L
// 1  8
void LD_HLm_L(void) { printf(" %s\n", __func__); }
// HALT
// 1  4
void HALT(void) { printf(" %s\n", __func__); }
// LD (HL),A
// 1  8
void LD_HLm_A(void) { printf(" %s\n", __func__); }
// LD A,B
// 1  4
void LD_A_B(void) { printf(" %s\n", __func__); }
// LD A,C
// 1  4
void LD_A_C(void) { printf(" %s\n", __func__); }
// LD A,D
// 1  4
void LD_A_D(void) { printf(" %s\n", __func__); }
// LD A,E
// 1  4
void LD_A_E(void) { printf(" %s\n", __func__); }
// LD A,H
// 1  4
void LD_A_H(void) { printf(" %s\n", __func__); }
// LD A,L
// 1  4
void LD_A_L(void) { printf(" %s\n", __func__); }
// LD A,(HL)
// 1  8
void LD_A_HLm(void) { printf(" %s\n", __func__); }
// LD A,A
// 1  4
void LD_A_A(void) { printf(" %s\n", __func__); }

//0x8...
// ADD A,B
// 1  4
void ADD_A_B(void) { printf(" %s\n", __func__); }
// ADD A,C
// 1  4
void ADD_A_C(void) { printf(" %s\n", __func__); }
// ADD A,D
// 1  4
void ADD_A_D(void) { printf(" %s\n", __func__); }
// ADD A,E
// 1  4
void ADD_A_E(void) { printf(" %s\n", __func__); }
// ADD A,H
// 1  4
void ADD_A_H(void) { printf(" %s\n", __func__); }
// ADD A,L
// 1  4
void ADD_A_L(void) { printf(" %s\n", __func__); }
// ADD A,(HL)
// 1  8
void ADD_A_HLm(void) { printf(" %s\n", __func__); }
// ADD A,A
// 1  4
void ADD_A_A(void) { printf(" %s\n", __func__); }
// ADC A,B
// 1  4
void ADC_A_B(void) { printf(" %s\n", __func__); }
// ADC A,C
// 1  4
void ADC_A_C(void) { printf(" %s\n", __func__); }
// ADC A,D
// 1  4
void ADC_A_D(void) { printf(" %s\n", __func__); }
// ADC A,E
// 1  4
void ADC_A_E(void) { printf(" %s\n", __func__); }
// ADC A,H
// 1  4
void ADC_A_H(void) { printf(" %s\n", __func__); }
// ADC A,L
// 1  4
void ADC_A_L(void) { printf(" %s\n", __func__); }
// ADC A,(HL)
// 1  8
void ADC_A_HLm(void) { printf(" %s\n", __func__); }
// ADC A,A
// 1  4
void ADC_A_A(void) { printf(" %s\n", __func__); }

// 0x9..
// SUB B
// 1  4
void SUB_B(void) { printf(" %s\n", __func__); }
// SUB C
// 1  4
void SUB_C(void) { printf(" %s\n", __func__); }
// SUB D
// 1  4
void SUB_D(void) { printf(" %s\n", __func__); }
// SUB E
// 1  4
void SUB_E(void) { printf(" %s\n", __func__); }
// SUB H
// 1  4
void SUB_H(void) { printf(" %s\n", __func__); }
// SUB L
// 1  4
void SUB_L(void) { printf(" %s\n", __func__); }
// SUB (HL)
// 1  8
void SUB_HLm(void) { printf(" %s\n", __func__); }
// SUB A
// 1  4
void SUB_A(void) { printf(" %s\n", __func__); }
// SBC A,B
// 1  4
void SBC_A_B(void) { printf(" %s\n", __func__); }
// SBC A,C
// 1  4
void SBC_A_C(void) { printf(" %s\n", __func__); }
// SBC A,D
// 1  4
void SBC_A_D(void) { printf(" %s\n", __func__); }
// SBC A,E
// 1  4
void SBC_A_E(void) { printf(" %s\n", __func__); }
// SBC A,H
// 1  4
void SBC_A_H(void) { printf(" %s\n", __func__); }
// SBC A,L
// 1  4
void SBC_A_L(void) { printf(" %s\n", __func__); }
// SBC A,(HL)
// 1  8
void SBC_A_HLm(void) { printf(" %s\n", __func__); }
// SBC A,A
// 1  4
void SBC_A_A(void) { printf(" %s\n", __func__); }

//0xA..
// AND B
// 1  4
void AND_B(void) { printf(" %s\n", __func__); }
// AND C
// 1  4
void AND_C(void) { printf(" %s\n", __func__); }
// AND D
// 1  4
void AND_D(void) { printf(" %s\n", __func__); }
// AND E
// 1  4
void AND_E(void) { printf(" %s\n", __func__); }
// AND H
// 1  4
void AND_H(void) { printf(" %s\n", __func__); }
// AND L
// 1  4
void AND_L(void) { printf(" %s\n", __func__); }
// AND (HL)
// 1  8
void AND_HLm(void) { printf(" %s\n", __func__); }
// AND A
// 1  4
void AND_A(void) { printf(" %s\n", __func__); }
// XOR B
// 1  4
void XOR_B(void) { printf(" %s\n", __func__); }
// XOR C
// 1  4
void XOR_C(void) { printf(" %s\n", __func__); }
// XOR D
// 1  4
void XOR_D(void) { printf(" %s\n", __func__); }
// XOR E
// 1  4
void XOR_E(void) { printf(" %s\n", __func__); }
// XOR H
// 1  4
void XOR_H(void) { printf(" %s\n", __func__); }
// XOR L
// 1  4
void XOR_L(void) { printf(" %s\n", __func__); }
// XOR (HL)
// 1  8
void XOR_HLm(void) { printf(" %s\n", __func__); }
// XOR A
// 1  4
void XOR_A(void) { printf(" %s\n", __func__); }

//0xB...
// OR B
// 1  4
void OR_B(void) {
    instr_or(gb_cpu->A, *gb_cpu->B);
    printf(" %s\n", __func__);
}
// OR C
// 1  4
void OR_C(void) {
    instr_or(gb_cpu->A, *gb_cpu->C);
    printf(" %s\n", __func__); }
// OR D
// 1  4
void OR_D(void) { printf(" %s\n", __func__);
instr_or(gb_cpu->A, *gb_cpu->D);
 }
// OR E
// 1  4
void OR_E(void) { printf(" %s\n", __func__);
instr_or(gb_cpu->A, *gb_cpu->E);
}
// OR H
// 1  4
void OR_H(void) { printf(" %s\n", __func__);
instr_or(gb_cpu->A, *gb_cpu->H);
}
// OR L
// 1  4
void OR_L(void) { printf(" %s\n", __func__); instr_or(gb_cpu->A, *gb_cpu->L);}
// OR (HL)
// 1  8
void OR_HLm(void) { printf(" %s\n", __func__);
//TODO
}
// OR A
// 1  4
void OR_A(void) { printf(" %s\n", __func__); instr_or(gb_cpu->A, *gb_cpu->A);}
// CP B
// 1  4
void CP_B(void) { printf(" %s\n", __func__);
instr_cp(gb_cpu->A, *gb_cpu->B);}
// CP C
// 1  4
void CP_C(void) { printf(" %s\n", __func__);instr_cp(gb_cpu->A, *gb_cpu->C); }
// CP D
// 1  4
void CP_D(void) { printf(" %s\n", __func__); instr_cp(gb_cpu->A, *gb_cpu->D);}
// CP E
// 1  4
void CP_E(void) { printf(" %s\n", __func__); instr_cp(gb_cpu->A, *gb_cpu->E);}
// CP H
// 1  4
void CP_H(void) { printf(" %s\n", __func__); instr_cp(gb_cpu->A, *gb_cpu->H);}
// CP L
// 1  4
void CP_L(void) { printf(" %s\n", __func__); instr_cp(gb_cpu->A, *gb_cpu->L);}
// CP (HL)
// 1  8
void CP_HLm(void) { printf(" %s\n", __func__);
//TODO
}
// CP A
// 1  4
void CP_A(void) { printf(" %s\n", __func__);instr_cp(gb_cpu->A, *gb_cpu->A);}

//0xC...
// RET NZ
// 1  20/8
void RET_NZ(void) { printf(" %s\n", __func__); }
// POP BC
// 1  12
void POP_BC(void) { printf(" %s\n", __func__); gb_cpu->BC = CPU_stack_pop(); gb_cpu->cycles += 12;}
// JP NZ,a16
// 3  16/12
void JP_NZ_a16(void) { printf(" %s\n", __func__); }
// JP a16
// 3  16
void JP_a16(void) { printf(" %s\n", __func__); }
// CALL NZ,a16
// 3  24/12
void CALL_NZ_a16(void) { printf(" %s\n", __func__); }
// PUSH BC
// 1  16
void PUSH_BC(void) { printf(" %s\n", __func__); CPU_stack_push(gb_cpu->BC); gb_cpu->cycles += 16;}
// ADD A,d8
// 2  8
void ADD_A_d8(void) { printf(" %s\n", __func__); }
// RST 00H
// 1  16
void RST_00H(void) { printf(" %s\n", __func__); }
// RET Z
// 1  20/8
void RET_Z(void) { printf(" %s\n", __func__); }
// RET
// 1  16
void RET(void) { printf(" %s\n", __func__); }
// JP Z,a16
// 3  16/12
void JP_Z_a16(void) { printf(" %s\n", __func__); }
// PREFIX CB
// 1  4
void PREFIX_CB(void) {
  uint8_t op = memory_read8(memory, gb_cpu->PC);
  gb_cpu->PC += 1;
  printf(" %s::", __func__);
  prefix_cb[op]();

}
// CALL Z,a16
// 3  24/12
void CALL_Z_a16(void) { printf(" %s\n", __func__); }
// CALL a16
// 3  24
void CALL_a16(void) { printf(" %s\n", __func__); }
// ADC A,d8
// 2  8
void ADC_A_d8(void) { printf(" %s\n", __func__); }
// RST 08H
// 1  16
void RST_08H(void) { printf(" %s\n", __func__); gb_cpu->PC = 0x0008; gb_cpu->cycles += 16;}

// 0xD...
// RET NC
// 1  20/8
void RET_NC(void) { printf(" %s\n", __func__); }
// POP DE
// 1  12
void POP_DE(void) { printf(" %s\n", __func__); gb_cpu->DE = CPU_stack_pop(); gb_cpu->cycles += 12; }
// JP NC,a16
// 3  16/12
void JP_NC_a16(void) { printf(" %s\n", __func__); }
// CALL NC,a16
// 3  24/12
void CALL_NC_a16(void) { printf(" %s\n", __func__); }
// PUSH DE
// 1  16
void PUSH_DE(void) { printf(" %s\n", __func__); CPU_stack_push(gb_cpu->DE);gb_cpu->cycles += 16;}
// SUB d8
// 2  8
void SUB_d8(void) { printf(" %s\n", __func__); }
// RST 10H
// 1  16
void RST_10H(void) { printf(" %s\n", __func__); gb_cpu->PC = 0x0010; gb_cpu->cycles += 16;}
// RET C
// 1  20/8
void RET_C(void) { printf(" %s\n", __func__); }
// RETI
// 1  16
void RETI(void) { printf(" %s\n", __func__); }
// JP C,a16
// 3  16/12
void JP_C_a16(void) { printf(" %s\n", __func__); }
// CALL C,a16
// 3  24/12
void CALL_C_a16(void) { printf(" %s\n", __func__); }
// SBC A,d8
// 2  8
void SBC_A_d8(void) { printf(" %s\n", __func__); }
// RST 18H
// 1  16
void RST_18H(void) { printf(" %s\n", __func__); gb_cpu->PC = 0x0018; gb_cpu->cycles += 16;}

// 0xE..
// LDH (a8),A
// 2  12
void LDH_a8_A(void) { printf(" %s\n", __func__); }
// POP HL
// 1  12
void POP_HL(void) { printf(" %s\n", __func__);gb_cpu->HL = CPU_stack_pop(); gb_cpu->cycles += 12;}
// LD (C),A
// 2  8
void LD_Cm_A(void) {
    uint16_t addr = *gb_cpu->C + 0xFF00;
    memory_write8(memory, addr, *gb_cpu->A);
    printf(" %s: 0x%04X <- 0x%02X\n", __func__, addr, *gb_cpu->A);
    gb_cpu->PC += 2;
}
// PUSH HL
// 1  16
void PUSH_HL(void) { printf(" %s\n", __func__); CPU_stack_push(gb_cpu->HL); gb_cpu->cycles += 16;}
// AND d8
// 2  8
void AND_d8(void) { printf(" %s\n", __func__); }
// RST 20H
// 1  16
void RST_20H(void) { printf(" %s\n", __func__);gb_cpu->PC = 0x0020; gb_cpu->cycles += 16; }
// ADD SP,r8
// 2  16
void ADD_SP_r8(void) { printf(" %s\n", __func__); }
// JP (HL)
// 1  4
void JP_HLm(void) { printf(" %s\n", __func__); }
// LD (a16),A
// 3  16
void LD_a16_A(void) { printf(" %s\n", __func__); }
// XOR d8
// 2  8
void XOR_d8(void) { printf(" %s\n", __func__); }
// RST 28H
// 1  16
void RST_28H(void) { printf(" %s\n", __func__); gb_cpu->PC = 0x0028; gb_cpu->cycles += 16;}

//0xF....
// LDH A,(a8)
// 2  12
void LDH_A_a8(void) { printf(" %s\n", __func__); }
// POP AF
// 1  12
void POP_AF(void) { printf(" %s\n", __func__); gb_cpu->DE = CPU_stack_pop(); gb_cpu->cycles += 12;}
// LD A,(C)
// 2  8
void LD_A_Cm(void) {
    uint16_t addr = 0xFF00 + *gb_cpu->C;
    uint8_t val = memory_read8(memory, addr);
    printf(" %s: 0x%04X - 0x%02X\n", __func__,addr, val);
}
// DI
// 1  4
void DI(void) { printf(" %s\n", __func__); instr_di(); }
// PUSH AF
// 1  16
void PUSH_AF(void) { printf(" %s\n", __func__); CPU_stack_push(gb_cpu->AF); gb_cpu->cycles += 16;}
// OR d8
// 2  8
void OR_d8(void) { printf(" %s\n", __func__); }
// RST 30H
// 1  16
void RST_30H(void) { printf(" %s\n", __func__); gb_cpu->PC = 0x0030; gb_cpu->cycles += 16;}
// LD HL,SP+r8
// 2  12
void LD_HL_SPr8(void) { printf(" %s\n", __func__); }
// LD SP,HL
// 1  8
void LD_SP_HL(void) { printf(" %s\n", __func__); }
// LD A,(a16)
// 3  16
void LD_A_a16(void) { printf(" %s\n", __func__); }
// EI
// 1  4
void EI(void) { printf(" %s\n", __func__); instr_ei(); gb_cpu->cycles += 4;}
// CP d8
// 2  8
void CP_d8(void) { printf(" %s\n", __func__); }
// RST 38H
// 1  16
void RST_38H(void) { printf(" %s\n", __func__); gb_cpu->PC = 0x0038; gb_cpu->cycles += 16;}


void no_op(void) { printf(" Unimplemented func!\n");  }


void(*op_codes[256])(void) = {
    //0x0...
    NOP,
    LD_BC_d16,
    LD_mBC_A,
    INC_BC,
    INC_B,
    DEC_B,
    LD_B_d8,
    RLCA,
    LD_a16_SP,
    ADD_HL_BC,
    LD_A_BC,
    DEC_BC,
    INC_C,
    DEC_C,
    LD_C_d8,
    RRCA,

    //0x1..
    STOP,
    LD_DE_d16,
    LD_DE_A,
    INC_DE,
    INC_D,
    DEC_D,
    LD_D_d8,
    RLA,
    JR_r8,
    ADD_HL_DE,
    LD_A_DE,
    DEC_DE,
    INC_E,
    DEC_E,
    LD_E_d8,
    RRA,

    //0x2..
    JR_NZ_r8,
    LD_HL_d16,
    LD_HLp_A,
    INC_HL,
    INC_H,
    DEC_H,
    LD_H_d8,
    DAA,
    JR_Z_r8,
    ADD_HL_HL,
    LD_A_HLp,
    DEC_HL,
    INC_L,
    DEC_L,
    LD_L_d8,
    CPL,

    //0x3..
    JR_NC_r8,
    LD_SP_d16,
    LD_HLs_A,
    INC_SP,
    INC_aHL,
    DEC_aHL,
    LD_mHL_d8,
    SCF,
    JR_C_r8,
    ADD_HL_SP,
    LD_A_HLs,
    DEC_SP,
    INC_A,
    DEC_A,
    LD_A_d8,
    CCF,

    //0x4..
    LD_B_B,
    LD_B_C,
    LD_B_D,
    LD_B_E,
    LD_B_H,
    LD_B_L,
    LD_B_HLm,
    LD_B_A,
    LD_C_B,
    LD_C_C,
    LD_C_D,
    LD_C_E,
    LD_C_H,
    LD_C_L,
    LD_C_HLm,
    LD_C_A,

    //0x5..
    LD_D_B,
    LD_D_C,
    LD_D_D,
    LD_D_E,
    LD_D_H,
    LD_D_L,
    LD_D_HLm,
    LD_D_A,
    LD_E_B,
    LD_E_C,
    LD_E_D,
    LD_E_E,
    LD_E_H,
    LD_E_L,
    LD_E_HLm,
    LD_E_A,

    //0x6..
    LD_H_B,
    LD_H_C,
    LD_H_D,
    LD_H_E,
    LD_H_H,
    LD_H_L,
    LD_H_HLm,
    LD_H_A,
    LD_L_B,
    LD_L_C,
    LD_L_D,
    LD_L_E,
    LD_L_H,
    LD_L_L,
    LD_L_HLm,
    LD_L_A,

    //0x7..
    LD_HLm_B,
    LD_HLm_C,
    LD_HLm_D,
    LD_HLm_E,
    LD_HLm_H,
    LD_HLm_L,
    HALT,
    LD_HLm_A,
    LD_A_B,
    LD_A_C,
    LD_A_D,
    LD_A_E,
    LD_A_H,
    LD_A_L,
    LD_A_HLm,
    LD_A_A,

    //0x8..
    ADD_A_B,
    ADD_A_C,
    ADD_A_D,
    ADD_A_E,
    ADD_A_H,
    ADD_A_L,
    ADD_A_HLm,
    ADD_A_A,
    ADC_A_B,
    ADC_A_C,
    ADC_A_D,
    ADC_A_E,
    ADC_A_H,
    ADC_A_L,
    ADC_A_HLm,
    ADC_A_A,

    //0x9..
    SUB_B,
    SUB_C,
    SUB_D,
    SUB_E,
    SUB_H,
    SUB_L,
    SUB_HLm,
    SUB_A,
    SBC_A_B,
    SBC_A_C,
    SBC_A_D,
    SBC_A_E,
    SBC_A_H,
    SBC_A_L,
    SBC_A_HLm,
    SBC_A_A,

    //0xA..
    AND_B,
    AND_C,
    AND_D,
    AND_E,
    AND_H,
    AND_L,
    AND_HLm,
    AND_A,
    XOR_B,
    XOR_C,
    XOR_D,
    XOR_E,
    XOR_H,
    XOR_L,
    XOR_HLm,
    XOR_A,

    //0xB..
    OR_B,
    OR_C,
    OR_D,
    OR_E,
    OR_H,
    OR_L,
    OR_HLm,
    OR_A,
    CP_B,
    CP_C,
    CP_D,
    CP_E,
    CP_H,
    CP_L,
    CP_HLm,
    CP_A,

    //0xC..
    RET_NZ,
    POP_BC,
    JP_NZ_a16,
    JP_a16,
    CALL_NZ_a16,
    PUSH_BC,
    ADD_A_d8,
    RST_00H,
    RET_Z,
    RET,
    JP_Z_a16,
    PREFIX_CB,
    CALL_Z_a16,
    CALL_a16,
    ADC_A_d8,
    RST_08H,

    //0xD..
    RET_NC,
    POP_DE,
    JP_NC_a16,
    no_op,
    CALL_NC_a16,
    PUSH_DE,
    SUB_d8,
    RST_10H,
    RET_C,
    RETI,
    JP_C_a16,
    no_op,
    CALL_C_a16,
    no_op,
    SBC_A_d8,
    RST_18H,

    //0xE..
    LDH_a8_A,
    POP_HL,
    LD_Cm_A,
    no_op,
    no_op,
    PUSH_HL,
    AND_d8,
    RST_20H,
    ADD_SP_r8,
    JP_HLm,
    LD_a16_A,
    no_op,
    no_op,
    no_op,
    XOR_d8,
    RST_28H,

    //0xF..
    LDH_A_a8,
    POP_AF,
    LD_A_Cm,
    DI,
    no_op,
    PUSH_AF,
    OR_d8,
    RST_30H,
    LD_HL_SPr8,
    LD_SP_HL,
    LD_A_a16,
    EI,
    no_op,
    no_op,
    CP_d8,
    RST_38H
};
