#ifndef __LCD_H
#define __LCD_H
/*
//LCD1602�Ŀ���IO�ڵĶ���

#define		RS_Pin		GPIO_Pin_5
#define		RW_Pin		GPIO_Pin_6
#define		EN_Pin		GPIO_Pin_7

//Ϊ�˶�PA�Ͱ�λ���в���
#define GPIO_WriteLow(GPIOx,a)    GPIOx->BSRR=(((uint32_t)(uint8_t)~(a))<<16)|((uint32_t)(uint8_t)(a))

void GPIO_LCD_Init(void);   //IO�ڳ�ʼ������
void LCD_AskBusy(void);   //��æ
void LCD_WriteCmd(unsigned char cmd);   //��LCD��д������
void LCD_WriteData(unsigned char data);   //��LCD��д������
void LCD_ClearScreen(void);   //����
void LCD_STR(unsigned int x, unsigned int y, unsigned char *str);   //�ڶ�Ӧλ����ʾ�ַ���

//��Ҫ��LCD����ʾ����ʾ�ַ�
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
