//////////////////////////////////////////////////////////////////////////////////	 
//
//  文 件 名   : main.c
//  功能描述   : OLED IIC (模拟IIC)接口演示例程
//              说明: 
//              ----------------------------------------------------------------
//              GND   电源地
//              VCC   接5V或3.3v电源
//              SCL   接PA7（SCL）
//              SDA   接PA5（SDA）            
//              ----------------------------------------------------------------
//由于f4 主频太高用AHB原始时钟OLED根本扛不住所以在OLED发送函数OLED_WR_Byte暂时对AHB做了降频处理.
//******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "usart.h"
#include "bmp.h"
 int main(void)
{
    int a=20;
	  delay_init(RCC_SYSCLK_Div8);	    	 //延时函数初始化	
	  uart_init(115200);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级 	LED_Init();			     //LED端口初始化
		OLED_Init();			//初始化OLED  
		OLED_Clear(); 

	 


	while(1) 
	{		
		OLED_Clear();
		OLED_DrawBMP(0,0,128,8,BMP1);  //图片显示(图片显示慎用，生成的字表较大，会占用较多空间，FLASH空间8K以下慎用)
		OLED_ShowCHinese(0+a,2,0);//嵌
		OLED_ShowCHinese(18+a,2,1);//入
		OLED_ShowCHinese(36+a,2,2);//式
		OLED_ShowCHinese(54+a,2,3);//开
		OLED_ShowCHinese(72+a,2,4);//发
		OLED_ShowString(15,4,(uint8_t*)"growupfanfan     @gmail.com",16);
		delay_ms(8000);
		OLED_DrawBMP(0,0,128,8,BMP2);
		delay_ms(8000);
		
	}	  
	
}

