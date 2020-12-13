/*
 * trace.h
 *
 *  Created on: Sep 18, 2020
 *      Author: vakluchev
 */

#ifndef INC_TRACE_H_
#define INC_TRACE_H_

#include "main.h"
#include "crc32.h"
#include <string.h>

#define CLK_Prescaler		1000000

#define	DWT_CYCCNT			*(volatile unsigned long *)0xE0001004
#define DWT_CONTROL 		*(volatile unsigned long *)0xE0001000
#define SCB_DEMCR   		*(volatile unsigned long *)0xE000EDFC

#define InitCC() 			SCB_DEMCR |= 0x01000000
#define ResetCC() 			DWT_CYCCNT = 0
#define EnableCC() 			DWT_CONTROL |= 1
#define DisableCC() 		DWT_CONTROL &= ~1
#define GetCC() 			DWT_CYCCNT

#define TRACECRC_ADDR		0x10000000
#define TRACEINFO_ADDR		0x10000004
#define TRACELOG_ADDR		0x10000014
#define PRINTDATA_ADDR		0x10005000
#define DUMPBUF_ADDR		0x1000A000

//Event codes
#define LED1				0x01 	//Green
#define LED2				0x02	//Yellow
#define LED3				0x03	//Red
#define PRINT				0x04
#define DUMP				0x05

#define P0					0x10
#define P1					0x11
#define P2					0x12
#define P3					0x13
#define P4					0x14
#define P5					0x15
#define P6					0x16
#define P7					0x17
#define P8					0x18
#define P9					0x19

typedef struct {
	uint32_t tracelog_size;
	uint32_t printlog_size;
	uint32_t dumpbuf_size;
	uint32_t task_id;
}traceinfo_t;

typedef struct {
	uint32_t timecode;
	uint32_t eventcode;
}tracelog_t;

void MX_TRACE_Init(void);
void SDK_TRACE_Start(void);
void SDK_TRACE_Stop(void);
void SDK_TRACE_Timestamp(uint8_t id, uint8_t value);
void SDK_TRACE_Print(char * format, ...);
void SDK_TRACE_Dump(uint32_t addr, uint16_t size);

#endif /* INC_TRACE_H_ */
