/*
 * gamefile.h
 *
 *  Created on: Apr 21, 2013
 *      Author: k120
 */

#ifndef GAMEFILE_H_
#define GAMEFILE_H_

#include <mfs.h>
#include "gbtypes.h"

void gb_game_load(char path[]);
void gb_game_unload(void);
Byte gb_game_addr(Address addr);

#endif /* GAMEFILE_H_ */
