#include "lcd.h"
#include "delay.h"
/*
extern unsigned char Current[] = "Current:U";
extern unsigned char Unit[] = "Unit:V";
extern unsigned char U[] = "U";
extern unsigned char I[] = "I";
extern unsigned char R[] = "R";
extern unsigned char C[] = "C";
extern unsigned char L[] = "L";
extern unsigned char V[] = "V";
extern unsigned char mA[] = "mA";
extern unsigned char kOhm[] = "kOhm";
extern unsigned char kpf[] = "kpf";
extern unsigned char kuh[] = "kuh";


void GPIO_LCD_Init(void)   //IO口初始化配置
{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);  

		//LCD的数据输出IO口
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		//LCD的控制IO口
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;				
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void LCD_AskBusy(void)   //判忙
{
		unsigned char status;
	  GPIO_WriteLow(GPIOA,0xFF);
		GPIO_ResetBits(GPIOB, RS_Pin);
		GPIO_SetBits(GPIOB, RW_Pin);
		do
		{
				GPIO_SetBits(GPIOB, EN_Pin);
				delay_ms(5);	
   			status = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_7);
				GPIO_ResetBits(GPIOB, EN_Pin);
		}while(status & 0x80);
}


void LCD_WriteCmd(unsigned char cmd)   //向LCD中写入命令
{
		LCD_AskBusy();
		GPIO_ResetBits(GPIOB, RS_Pin);
		GPIO_ResetBits(GPIOB, RW_Pin);
		GPIO_WriteLow(GPIOA,cmd);
		GPIO_SetBits(GPIOB, EN_Pin);
		GPIO_ResetBits(GPIOB, EN_Pin);
}

void LCD_WriteData(unsigned char data)   //向LCD中写入数据
{
		LCD_AskBusy();
		GPIO_SetBits(GPIOB, RS_Pin);
		GPIO_ResetBits(GPIOB, RW_Pin);
		GPIO_WriteLow(GPIOA,data);
		GPIO_SetBits(GPIOB, EN_Pin);
		GPIO_ResetBits(GPIOB, EN_Pin);
}

void LCD_ClearScreen(void)   //清屏
{
		LCD_WriteCmd(0x01);
		delay_ms(10);
			  
	  //LCD初始化配置
		LCD_WriteCmd(0x38);
		LCD_WriteCmd(0x0c);
		LCD_WriteCmd(0x06);
		LCD_WriteCmd(0x01);
}

void LCD_STR(unsigned int x, unsigned int y, unsigned char *str)   //在对应位置显示字符串
{
		unsigned int addr, i;
    if(y == 0)
		addr = 0x00 + x;
		else
		addr = 0x40 + x;
	  LCD_WriteCmd(addr | 0x80);
		while(str[i] != '\0')
		{
				LCD_WriteData(str[i]);
				i++;
		}
}

*/
