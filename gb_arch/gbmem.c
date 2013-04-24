/*
 * gbmem.c
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 *      
 *      GameBoy memory map
 */

#include "gbmem.h"

uint16_t selected_rom_bank, selected_ram_bank;
extern Byte *upper_addrs = NULL;
extern Byte *ram_addrs = NULL;

void gb_mem_init(void) {
	
	uint32_t ramsize;
	ramsize = gb_game_ramsize();
	selected_rom_bank = 1;
	selected_ram_bank = 0;
	
	if(!upper_addrs) {
		upper_addrs = (Byte*) malloc(sizeof(Byte) * SIZE_MEM_UPPER);
		printf("Upper size is %i bytes. ", SIZE_MEM_UPPER);
	}
	
	if(!ram_addrs) {
		ram_addrs = (Byte*) malloc(sizeof(Byte) * ramsize);
		printf("RAM size is %i bytes\n", ramsize);
	}
	
	memset(upper_addrs, 0, sizeof(Byte) * SIZE_MEM_UPPER);
	memset(ram_addrs, 0, sizeof(Byte) * ramsize);
	
	gb_mem_write(IO_ADDR_TIMA, 0x00);
	gb_mem_write(IO_ADDR_TMA, 0x00);
	gb_mem_write(IO_ADDR_TAC, 0x00);
	gb_mem_write(IO_ADDR_NR10, 0x80);
	gb_mem_write(IO_ADDR_NR11, 0xBF);
	gb_mem_write(IO_ADDR_NR12, 0xF3);
	gb_mem_write(IO_ADDR_NR14, 0xBF);
	gb_mem_write(IO_ADDR_NR21, 0x3F);
	gb_mem_write(IO_ADDR_NR22, 0x00);
	gb_mem_write(IO_ADDR_NR24, 0xBF);
	gb_mem_write(IO_ADDR_NR30, 0x7F);
	gb_mem_write(IO_ADDR_NR31, 0xFF);
	gb_mem_write(IO_ADDR_NR32, 0x9F);
	gb_mem_write(IO_ADDR_NR33, 0xBF);
	gb_mem_write(IO_ADDR_NR41, 0xFF);
	gb_mem_write(IO_ADDR_NR42, 0x00);
	gb_mem_write(IO_ADDR_NR43, 0x00);
	gb_mem_write(IO_ADDR_NR30, 0xBF);
	gb_mem_write(IO_ADDR_NR50, 0x77);
	gb_mem_write(IO_ADDR_NR51, 0xF3);
	gb_mem_write(IO_ADDR_NR52, 0xF1);
	gb_mem_write(IO_ADDR_LCDC, 0x91);
	gb_mem_write(IO_ADDR_SCY, 0x00);
	gb_mem_write(IO_ADDR_SCX, 0x00);
	gb_mem_write(IO_ADDR_LYC, 0x00);
	gb_mem_write(IO_ADDR_BGP, 0xFC);
	gb_mem_write(IO_ADDR_OBP0, 0xFF);
	gb_mem_write(IO_ADDR_OBP1, 0xFF);
	gb_mem_write(IO_ADDR_WY, 0x00);
	gb_mem_write(IO_ADDR_WX, 0x00);
	gb_mem_write(IO_ADDR_IE, 0x00);
	
	printf("Memory initialized...\n");
	
}

Byte gb_mem_read(Address addr) {
	
	Byte value = 0x00;
	//printf("Reading from %x...\n", addr);
	
	if(addr < TOP_CART) {
		value = gb_read_rom(addr);
		
	} else if(addr < TOP_VRAM) {
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

void gb_mem_write(Address addr, Byte value) {
	
	//printf("Writing %x to %x\n", value, addr);
	printf("RAM! ");
	
	if(addr < TOP_CART) {
		gb_write_rom(addr, value);
		
	} else if(addr < TOP_VRAM) {
		upper_addrs[addr - OFFSET_ADDR_UPPER] = value;
		
	} else if(addr < TOP_SWRAM) {
		gb_write_swram(addr, value);
		
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

Word gb_mem_wread(Address addr) {
	
	return gb_mem_read(addr) | (gb_mem_read(addr + 1) << 8);
	
}

void gb_mem_wwrite(Address addr, Word value) {
	
	gb_mem_write(addr, value & 0xFF);
	gb_mem_write(addr + 1, (value >> 8) & 0xFF);
	
}

void gb_write_rom(Address addr, Byte value) {
	
	if(addr < INROM_DENI) {
		// SCREW YOURSELF
	} else if(addr < INROM_ROM_SELLOW) {
		selected_rom_bank = (selected_rom_bank & (~0xFF)) | value;
		printf("ROMBANK set to %i\n", selected_rom_bank);
		//if(selected_rom_bank == 0)
			//selected_rom_bank = 1;
		
	} else if(addr < INROM_ROM_SELHI) {
		selected_rom_bank = (selected_rom_bank && 0xFF) | ((value & 0x01) << 8);
		printf("RAMBANK set to %i\n", selected_ram_bank);
		//if(selected_rom_bank == 0)
			//selected_rom_bank = 1;
		
	} else if(addr < INROM_RAM_SEL) {
		selected_ram_bank = value & 0x0F;
		
	} else {
		printf("RomWrite: Well shit, that's not a valid ROM cart address.\n");
		
	}
	
}

Byte gb_read_rom(Address addr) {

	return gb_game_addr(addr);
	
}

Byte gb_read_swrom(Address addr) {
	
	return gm_game_addr(addr + (SIZE_ROM * selected_rom_bank));
	
}

void gb_write_swram(Address addr, Byte value) {
	
	ram_addrs[addr + (SIZE_SWRAM * selected_ram_bank)] = value;
	
}

Byte gb_read_swram(Address addr) {
	
	return ram_addrs[addr + (SIZE_SWRAM * selected_ram_bank)];
	
}