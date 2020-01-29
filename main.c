/*
 * GccApplication1.c
 *
 * Created: 26-01-2020 16:26:01
 * Author : CG-DTE
 */ 

#include <avr/io.h>
void start()
{   
	TWBR=0.5;
	TWSR=~3&TWSR
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT));
	while ((TWSR & (0xF8)) != 0x08);
}
void Addr(unsigned char ADDR)
{
	TWDR=ADDR; 
	TWCR=(1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	while ((TWSR & (0xF8)) !=0x18);
}
void write_Data(unsigned char DATA)
{
	TWDR=DATA;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	while ((TWSR & (0xF8)) !=0x28);
}
void read()
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}
void STOP()
{
	TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}



