/*
 * gamefile.c
 *
 *  Created on: Apr 21, 2013
 *      Author: k120
 */

#include "gamefile.h"

FILE_PTR game_ptr;
Byte cart_type;
Byte game_title[16];
int rom_size, ram_size, rom_banks, ram_banks;

void gb_game_load(char path[]) {
	
	printf("Loading up gamefile...");
	
	game_ptr = fopen(path, "r");
	if(game_ptr == NULL)
		printf("Failed to open game.");
	else
		printf(".......Done!");
	
}

void gb_game_unload() {
	
	fclose(game_ptr);
	
}

void gb_game_init() {
	
	gb_game_anal();
	gb_game_findname();
	gb_game_doromsizing();
	gb_game_doramsizing();
	
	printf("Game initialized...\n");
	
}

Byte gb_game_addr(Address addr) {
	
	char cart_data[1];
	size_t fuckit;
		
	fuckit = fseek(game_ptr, (long) addr, IO_SEEK_SET);
	fuckit = read(game_ptr, cart_data, sizeof(cart_data));
	
	return (Byte) cart_data[0];
	
}

void gb_game_anal() {
	
	cart_type = gb_game_addr(0x0147);
	
}

void gb_game_findname() {

	Address title_addr;
	int i;
	
	title_addr = INDIC_TITLE;
	
	for(i = 0; i < 16; i++) {
		game_title[i] = gb_game_addr(title_addr);;
		title_addr++;
	}
	
	printf("Game title is %s\n", (char*) game_title);
	
}

void gb_game_docartyping() {
	
	// I know what zelda is.  Leave me alone.
	
}

void gb_game_doromsizing() {
	
	switch(gb_game_addr(INDIC_ROM)) {
	
		case 0x05:
			rom_size = 1024 * 1024;
			rom_banks = 64;
			break;
			
		default:
			printf("Unsupported ROM!  Fuck off!");
			break;
	
	}
	
}

void gb_game_doramsizing() {
	
	switch(gb_game_addr(INDIC_RAM)) {
	
		case 0x02:
			ram_size = 2 * 1024;
			ram_banks = 1;
			break;
			
		default:
			printf("Unsupported RAM!  Fuck off!");
			break;
	
	}
	
}

uint32_t gb_game_ramsize() {
	
	return ram_size;
	
}