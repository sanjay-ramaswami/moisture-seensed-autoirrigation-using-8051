#include<reg51.h>
#include<stdio.h>
#include<intrins.h>
#define LCD_dat P2
sbit rs =P3^0;
sbit en =P3^1;
sbit soil = P1^1;
		sbit relay = P1^0;
void dely(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);

void main(void)
{  
	
	unsigned int SOIL = soil;
	
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
  while(1) /* infinity loop */
	{
		if(SOIL == 1)
		{
						lcd_cmd(0x80);
		lcd_str("MOISTURE : LOW"); // '\0'
	lcd_cmd(0xc0);
		lcd_str("MOTOR STATE : ON"); // '\0'
//lcd_cmd(0x01);
			relay = 0;
			break;
		}
		else
		{
			lcd_cmd(0x80);
		lcd_str("MOISTURE : OK "); // '\0'
	lcd_cmd(0xc0);
		lcd_str("MOTOR STATE :OFF"); // '\0'
	 // lcd_cmd(0x01);
			relay = 1;
			
			break;
	}
	
}
	}
void lcd_str(unsigned char *str)
{
	unsigned int loop =0;
	for(loop =0; str[loop]!= '\0'; loop++)
	{
		lcd_data(str[loop]);
	}
}
void lcd_data(unsigned char ch)
{
	LCD_dat = ch;
	rs = 1;  // data	
	en = 1;
	dely(10);
	en = 0;
}

void lcd_cmd(unsigned char ch)
{
	LCD_dat = ch;
	rs = 0;  // cmd
	en = 1;
	dely(10);
	en = 0;
}
void dely(unsigned int dly)
{
	unsigned int loop =0;
	unsigned int delay_gen =0;
	for(loop =0; loop < dly; loop++)
	for(delay_gen =0; delay_gen < 1000; delay_gen++); /* delay */
}