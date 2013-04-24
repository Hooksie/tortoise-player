/*
 * player.c
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 */

#include "player.h"

extern int_32 Player_Start(int_32 argc, char_ptr argv[] ) {
	
	gb_game_load(argv[1]);
	gb_cpu_init();
	gb_game_init();
	gb_mem_init();
	
	printf("Game file begins -> %x %x %x %x %x %x %x \n", 
			gb_mem_read(0x00), gb_mem_read(0x01), gb_mem_read(0x02), gb_mem_read(0x03),
			gb_mem_read(0x04), gb_mem_read(0x05), gb_mem_read(0x06));
	
	//gb_cpu_execute_cycles(40);
	
	while(1) {
		
		gb_cpu_execute_cycles(40);
//		_time_delay(1000);
		//printf("wait for it...\n");
		getchar();
		printf("Cycle executed...\n");
	}
	
	return 0;
	
}