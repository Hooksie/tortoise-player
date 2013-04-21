/*
 * gbcpu.h
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 */

#ifndef GBCPU_H_
#define GBCPU_H_

#include "gbtypes.h"

void gb_cpu_execute_cycles(int max_cycles);
void gb_cpu_init(void);

static void interupt_check(void);
static void call_opcode(int *cycles_ptr);

#endif /* GBCPU_H_ */
