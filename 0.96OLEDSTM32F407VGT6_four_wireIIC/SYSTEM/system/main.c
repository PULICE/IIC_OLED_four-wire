//////////////////////////////////////////////////////////////////////////////////	 
//
//  �� �� ��   : main.c
//  ��������   : OLED IIC (ģ��IIC)�ӿ���ʾ����
//              ˵��: 
//              ----------------------------------------------------------------
//              GND   ��Դ��
//              VCC   ��5V��3.3v��Դ
//              SCL   ��PA7��SCL��
//              SDA   ��PA5��SDA��            
//              ----------------------------------------------------------------
//����f4 ��Ƶ̫����AHBԭʼʱ��OLED��������ס������OLED���ͺ���OLED_WR_Byte��ʱ��AHB���˽�Ƶ����.
//******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "usart.h"
#include "bmp.h"
 int main(void)
{
    int a=20;
	  delay_init(RCC_SYSCLK_Div8);	    	 //��ʱ������ʼ��	
	  uart_init(115200);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� 	LED_Init();			     //LED�˿ڳ�ʼ��
		OLED_Init();			//��ʼ��OLED  
		OLED_Clear(); 

	 


	while(1) 
	{		
		OLED_Clear();
		OLED_DrawBMP(0,0,128,8,BMP1);  //ͼƬ��ʾ(ͼƬ��ʾ���ã����ɵ��ֱ�ϴ󣬻�ռ�ý϶�ռ䣬FLASH�ռ�8K��������)
		OLED_ShowCHinese(0+a,2,0);//Ƕ
		OLED_ShowCHinese(18+a,2,1);//��
		OLED_ShowCHinese(36+a,2,2);//ʽ
		OLED_ShowCHinese(54+a,2,3);//��
		OLED_ShowCHinese(72+a,2,4);//��
		OLED_ShowString(15,4,(uint8_t*)"growupfanfan     @gmail.com",16);
		delay_ms(8000);
		OLED_DrawBMP(0,0,128,8,BMP2);
		delay_ms(8000);
		
	}	  
	
}

