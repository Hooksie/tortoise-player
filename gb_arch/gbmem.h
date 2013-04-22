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
#include "../gamefile.h"

void gb_mem_init(void);
Byte gb_mem_read(Address addr);
void gb_mem_write(Address addr, Byte value);

static Byte gb_read_rom(Address addr);
static Byte gb_read_io(Address addr);
static void gb_write_io(Address addr, Byte value);
static Byte gb_read_vram(Address addr);
static void gb_write_vram(Address addr, Byte value);
static Byte gb_read_swram(Address addr);

#define SIZE_ROM				0x4000
#define SIZE_SWROM				0x4000
#define SIZE_VRAM				0x2000
#define SIZE_SWRAM				0x2000
#define SIZE_IRAM				0x2000
#define SIZE_ECHO				0x1E00
#define SIZE_SPRITES			0x00A0
#define SIZE_SBANK1				0x0060
#define SIZE_IOPORTS			0x004C
#define SIZE_SBANK2				0x0034
#define SIZE_HIRAM				0x0080

#define TOP_CART				0x8000
#define TOP_VRAM				0xA000
#define TOP_SWRAM				0xC000
#define TOP_IRAM				0XE000
#define TOP_ECHO				0xFE00
#define TOP_SPRITE 				0xFEA0
#define TOP_SBANK1				0xFF00
#define TOP_IOPORTS				0xFF4C
#define TOP_SBANK2				0xFF80
#define TOP_HIRAM				0xFFFF

#define SIZE_MEM_UPPER 			0x8000
#define SIZE_MEM_IO 			0x0100

#define OFFSET_ADDR_IO			0xFF00
#define OFFSET_ADDR_UPPER		0x8000

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

