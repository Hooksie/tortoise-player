/*
 * gamefile.h
 *
 *  Created on: Apr 21, 2013
 *      Author: k120
 */

#ifndef GAMEFILE_H_
#define GAMEFILE_H_

#include <mfs.h>
#include <stdlib.h>
#include "gbtypes.h"
#include "gbmem.h"


void gb_game_load(char path[]);
void gb_game_unload(void);
void gb_game_init(void);
Byte gb_game_addr(Address addr);
void gb_game_anal(void);
void gb_game_findname(void);
void gb_game_docartyping(void);
void gb_game_doromsizing(void);
void gb_game_doramsizing(void);
uint32_t gb_game_ramsize();

#endif /* GAMEFILE_H_ */
