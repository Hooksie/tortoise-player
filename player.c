/*
 * player.c
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 */

#include "player.h"

void Player_Start(void) {
	
	gb_mem_init();
	
	
	while(1) {
		
		gb_cpu_execute_cycles(40);
		
	}
	
}