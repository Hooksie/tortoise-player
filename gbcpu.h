/*
 * gbcpu.h
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 */

#ifndef GBCPU_H_
#define GBCPU_H_

#include "gbtypes.h"

void cpu_execute_cycles(int max_cycles);
void init_cpu(void);
void interupt_check(void);
void call_opcode(uint8_t opcode, int *cycles_ptr);

#endif /* GBCPU_H_ */
