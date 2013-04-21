/*
 * gbmem.c
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 *      
 *      GameBoy memory map
 */

#include "gbmem.h"

extern Byte *upper_addrs = NULL;
extern Byte *io_addrs = NULL;

void gb_mem_init(void) {
	
	if(!upper_addrs)
		upper_addrs = (Byte*) malloc(sizeof(Byte) * SIZE_MEM_UPPER);
	
	if(!io_addrs)
		io_addrs = (Byte*) malloc(sizeof(Byte) * SIZE_MEM_IO);
	
	memset(upper_addrs, 0, SIZE_MEM_UPPER);
	
	gb_write_addr(IO_ADDR_TIMA, 0x00);
	gb_write_addr(IO_ADDR_TMA, 0x00);
	gb_write_addr(IO_ADDR_TAC, 0x00);
	gb_write_addr(IO_ADDR_NR10, 0x80);
	gb_write_addr(IO_ADDR_NR11, 0xBF);
	gb_write_addr(IO_ADDR_NR12, 0xF3);
	gb_write_addr(IO_ADDR_NR14, 0xBF);
	gb_write_addr(IO_ADDR_NR21, 0x3F);
	gb_write_addr(IO_ADDR_NR22, 0x00);
	gb_write_addr(IO_ADDR_NR24, 0xBF);
	gb_write_addr(IO_ADDR_NR30, 0x7F);
	gb_write_addr(IO_ADDR_NR31, 0xFF);
	gb_write_addr(IO_ADDR_NR32, 0x9F);
	gb_write_addr(IO_ADDR_NR33, 0xBF);
	gb_write_addr(IO_ADDR_NR41, 0xFF);
	gb_write_addr(IO_ADDR_NR42, 0x00);
	gb_write_addr(IO_ADDR_NR43, 0x00);
	gb_write_addr(IO_ADDR_NR30, 0xBF);
	gb_write_addr(IO_ADDR_NR50, 0x77);
	gb_write_addr(IO_ADDR_NR51, 0xF3);
	gb_write_addr(IO_ADDR_NR52, 0xF1);
	gb_write_addr(IO_ADDR_LCDC, 0x91);
	gb_write_addr(IO_ADDR_SCY, 0x00);
	gb_write_addr(IO_ADDR_SCX, 0x00);
	gb_write_addr(IO_ADDR_LYC, 0x00);
	gb_write_addr(IO_ADDR_BGP, 0xFC);
	gb_write_addr(IO_ADDR_OBP0, 0xFF);
	gb_write_addr(IO_ADDR_OBP1, 0xFF);
	gb_write_addr(IO_ADDR_WY, 0x00);
	gb_write_addr(IO_ADDR_WX, 0x00);
	gb_write_addr(IO_ADDR_IE, 0x00);
	
}

Byte read_gb_addr(Address addr) {
	
	Byte value = 0x00;
	
	if(addr < TOP_CART) {
		value = gb_read_rom(addr);
		
	} else if(addr < TOP_VRAM) {
		//value = gb_read_vram(addr);
		value = upper_addrs[addr - OFFSET_ADDR_UPPER];
		
	} else if(addr < TOP_SWRAM) {
		value = gb_read_swram(addr);
		
	} else if(addr <= TOP_HIRAM ) {
		value = upper_addrs[addr - OFFSET_ADDR_UPPER];
		
	} else {
		// HOLY SHIT, someone fucked up
	} 
	
	return value;
	
}

void gb_write_addr(Address addr, Byte value) {
	
	if(addr < TOP_CART) {
		value = gb_write_rom(addr, value);
		
	} else if(addr < TOP_VRAM) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr < TOP_SWRAM) {
		value = gb_read_swram(addr);
		
	} else if(addr < TOP_IRAM) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr < TOP_ECHO) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr < TOP_SPRITE) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr < TOP_SBANK1) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr < TOP_IOPORTS) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr < TOP_SBANK2) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr < TOP_HIRAM) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr == TOP_HIRAM ) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else {
		// HOLY SHIT, someone fucked up
	} 
	
}

Byte gb_read_rom(Address addr) {
	
	Byte value;
	return value;
	
}

Byte gb_read_swram(Address addr) {
	
	Byte value;
	return value;
	
}