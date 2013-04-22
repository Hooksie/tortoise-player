/*
 * player.c
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 */

#include "player.h"

extern int_32 Player_Start(int_32 argc, char_ptr argv[] ) {
	
	gb_game_load(argv[1]);
	gb_mem_init();
	gb_cpu_init();
	
//	printf("Check this shit -> %x\n", gb_game_addr(0x00));
//	printf("Check this shit -> %x\n", gb_game_addr(0x02));
//	printf("Check this shit -> %x\n", gb_game_addr(0x01));
	
	
	while(1) {
		
		gb_cpu_execute_cycles(40);
		
	}
	
	return 0;
	
}