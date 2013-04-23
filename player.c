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
	
//	printf("Check this shit -> %x\n", gb_game_addr(0x00));
//	printf("Check this shit -> %x\n", gb_game_addr(0x02));
//	printf("Check this shit -> %x\n", gb_game_addr(0x01));
	
	printf("Check this shit -> %x\n", gb_mem_read(0x00));
	printf("Check this shit -> %x\n", gb_mem_read(0x01));
	printf("Check this shit -> %x\n", gb_mem_read(0x02));
	printf("Check this shit -> %x\n", gb_mem_read(0x03));
	printf("Check this shit -> %x\n", gb_mem_read(0x04));
	printf("Check this shit -> %x\n", gb_mem_read(0x05));
	printf("Check this shit -> %x\n", gb_mem_read(0x06));
	
	//gb_cpu_execute_cycles(40);
	
	while(1) {
		
		gb_cpu_execute_cycles(40);
//		_time_delay(1000);
		//printf("wait for it...\n");
		getchar();
		printf("Cycles executed... fuck\n");
	}
	
	return 0;
	
}