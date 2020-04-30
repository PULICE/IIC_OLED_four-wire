
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
//����f4 ��Ƶ̫����AHBԭʼʱ��OLED��������ס���Զ�AHB���˽�Ƶ����ͬʱ��ʱ����Ҳ��16�ִ���
//******************************************************************************/

#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "usart.h"
#include "bmp.h"
 int main(void)
{
	  u8 t;
	  delay_init(RCC_SYSCLK_Div8);	    	 //��ʱ������ʼ��	
	  uart_init(115200);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ� 	LED_Init();			     //LED�˿ڳ�ʼ��
		OLED_Init();			//��ʼ��OLED  
		OLED_Clear()  	; 
		t=' ';
	 


	while(1) 
	{		

		delay_ms(500);
		OLED_Clear();
		OLED_ShowCHinese(0,0,0);//Ƕ
		OLED_ShowCHinese(18,0,1);//��
		OLED_ShowCHinese(36,0,2);//ʽ
		OLED_ShowCHinese(54,0,3);//��
		OLED_ShowCHinese(72,0,4);//��
		OLED_ShowCHinese(90,0,5);//��
		OLED_ShowString(6,3,(uint8_t*)"mcudev.taobao.com",16);
		OLED_ShowString(0,6,(uint8_t*)"ASCII:",16);  
		OLED_ShowString(63,6,(uint8_t*)"CODE:",16);  
		OLED_ShowChar(48,6,t,16);//��ʾASCII�ַ�	   
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(103,6,t,3,16);//��ʾASCII�ַ�����ֵ 	
		delay_ms(1000);
    printf("test��printf ok\r\n");
		OLED_DrawBMP(0,0,128,8,BMP1);  //ͼƬ��ʾ(ͼƬ��ʾ���ã����ɵ��ֱ�ϴ󣬻�ռ�ý϶�ռ䣬FLASH�ռ�8K��������)
		delay_ms(1000);

    printf("���ֲ���\r\n");
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

