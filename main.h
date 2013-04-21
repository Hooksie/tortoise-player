#ifndef __main_h_
#define __main_h_
#include <mqx.h>
#include <bsp.h>
#include <mfs.h>
#include <sh_mfs.h>
#include <shell.h>
#include "gbtypes.h"

#define APPLICATION_HAS_SHELL
#define MAIN_TASK   1
#define RAM_DISK_SIZE 0x2000
/* Uncomment following code to use whole external MRAM for ramdisk, if available.
Not applicable when using MRAM target! */
/*
#define RAM_DISK_BASE BSP_EXTERNAL_MRAM_BASE
#define RAM_DISK_SIZE BSP_EXTERNAL_MRAM_SIZE
*/

 
#define RTCS_DHCP 1
 
#define RTCS_PPP 0

extern void Main_task (uint_32);

void Ram_disk_start(void);

/* PPP device must be set manually and 
** must be different from the default IO channel (BSP_DEFAULT_IO_CHANNEL) 
*/
#define PPP_DEVICE      "ittyb:" 

/*
** Define PPP_DEVICE_DUN only when using PPP to communicate
** to Win9x Dial-Up Networking over a null-modem
** This is ignored if PPP_DEVICE is not #define'd
*/
#define PPP_DEVICE_DUN  1

/*
** Define the local and remote IP addresses for the PPP link
** These are ignored if PPP_DEVICE is not #define'd
*/
#define PPP_LOCADDR     IPADDR(192,168,0,216)
#define PPP_PEERADDR    IPADDR(192,168,0,217)

/*
** Define a default gateway
*/
#define GATE_ADDR       IPADDR(192,168,0,1)

#endif /* __main_h_ */

