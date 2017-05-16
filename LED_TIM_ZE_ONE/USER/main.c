/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The TIM application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-10-30
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "systick.h"
#include <stdio.h>

/* Difine ------------------------------------------------------------------*/

#define YdirNumber 7
#define XdirNumber 7
#define Row YdirNumber*8 
#define Col XdirNumber*16 

#define H138_A_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_0);
#define H138_A_H			 GPIO_SetBits(GPIOF , GPIO_Pin_0);
#define H138_B_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_1);
#define H138_B_H			 GPIO_SetBits(GPIOF , GPIO_Pin_1);
#define H138_C_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_2);
#define H138_C_H			 GPIO_SetBits(GPIOF , GPIO_Pin_2);
#define MBI5026_SDI1_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_3);
#define MBI5026_SDI1_H			 GPIO_SetBits(GPIOF , GPIO_Pin_3);
#define MBI5026_SDI2_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_4);
#define MBI5026_SDI2_H		   GPIO_SetBits(GPIOF , GPIO_Pin_4);
#define MBI5026_SDI3_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_5);
#define MBI5026_SDI3_H			 GPIO_SetBits(GPIOF , GPIO_Pin_5);
#define MBI5026_SDI4_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_11);
#define MBI5026_SDI4_H			 GPIO_SetBits(GPIOF , GPIO_Pin_11);
#define MBI5026_SDI5_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_12);
#define MBI5026_SDI5_H			 GPIO_SetBits(GPIOF , GPIO_Pin_12);
#define MBI5026_SDI6_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_13);
#define MBI5026_SDI6_H			 GPIO_SetBits(GPIOF , GPIO_Pin_13);
#define MBI5026_SDI7_L 		   GPIO_ResetBits(GPIOF , GPIO_Pin_14);
#define MBI5026_SDI7_H			 GPIO_SetBits(GPIOF , GPIO_Pin_14);



#define MBI5026_OE_L   GPIO_ResetBits(GPIOF , GPIO_Pin_15); 
#define MBI5026_OE_H   GPIO_SetBits(GPIOF , GPIO_Pin_15);
#define H138_D_L  GPIO_ResetBits(GPIOG , GPIO_Pin_0);
#define H138_D_H  GPIO_SetBits(GPIOG , GPIO_Pin_0);
#define MBI5026_CLK_L  GPIO_ResetBits(GPIOG , GPIO_Pin_1);
#define MBI5026_CLK_H  GPIO_SetBits(GPIOG , GPIO_Pin_1);
#define MBI5026_LE_L	 GPIO_ResetBits(GPIOG , GPIO_Pin_2);
#define MBI5026_LE_H   GPIO_SetBits(GPIOG , GPIO_Pin_2);

/* Private function prototypes -----------------------------------------------*/
void GPIO_Configuration(void);
void NVIC_Configuration(void);
void TIM_Configuration(void);
void Clean(void);
void Light(void);
void  Delay (uint32_t nCount);
/* Private variables ---------------------------------------------------------*/	
static uint8_t disBuff[56][14];
static uint8_t linecount=0;
//static uint8_t 

/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
int main(void)
{
	uint8_t i,j,m;
	
	GPIO_Configuration();
	delay_init();
	NVIC_Configuration();
	TIM_Configuration();
	Clean();
	
    /* Infinite loop */
    while (1)
		{
		//编写程序更新显示库disBuff数组；
			for(i=0; i<Row ; i++)
				{
						for(j=0;j<Col/8;j++)
						{
							disBuff[i][j]=0x80;
							delay_ms(1);
							for(m=0;m<8;m++)
							{
								disBuff[i][j]=disBuff[i][j]>>1;
								delay_ms(1);
			          
							}							
						}
				}
			   Light();
			   delay_ms(1000);
				 Clean();
			   delay_ms(1000);
				 Light();
				 delay_ms(1000);
				 Clean();
				 delay_ms(1000);		
				 delay_ms(1000);
			
    }

}

/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configures the different GPIO ports.
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG, ENABLE); 						 
				 
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_10| GPIO_Pin_11| GPIO_Pin_12| GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15 ;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 
  GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 ;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
}

/*******************************************************************************
* Function Name  : TIM_Configuration
* Description    : TIM_Configuration program.
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void TIM_Configuration(void)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;		  //定义一个结构体
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);	  //使能TIM2外设
  TIM_DeInit(TIM2);
  TIM_TimeBaseStructure.TIM_Period=100;		 		  /*自动重装载寄存
  															器周期的值(计数值) 
												            累计 TIM_Period个
															频率后产生一个更新
															或者中断 */
  TIM_TimeBaseStructure.TIM_Prescaler= (720 - 1);		 // 时钟预分频数   分出时钟=主频/（分频系数-1）10us；100kHz；
  TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;  // 采样分频 
  TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;// 向上计数模式 
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);/*根据TIM_TimeBaseStructure中指定
  												  的参数初始化TIM2的时间基数单位 */
  TIM_ClearFlag(TIM2, TIM_FLAG_Update);					// 清除溢出中断标志 
  TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);				//使能中断
  TIM_Cmd(TIM2, ENABLE);								// 开启时钟 
}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configuration the nested vectored interrupt controller.
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;            //定义一个结构体	 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); //设置优先级组  													
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; //设置 TIM2优先级	  
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//配置抢断优先级
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;   //配置响应优先级	
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	 //使能优先级
  NVIC_Init(&NVIC_InitStructure);
}


