/*
 * gbtypes.h
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 */

#ifndef GBTYPES_H_
#define GBTYPES_H_

#include <stdint.h>

#ifndef NULL
#define NULL 0
#endif

typedef uint8_t	Byte;
typedef uint16_t Word;
typedef uint16_t Address;

typedef int8_t SByte;
typedef int16_t SWord;

typedef uint16_t BasicRegister;
typedef uint8_t Flag;

// SWEET JESUS THE FOLLOWING ACTUALLY WORKS!
// HOW DID I GET HERE I AM NOT GOOD WITH C
typedef union SplitRegister {
	Word full;
	struct {
		Byte low, high;
	} split;
} SplitRegister;


typedef enum { FREQ_NORMAL, FREQ_DOUBLE } FrequencyMode;
typedef enum { ROM_ONLY, MBC1, MBC2, MBC3, MC5, RUMBLE, HuC1 } CartType;
typedef enum { CONSOLE_GBC } ConsoleTypes;
typedef enum { MODE_GBC_ENABLED } ConsoleModes;

// Hold the internal state of the CPU
typedef struct CpuState {
	SplitRegister reg_af, reg_bc, reg_de, reg_hl;
	BasicRegister reg_sp, reg_pc;
	Flag flag_Z, flag_N, flag_H, flag_C, halted, stopped;
	int ei, ime;
	FrequencyMode frequency;
} CpuState;


#endif /* GBTYPES_H_ */
