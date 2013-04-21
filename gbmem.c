/*
 * gbmem.c
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 *      
 *      GameBoy memory map
 */

#include "gbmem.h"

Byte *upper_addrs = NULL;
Byte *io_addrs = NULL;

void gbmem_init(void) {
	
	if(!upper_addrs)
		upper_addrs = (Byte*) malloc(sizeof(Byte) * SIZE_MEM_UPPER);
	
	if(!io_addrs)
		io_addrs = (Byte*) malloc(sizeof(Byte) * SIZE_MEM_IO);
	
	memset(upper_addrs, 0, SIZE_MEM_UPPER);
	
}

Byte read_gb_addr(Address addr) {
	
	// TODO Make this terribly important thing work
	
	Byte herpderp = 0x00;
	return herpderp;
	
}