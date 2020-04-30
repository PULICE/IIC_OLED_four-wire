/****************************************************************************	  
//  ��������   : OLED 4�ӿ���ʾ����(51ϵ��)
//              ˵��: 
//              ------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��5V��3.3v��Դ
//              D0   ��PA6��SCL��
//              D1   ��PA7��SDA��
//              RES  ��PA4
//              DC   ��PA5
//              CS   ��PA3               

****************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "stm32f4xx.h"
 int main(void)
 {	u8 t;
		delay_init(RCC_SYSCLK_Div2);	    	 //��ʱ������ʼ��	  
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� 	LED_Init();			     //LED�˿ڳ�ʼ��
		OLED_Init();			//��ʼ��OLED  
		OLED_Clear(); 
		t=' ';
	while(1) 
	{		
		OLEDdisplay();
		delay_ms(6000);
		OLED_Clear();
		OLED_ShowString(0,3,(unsigned char*)"1.3' OLED TEST");
		OLED_ShowString(0,6,(unsigned char*)"ASCII:");  
		OLED_ShowString(63,6,(unsigned char*)"CODE:");  
		OLED_ShowChar(48,6,t);//��ʾASCII�ַ�	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(103,6,t,3,16);//��ʾASCII�ַ�����ֵ 	
		delay_ms(2000);
		OLED_Clear();
		OLED_DrawBMP(0,0,128,8,BMP1);  //ͼƬ��ʾ(ͼƬ��ʾ���ã����ɵ��ֱ�ϴ󣬻�ռ�ý϶�ռ䣬FLASH�ռ�8K��������)
		delay_ms(2000);



	}	  
	
}

