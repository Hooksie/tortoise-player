/*
 * gbmem.h
 *
 *  Created on: Apr 20, 2013
 *      Author: Team Motivation
 *      
 *      GameBoy memory map
 */

#ifndef GBMEM_H_
#define GBMEM_H_

#include "gbtypes.h"

void gbmem_init(void);
Byte read_gb_addre(Address addr);

#define SIZE_MEM_UPPER 			0x8000
#define SIZE_MEM_IO 			0x0100

#define IO_ADDR_P1				0xFF00
#define IO_ADDR_SB				0xFF01
#define IO_ADDR_SC				0xFF02
#define IO_ADDR_DIV				0xFF04
#define IO_ADDR_TIMA			0xFF05
#define IO_ADDR_TMA				0xFF06
#define IO_ADDR_TAC				0xFF07
#define IO_ADDR_IF				0xFF0F
#define IO_ADDR_NR10			0xFF10
#define IO_ADDR_NR11			0xFF11
#define IO_ADDR_NR12			0xFF12
#define IO_ADDR_NR13			0xFF13
#define IO_ADDR_NR14			0xFF14
#define IO_ADDR_NR20			0xFF15
#define IO_ADDR_NR21			0xFF16
#define IO_ADDR_NR22			0xFF17
#define IO_ADDR_NR23			0xFF18
#define IO_ADDR_NR24			0xFF19
#define IO_ADDR_NR30			0xFF1A
#define IO_ADDR_NR31			0xFF1B
#define IO_ADDR_NR32			0xFF1C
#define IO_ADDR_NR33			0xFF1D
#define IO_ADDR_NR34			0xFF1E
#define IO_ADDR_NR40			0xFF1F
#define IO_ADDR_NR41			0xFF20
#define IO_ADDR_NR42			0xFF21
#define IO_ADDR_NR43			0xFF22
#define IO_ADDR_NR44			0xFF23
#define IO_ADDR_NR50			0xFF24
#define IO_ADDR_NR51			0xFF25
#define IO_ADDR_NR52			0xFF26
#define IO_ADDR_LCDC			0xFF40
#define IO_ADDR_STAT			0xFF41
#define IO_ADDR_SCY				0xFF42
#define IO_ADDR_SCX				0xFF43
#define IO_ADDR_LY				0xFF44
#define IO_ADDR_LYC				0xFF45
#define IO_ADDR_DMA				0xFF46
#define IO_ADDR_BGP				0xFF47
#define IO_ADDR_OBP0			0xFF48
#define IO_ADDR_OBP1			0xFF49
#define IO_ADDR_WY				0xFF4A
#define IO_ADDR_WX				0xFF4B
#define IO_ADDR_KEY1			0xFF4D
#define IO_ADDR_VBK				0xFF4F
#define IO_ADDR_HDMA1			0xFF51
#define IO_ADDR_HDMA2			0xFF52
#define IO_ADDR_HDMA3			0xFF53
#define IO_ADDR_HDMA4			0xFF54
#define IO_ADDR_HDMA5			0xFF55
#define IO_ADDR_RP				0xFF56
#define IO_ADDR_BGPI			0xFF68
#define IO_ADDR_BGPD			0xFF69
#define IO_ADDR_OBPI			0xFF6A
#define IO_ADDR_OBPD			0xFF6B
#define IO_ADDR_SVBK			0xFF70
#define IO_ADDR_IE				0xFFFF

#endif /* GBMEM_H_ */

