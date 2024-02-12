#include "LCD.h"
#include "BUTTON.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	unsigned char counter1 = 0;
	unsigned char counter2 = 0;
	unsigned char counter3 = 0;
	unsigned char counter4 = 0;
	//Initialize LCD
	LCD_vInit();
	//Enable Internal Pull of PB3,PB4,PB5,PB6,PB7
	BUTTON_vEnableInternalPullUp('B', 3);
	BUTTON_vEnableInternalPullUp('B', 4);
	BUTTON_vEnableInternalPullUp('B', 5);
	BUTTON_vEnableInternalPullUp('B', 6);
	BUTTON_vEnableInternalPullUp('B', 7);
	//Show Candidates Names in LCD
	LCD_vSendString("A=");
	LCD_vMoveCursor(1, 12);
	LCD_vSendString("B=");
	LCD_vMoveCursor(2, 1);
	LCD_vSendString("C=");
	LCD_vMoveCursor(2, 12);
	LCD_vSendString("D=");
    while(1)
    {
		//Show Number of votes to candidate 1
		LCD_vMoveCursor(1, 3);
		if(counter1 < 10)
		{
			LCD_vSendChar(counter1+48);
		}
		else if(counter1 < 100)
		{
			LCD_vSendChar((counter1 / 10) + 48);
			LCD_vSendChar((counter1 % 10) + 48);
		}
		else if(counter1 < 1000)
		{
			LCD_vSendChar((counter1 / 100)+48);
			LCD_vSendChar(((counter1 % 100) / 10) + 48);
			LCD_vSendChar(((counter1 % 100) % 10) + 48);
		}
		//Show Number of votes to candidate 2
		LCD_vMoveCursor(1, 14);
		if(counter2 < 10)
		{
			LCD_vSendChar(counter2 +48);
		}
		else if(counter2 < 100)
		{
			LCD_vSendChar((counter2 / 10) + 48);
			LCD_vSendChar((counter2 % 10) + 48);
		}
		else if(counter2 < 1000)
		{
			LCD_vSendChar((counter2 / 100) + 48);
			LCD_vSendChar(((counter2 % 100) / 10) + 48);
			LCD_vSendChar(((counter2 % 100) % 10) + 48);
		}
		//Show Number of votes to candidate 3
		LCD_vMoveCursor(2, 3);
		if(counter3 < 10)
		{
			LCD_vSendChar(counter3 + 48);
		}
		else if(counter3 < 100)
		{
			LCD_vSendChar((counter3 / 10)+48);
			LCD_vSendChar((counter3 % 10) + 48);
		}
		else if(counter3 < 1000)
		{
			LCD_vSendChar((counter3 / 100)+48);
			LCD_vSendChar(((counter3 % 100) / 10) + 48);
			LCD_vSendChar(((counter3 % 100) % 10) + 48);
		}
		//Show Number of votes to candidate 4
		LCD_vMoveCursor(2, 14);
		if(counter4 < 10)
		{
			LCD_vSendChar(counter4 +48);
		}
		else if(counter4 < 100)
		{
			LCD_vSendChar((counter4 / 10)+48);
			LCD_vSendChar((counter4 % 10) + 48);
		}
		else if(counter4 < 1000)
		{
			LCD_vSendChar((counter4 / 100)+48);
			LCD_vSendChar(((counter4 % 100) / 10) + 48);
			LCD_vSendChar(((counter4 % 100) % 10) + 48);
		}
		//Check Which button is pushed
		if(BUTTON_u8ReadStatus('B', 3) == 0)
		{
			_delay_ms(20); //delay for switch bouncing
			if(BUTTON_u8ReadStatus('B', 3) == 0)
			{
				counter1++;
				while(BUTTON_u8ReadStatus('B', 3) == 0);
			}
		}	
		else if(BUTTON_u8ReadStatus('B', 4) == 0)
		{
			_delay_ms(20); //delay for switch bouncing
			if(BUTTON_u8ReadStatus('B', 4) == 0)
			{
				counter2++;
				while(BUTTON_u8ReadStatus('B', 4) == 0);
			}
		}	
		else if(BUTTON_u8ReadStatus('B', 5) == 0)
		{
			_delay_ms(20); //delay for switch bouncing
			if(BUTTON_u8ReadStatus('B', 5) == 0)
			{
				counter3++;
				while(BUTTON_u8ReadStatus('B', 5) == 0);
			}
		}	
		else if(BUTTON_u8ReadStatus('B', 6) == 0)
		{
			_delay_ms(20); //delay for switch bouncing
			if(BUTTON_u8ReadStatus('B', 6) == 0)
			{
				counter4++;
				while(BUTTON_u8ReadStatus('B', 6) == 0);
			}
		}
		else if(BUTTON_u8ReadStatus('B', 7) == 0)
		{
			_delay_ms(20); //delay for switch bouncing
			if(BUTTON_u8ReadStatus('B', 7) == 0)
			{
				counter1 = counter2 = counter3 = counter4 = 0;
				LCD_vClearScreen();
				LCD_vSendString("A=");
				LCD_vMoveCursor(1, 12);
				LCD_vSendString("B=");
				LCD_vMoveCursor(2, 1);
				LCD_vSendString("C=");
				LCD_vMoveCursor(2, 12);
				LCD_vSendString("D=");
				while(BUTTON_u8ReadStatus('B', 7) == 0);
			}
		}
    }
}