#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
#include "stdlib.h"	    	
//OLED模式设置
//0:4线串行模式
//1:并行8080模式
#define OLED_MODE 0
#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
/*-----------------OLED端口定义----------------*/ 
#define RCC_OLEDPeriph_CLOCKa()   RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
#define RCC_OLEDPeriph_Porta     RCC_APB2Periph_GPIOA
#define RCC_OLEDPeriph_Portb     RCC_APB2Periph_GPIOG
#define OLED_GeneralPort         GPIOA
#define OLED_ExtraPort           GPIOG

#define OLED_CS_Io               GPIO_Pin_3
#define OLED_RST_Io              GPIO_Pin_4
#define OLED_DC_Io               GPIO_Pin_5

#define OLED_SCLK_Io             GPIO_Pin_6//CLK或者叫DO
#define OLED_SDIN_Io             GPIO_Pin_7//DIN或者叫DI

/*在使用7线OLED且在模式0（OLED_MODE 0）时这 两个引脚的定义不必关心*/
#define OLED_WR_Io              GPIO_Pin_14
#define OLED_RD_Io              GPIO_Pin_13



#define OLED_CS_Clr()  GPIO_ResetBits(OLED_GeneralPort ,OLED_CS_Io)//CS
#define OLED_CS_Set()  GPIO_SetBits(OLED_GeneralPort ,OLED_CS_Io)

#define OLED_RST_Clr() GPIO_ResetBits(OLED_GeneralPort ,OLED_RST_Io)//RES
#define OLED_RST_Set() GPIO_SetBits(OLED_GeneralPort ,OLED_RST_Io)

#define OLED_DC_Clr() GPIO_ResetBits(OLED_GeneralPort ,OLED_DC_Io)//DC
#define OLED_DC_Set() GPIO_SetBits(OLED_GeneralPort ,OLED_DC_Io)




#define OLED_WR_Clr() GPIO_ResetBits(OLED_ExtraPort,OLED_WR_Io)
#define OLED_WR_Set() GPIO_SetBits(OLED_ExtraPort,OLED_WR_Io)

#define OLED_RD_Clr() GPIO_ResetBits(OLED_ExtraPort,OLED_RD_Io)
#define OLED_RD_Set() GPIO_SetBits(OLED_ExtraPort,OLED_RD_Io)



//PC0~7,作为数据线
//#define DATAOUT(x) GPIO_Write(GPIOC,x);//输出  
//使用4线或7线串行接口时使用 

#define OLED_SCLK_Clr() GPIO_ResetBits(OLED_GeneralPort ,OLED_SCLK_Io)
#define OLED_SCLK_Set() GPIO_SetBits(OLED_GeneralPort ,OLED_SCLK_Io)

#define OLED_SDIN_Clr() GPIO_ResetBits(OLED_GeneralPort ,OLED_SDIN_Io)
#define OLED_SDIN_Set() GPIO_SetBits(OLED_GeneralPort ,OLED_SDIN_Io)

 		     
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y, u8 *p);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
#endif  
	 



