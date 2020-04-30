
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
//由于f4 主频太高用AHB原始时钟OLED根本扛不住所以对AHB做了降频处理，同时延时函数也做16分处理
//******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "usart.h"
#include "bmp.h"
 int main(void)
{
	  u8 t;
	  delay_init(RCC_SYSCLK_Div8);	    	 //延时函数初始化	
	  uart_init(115200);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级 	LED_Init();			     //LED端口初始化
		OLED_Init();			//初始化OLED  
		OLED_Clear()  	; 
		t=' ';
	 


	while(1) 
	{		

		delay_ms(500);
		OLED_Clear();
		OLED_ShowCHinese(0,0,0);//嵌
		OLED_ShowCHinese(18,0,1);//入
		OLED_ShowCHinese(36,0,2);//式
		OLED_ShowCHinese(54,0,3);//开
		OLED_ShowCHinese(72,0,4);//发
		OLED_ShowCHinese(90,0,5);//网
		OLED_ShowString(6,3,(uint8_t*)"mcudev.taobao.com",16);
		OLED_ShowString(0,6,(uint8_t*)"ASCII:",16);  
		OLED_ShowString(63,6,(uint8_t*)"CODE:",16);  
		OLED_ShowChar(48,6,t,16);//显示ASCII字符	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(103,6,t,3,16);//显示ASCII字符的码值 	
		delay_ms(1000);
    printf("test、printf ok\r\n");
		OLED_DrawBMP(0,0,128,8,BMP1);  //图片显示(图片显示慎用，生成的字表较大，会占用较多空间，FLASH空间8K以下慎用)
		delay_ms(1000);

    printf("汉字测试\r\n");
		OLED_DrawBMP(0,0,128,8,BMP2);
		delay_ms(1000);

		
		OLED_DrawBMP(0,0,128,8,BMP3);
		delay_ms(1000);

		
		OLED_DrawBMP(0,0,128,8,BMP4);
		delay_ms(1000);

		
		OLED_DrawBMP(0,0,128,8,BMP5);
		delay_ms(1000);

		
		OLED_DrawBMP(0,0,128,8,BMP6);
		delay_ms(1000);

	}	  
	
}

