/*
	This example shows how to erase and write to application section
	in flash memory. The bootloader contains an application that is 
	stored in an array. Bootloader flashes the application in the 
	application section and then jumps to its location to execute it.
*/



#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/boot.h>
#include <stdio.h>


const uint8_t hexdata[256] = {
			/* address: 0x0000XXXX */
			/* 0x0000 */
			0x0C, 0x94, 0x2A, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			/* 0x0010 */
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			/* 0x0020 */
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			/* 0x0030 */
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			/* 0x0040 */
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			0x0C, 0x94, 0x34, 0x00,
			/* 0x0050 */
			0x0C, 0x94, 0x34, 0x00,
			0x11, 0x24, 0x1F, 0xBE,
			0xCF, 0xE5, 0xD8, 0xE0,
			0xDE, 0xBF, 0xCD, 0xBF,
			/* 0x0060 */
			0x0E, 0x94, 0x36, 0x00,
			0x0C, 0x94, 0x4C, 0x00,
			0x0C, 0x94, 0x00, 0x00,
			0x8F, 0x9A, 0x40, 0xE9,
			/* 0x0070 */
			0x51, 0xE0, 0x97, 0x98,
			0x20, 0xED, 0x37, 0xE0,
			0xCA, 0x01, 0x01, 0x97,
			0xF1, 0xF7, 0x21, 0x50,
			/* 0x0080 */
			0x30, 0x40, 0xD1, 0xF7,
			0x97, 0x9A, 0x20, 0xED,
			0x37, 0xE0, 0xCA, 0x01,
			0x01, 0x97, 0xF1, 0xF7,
			/* 0x0090 */
			0x21, 0x50, 0x30, 0x40,
			0xD1, 0xF7, 0xED, 0xCF,
			0xF8, 0x94, 0xFF, 0xCF,
			/* END OF DATA */

			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,

			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,

			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,

			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,

			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			0xFF, 0xFF, 0xFF, 0xFF,
			};


void boot_program_page (uint32_t page, uint8_t *buf)
{
	uint16_t i;

	/* Erase page */
	boot_page_erase (page);
	/* Wait until the memory is erased */
	boot_spm_busy_wait ();

	for (i=0; i<SPM_PAGESIZE; i+=2)
	{
		/* Set up little-endian word */
		uint16_t w = *buf++;
		w += (*buf++) << 8;

		/* Fill temporarily word buffer */
		boot_page_fill (page + i, w);
	}

	/* Store buffer in flash page */
	boot_page_write (page);
	/* Wait until the memory is written */
	boot_spm_busy_wait();

	/* Reenable RWW-section again. We need this if we want to jump back
	 to the application after bootloading */

	boot_rww_enable ();
}


int main ( void )
{

	DDRD |= 0x80;

	/* Turn LED on */
	PORTD |= 0x80;

	/* Flash first 128 bytes from hexdata array in page 1 */
	boot_program_page(0, hexdata);
	/* Flash second 128 bytes from hexdata array in page 2 */
	boot_program_page(128, &hexdata[128]);

	/* Turn LED off */
	PORTD &= ~0x80;

	/* jump to application programmed at 0x0000 */
	asm ( "jmp 0x0000" );
}



