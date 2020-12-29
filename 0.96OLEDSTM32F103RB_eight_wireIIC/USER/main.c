/******************************************************************************* 
*加上电源线实际上这个example是可以驱动7线OLED屏幕的，关于OLED具体的IO定义在oled.h
*中以有详细的说明，这里就不在赘述。
******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
 int main(void)
 {	u8 t;
		delay_init();	    	 //延时函数初始化	  
		NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级 	LED_Init();			     //LED端口初始化
		OLED_Init();			//初始化OLED  
		OLED_Clear()  	; 

		t='\0';
	OLED_Clear();
	OLED_DrawBMP(0,0,128,8,BMP1);  //图片显示(图片显示慎用，生成的字表较大，会占用较多空间，FLASH空间8K以下慎用)
	delay_ms(8000);
	delay_ms(8000);
	OLED_Clear();

	OLED_ShowString(0,4,(unsigned char*)"1.3' OLED TEST");
	OLED_ShowString(20,6,(unsigned char*)"2020/12/29");  
	OLED_ShowString(0,1,(unsigned char*)"ASCII:");  
	OLED_ShowString(63,1,(unsigned char*)"CODE:");  
	while(1) 
	{		

		OLED_ShowChar(48,1,t);//显示ASCII字符	 
		
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(103,1,t,3,16);//显示ASCII字符的码值 	
		delay_ms(100);






	}	  
	
}

