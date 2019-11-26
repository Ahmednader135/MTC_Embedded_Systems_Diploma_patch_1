#include "std_types.h"
#include "bit_math.h"
#include "IIC.h"


#define SLAVE_ADDRESS 0xA0


stdReturnType_t EXT_EEPROM_Write_Byte(u16 address,u8 data)
{
	u8 state = 0;
	u8 address_high = (address>>8) & 0x0F;
	u8 address_low =  (u8) address;
	
	/* Start condition */
	TWI_Start();
	/* Get state */
	state = TWI_GetStatus();
	/* Check that start condition sent */
	if(state != TWI_START)
	{
		return ERROR;
	}
	/* Send slave address */
	TWI_Write(SLAVE_ADDRESS);
	/* Get state */
	state = TWI_GetStatus();
	/* Check that slave address is sent successfully */
	if(state != TWI_MT_SLA_ACK)
	{
		return ERROR;
	}
	/* Send memory address (HIGH) location to write */
	TWI_Write(address_high);
	/* Get state */
	state = TWI_GetStatus();
	/* Check that memory address is sent successfully */
	if(state != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}
	/* Send memory address (LOW) location to write */
	TWI_Write(address_low);
	/* Get state */
	state = TWI_GetStatus();
	/* Check that memory address is sent successfully */
	if(state != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}
	/* Send data to write to memory */
	TWI_Write(data);
	/* Get state */
	state = TWI_GetStatus();
	/* Check data is sent successfully */
	if(state != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}
	/* Stop condition */
	TWI_Stop();
	
	return SUCCESS;
}



stdReturnType_t EXT_EEPROM_Read_Byte(u16 address,u8 * data)
{
	u8 state = 0;
	u8 address_high = (address>>8) & 0x0F;
	u8 address_low =  (u8) address;
	
	/* Start condition */
	TWI_Start();
	/* Get state */
	state = TWI_GetStatus();
	/* Check that start condition sent */
	if(state != TWI_START)
	{
		return ERROR;
	}
	/* Send slave address */
	TWI_Write(SLAVE_ADDRESS);
	/* Get state */
	state = TWI_GetStatus();
	/* Check that slave address is sent successfully */
	if(state != TWI_MT_SLA_ACK)
	{
		return ERROR;
	}
	/* Send memory address (HIGH) location to write */
	TWI_Write(address_high);
	/* Get state */
	state = TWI_GetStatus();
	/* Check that memory address is sent successfully */
	if(state != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}
	/* Send memory address (LOW) location to write */
	TWI_Write(address_low);
	/* Get state */
	state = TWI_GetStatus();
	/* Check that memory address is sent successfully */
	if(state != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}
	/* Repeated Start condition */
	TWI_Start();
	/* Get state */
	state = TWI_GetStatus();
	/* Check that repeated start condition sent */
	if(state != TWI_REP_START)
	{
		return ERROR;
	}
	/* Send slave address */
	TWI_Write(SLAVE_ADDRESS | 0x01);
	/* Get state */
	state = TWI_GetStatus();
	/* Check that slave address is sent successfully */
	if(state != TWI_MR_SLA_ACK)
	{
		return ERROR;
	}
	/* Read data */
	*data = TWI_ReadNACK();
	/* Get state */
	state = TWI_GetStatus();
	/* Check that slave address is sent successfully */
	if(state != TWI_MR_DATA_NOT_ACK)
	{
		return ERROR;
	}
	/* Stop condition */
	TWI_Stop();
	
	return SUCCESS;
	
}
