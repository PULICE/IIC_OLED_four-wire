/******************************************************************************* 
*���ϵ�Դ��ʵ�������example�ǿ�������7��OLED��Ļ�ģ�����OLED�����IO������oled.h
*��������ϸ��˵��������Ͳ���׸����
******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
 int main(void)
 {	u8 t;
		delay_init();	    	 //��ʱ������ʼ��	  
		NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� 	LED_Init();			     //LED�˿ڳ�ʼ��
		OLED_Init();			//��ʼ��OLED  
		OLED_Clear()  	; 

		t='\0';
	OLED_Clear();
	OLED_DrawBMP(0,0,128,8,BMP1);  //ͼƬ��ʾ(ͼƬ��ʾ���ã����ɵ��ֱ�ϴ󣬻�ռ�ý϶�ռ䣬FLASH�ռ�8K��������)
	delay_ms(8000);
	delay_ms(8000);
	OLED_Clear();

	OLED_ShowString(0,4,(unsigned char*)"1.3' OLED TEST");
	OLED_ShowString(20,6,(unsigned char*)"2020/12/29");  
	OLED_ShowString(0,1,(unsigned char*)"ASCII:");  
	OLED_ShowString(63,1,(unsigned char*)"CODE:");  
	while(1) 
	{		

		OLED_ShowChar(48,1,t);//��ʾASCII�ַ�	 
		
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(103,1,t,3,16);//��ʾASCII�ַ�����ֵ 	
		delay_ms(100);






	}	  
	
}

