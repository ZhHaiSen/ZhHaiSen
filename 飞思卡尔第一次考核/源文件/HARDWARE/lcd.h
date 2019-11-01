#ifndef __LCD_H
#define __LCD_H
/*
//LCD1602的控制IO口的定义

#define		RS_Pin		GPIO_Pin_5
#define		RW_Pin		GPIO_Pin_6
#define		EN_Pin		GPIO_Pin_7

//为了对PA低八位进行操作
#define GPIO_WriteLow(GPIOx,a)    GPIOx->BSRR=(((uint32_t)(uint8_t)~(a))<<16)|((uint32_t)(uint8_t)(a))

void GPIO_LCD_Init(void);   //IO口初始化配置
void LCD_AskBusy(void);   //判忙
void LCD_WriteCmd(unsigned char cmd);   //向LCD中写入命令
void LCD_WriteData(unsigned char data);   //向LCD中写入数据
void LCD_ClearScreen(void);   //清屏
void LCD_STR(unsigned int x, unsigned int y, unsigned char *str);   //在对应位置显示字符串

//需要在LCD上显示的提示字符
extern unsigned char Current[];
extern unsigned char Unit[];
extern unsigned char U[];
extern unsigned char I[];
extern unsigned char R[];
extern unsigned char C[];
extern unsigned char L[];
extern unsigned char V[];
extern unsigned char mA[];
extern unsigned char kOhm[];
extern unsigned char kpf[];
extern unsigned char kuh[];
*/
#endif