/*******************************************************************************
* Function Name  : Clean
* Description    : 清空显示区
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void Clean(void)
{
	uint8_t i,j;
	
	for(i=0; i<Row ; i++)
	{
		for(j=0;j<Col/8;j++)
		{
			disBuff[i][j]=0x00;   //全黑
		}
	}
}


/*******************************************************************************
* Function Name  : Light
* Description    : 全部点亮灯
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void Light(void)
{
	   uint8_t i,j;
		for(i=0; i<Row ; i++)
				{
						for(j=0;j<Col/8;j++)
						{
								disBuff[i][j]=0xFF;   //全亮
						}
				}
}

/*******************************************************************************
* Function Name  : Delay
* Description    : Delay Time
* Input          : - nCount: Delay Time
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void  Delay (uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}


/*******************************************************************************
* Function Name  : MBIsenddata
* Description    : 列数据移位程序 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void MBIsenddata(uint8_t k)
{
	  int8_t i;
		uint8_t j;
		uint8_t data1,data2,data3,data4,data5,data6,data7;//七块列数据一起移位
	for(i=(Col/8)-1;i>=0;i--)
	{
		data1=disBuff[k][i];
		data2=disBuff[k+8][i];
		data3=disBuff[k+16][i];
		data4=disBuff[k+24][i];
		data5=disBuff[k+32][i];
		data6=disBuff[k+40][i];
		data7=disBuff[k+48][i];
		for(j=0;j<8;j++)
			{
				MBI5026_CLK_L;
				if((0x01&data1)==1)
					{MBI5026_SDI1_H;}
					else MBI5026_SDI1_L;
					
				if((0x01&data2)==1)
					{MBI5026_SDI2_H;}
					else MBI5026_SDI2_L;
					
				if((0x01&data3)==1)
					{MBI5026_SDI3_H;}
					else MBI5026_SDI3_L;
					
				if((0x01&data4)==1)
					{MBI5026_SDI4_H;}
					else MBI5026_SDI4_L;
					
				if((0x01&data5)==1)
					{MBI5026_SDI5_H;}
					else MBI5026_SDI5_L;
					
				if((0x01&data6)==1)
					{MBI5026_SDI6_H;}
					else MBI5026_SDI6_L;
					
				if((0x01&data7)==1)
					{MBI5026_SDI7_H;}
					else MBI5026_SDI7_L;
					
					//delay_us(5);
					Delay(5);
					MBI5026_CLK_H;
					//delay_us(5);
					Delay(5);
					data1=data1>>1;
					data2=data2>>1;
					data3=data3>>1;
					data4=data4>>1;
					data5=data5>>1;
					data6=data6>>1;
					data7=data7>>1;
					
			}
	} 
}

/*******************************************************************************
* Function Name  : HC138_display
* Description    : 行控制程序
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void HC138_display(uint8_t m)
{
	switch(m)
	{ //第一片138
		case  7 :   H138_D_H; H138_C_L; H138_B_L; H138_A_L; break; 
		case  6 :   H138_D_H; H138_C_L; H138_B_L; H138_A_H; break; 
		case  5 :   H138_D_H; H138_C_L; H138_B_H; H138_A_L; break; 
		case  4 :   H138_D_H; H138_C_L; H138_B_H; H138_A_H; break;
		case  3 :   H138_D_H; H138_C_H; H138_B_L; H138_A_L; break;
		case  2 :   H138_D_H; H138_C_H; H138_B_L; H138_A_H; break;
		case  1 :   H138_D_H; H138_C_H; H138_B_H; H138_A_L; break;
		case  0 :   H138_D_H; H138_C_H; H138_B_H; H138_A_H; break;
		}
}



/*******************************************************************************
* Function Name  : TIM2_IRQHandler
* Description    : This function handles TIM2 Handler.
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void TIM2_IRQHandler(void)
{
    
	if ( TIM_GetITStatus(TIM2 , TIM_IT_Update) != RESET ) 
	{	//检测是否发生溢出更新事件
		TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);
		
     MBIsenddata(linecount);  
		 MBI5026_OE_H;
		 Delay(10);
		 MBI5026_LE_H;    //锁存
		 Delay(10);
		 MBI5026_LE_L;   
		 Delay(5);
		 HC138_display(linecount);
		 MBI5026_OE_L;
		 Delay(5);
		 if((linecount++)>=(Row/YdirNumber)-1)linecount=0;
  }	
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

