/*
 * gamefile.c
 *
 *  Created on: Apr 21, 2013
 *      Author: k120
 */

#include "gamefile.h"
#include <stdlib.h>

FILE_PTR game_ptr;

void gb_game_load(char path[]) {
	
	game_ptr = fopen(path, "r");
	if(game_ptr == NULL)
		printf("Failed to open game.");
	
}

void gb_game_unload() {
	
	fclose(game_ptr);
	
}

Byte gb_game_addr(Address addr) {
	
	char cart_data[1];
	size_t fuckit;
		
	fuckit = fseek(game_ptr, (long) addr, IO_SEEK_SET);
	fuckit = read(game_ptr, cart_data, sizeof(cart_data));
	
	return (Byte) cart_data[0];
	
}