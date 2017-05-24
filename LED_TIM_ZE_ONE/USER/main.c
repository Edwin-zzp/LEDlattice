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
#include "Pic_h.h"

/* Difine ------------------------------------------------------------------*/

#define YdirNumber 7
#define XdirNumber 7
#define Row YdirNumber*8 
#define Col XdirNumber*16 

#define H138_A_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_5);
#define H138_A_H			 GPIO_SetBits(GPIOF , GPIO_Pin_5);
#define H138_B_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_3);
#define H138_B_H			 GPIO_SetBits(GPIOF , GPIO_Pin_3);
#define H138_C_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_1);
#define H138_C_H			 GPIO_SetBits(GPIOF , GPIO_Pin_1);
#define H138_D_L  		GPIO_ResetBits(GPIOF , GPIO_Pin_0);
#define H138_D_H  		GPIO_SetBits(GPIOF , GPIO_Pin_0);

#define MBI5026_OE_L   GPIO_ResetBits(GPIOG , GPIO_Pin_13); 
#define MBI5026_OE_H   GPIO_SetBits(GPIOG , GPIO_Pin_13);

#define MBI5026_SDI1_L			 GPIO_ResetBits(GPIOG , GPIO_Pin_15);
#define MBI5026_SDI1_H			 GPIO_SetBits(GPIOG , GPIO_Pin_15);
#define MBI5026_SDI2_L			 GPIO_ResetBits(GPIOG , GPIO_Pin_8);
#define MBI5026_SDI2_H		   GPIO_SetBits(GPIOG , GPIO_Pin_8);
#define MBI5026_SDI3_L			 GPIO_ResetBits(GPIOG , GPIO_Pin_2);
#define MBI5026_SDI3_H			 GPIO_SetBits(GPIOG , GPIO_Pin_2);
#define MBI5026_SDI4_L			 GPIO_ResetBits(GPIOE , GPIO_Pin_14);
#define MBI5026_SDI4_H			 GPIO_SetBits(GPIOE , GPIO_Pin_14);
#define MBI5026_SDI5_L			 GPIO_ResetBits(GPIOE , GPIO_Pin_15);
#define MBI5026_SDI5_H			 GPIO_SetBits(GPIOE , GPIO_Pin_15);
#define MBI5026_SDI6_L			 GPIO_ResetBits(GPIOF , GPIO_Pin_12);
#define MBI5026_SDI6_H			 GPIO_SetBits(GPIOF , GPIO_Pin_12);
#define MBI5026_SDI7_L 		   GPIO_ResetBits(GPIOE , GPIO_Pin_5);
#define MBI5026_SDI7_H			 GPIO_SetBits(GPIOE , GPIO_Pin_5);

#define MBI5026_CLK_L  GPIO_ResetBits(GPIOG , GPIO_Pin_11);
#define MBI5026_CLK_H  GPIO_SetBits(GPIOG , GPIO_Pin_11);
#define MBI5026_LE_L	 GPIO_ResetBits(GPIOG , GPIO_Pin_9);
#define MBI5026_LE_H   GPIO_SetBits(GPIOG , GPIO_Pin_9);

/* Private function prototypes -----------------------------------------------*/
void GPIO_Configuration(void);
void NVIC_Configuration(void);
void TIM_Configuration(void);
void Clean(void);
void Light(void);
void Delay (uint32_t nCount);



void Drow_point(int x,int y,unsigned char dat);
void Drow_line(int x1,int y1,int x2,int y2,int dat);
void square_clock(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t mod,uint8_t speed);
void square_rim(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t speed);
void square_door(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t mod,uint8_t speed);

void Drow_circle(int xc,int yc,int r,int mod,int c );

void Drow_picture_all(unsigned char *p);
void Dorw_bmp(int xc,int yc,uint8_t w,uint8_t h,uint8_t *p, uint8_t mod);



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
	//Drow_line(0,0,0,112,1);
	//Drow_line(0,0,55,0,1);
	//Drow_line(55,0,55,112,1);
	//Drow_line(0,111,55,111,1);
	//Drow_picture_all(Pic1);
	Dorw_bmp(5,10,24,30,Pic2,1);
	//disBuff[0][12]=0x80;
	//disBuff[1][12]=0x80;
	//disBuff[2][12]=0x80;
	//disBuff[3][12]=0x80;
	//disBuff[4][12]=0x80;
	//disBuff[5][12]=0x80;
	//disBuff[6][12]=0x80;
	//disBuff[7][12]=0x80;
	
    /* Infinite loop */
    while (1)
		{
		//编写程序更新显示库disBuff数组；
		/*	for(i=0; i<Row ; i++)
				{
						for(j=0;j<Col/8;j++)
						{
							disBuff[i][j]=0x80;
							delay_ms(100);
							for(m=0;m<8;m++)
							{
								disBuff[i][j]=disBuff[i][j]>>1;
								delay_ms(100);
			          
							}							
						}
				}*/
			
			/*for(i=0;i<Row;i++)
			{
				Drow_point(i,96,1);
			}*/
			
		/*	for(i=0;i<10;i++)
			{
				Drow_circle(28,56,10+i,0,1,20);
				delay_ms(10);
			}*/
			//square_clock(0,0,56,111,1,8);
		//	delay_ms(1000);
			//square_clock(0,0,56,111,0,8);
			//delay_ms(1000);
			//Drow_circle(28,56,20,1,1,20);
			//square_rim(0,0,55,111,20);
			//square_door(32,3,46,18,0,80);
			//square_door(0,0,55,111,1,80);
			//Drow_line(55,96,55,0,1);
			//Drow_line(11,0,11,97,1);
			//Drow_line(19,0,19,97,1);
			//Drow_line(27,0,27,97,1);
			//Drow_line(35,0,35,97,1);
			//Drow_line(43,0,43,97,1);
			//Drow_line(51,0,51,97,1);
			/*Drow_point(0,0,1);
			Drow_point(0,96,1);
			Drow_point(8,96,1);
			Drow_point(16,96,1);
			Drow_point(24,96,1);
			Drow_point(32,96,1);
			Drow_point(40,96,1);
			Drow_point(48,96,1);
				Drow_point(55,0,1);
			Drow_point(55,96,1);
			 Drow_point(27,55,1);*/
				//Drow_picture_all(Pic1);
			  // Light();
			//   delay_ms(1000);
			//	 Clean();
			//   delay_ms(500);
			
    }

}

/*******************************************************************************
* Function Name  : Dorw_bmp
* Description    : 绘制圆
* Input          : xc、yc贴图左上角位置。w，h为图片宽高。p位图片数组。mod为1时贴图，为0时删图
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/

void Dorw_bmp(int xc,int yc,uint8_t w,uint8_t h,uint8_t *p , uint8_t mod)
{
	 //uint16_t psize= w*h;
	 uint16_t i,j,m;
	 uint8_t data;
	 if(w+yc<0||h+xc<0||yc>Col||xc>Row)
	 {
		 return;
	 }
	 for(i=0;i<h;i++)
		for(j=0;j<w/8;j++)
		{
			if(mod)
				{
					//disBuff[i][j]=*(p+i*((yc+w)<Col?w:(Col-yc))+j);
					data=*(p+i*(w/8)+j);
					for(m=0;m<8;m++)
					{
								Drow_point(xc+i,yc+j*8+m,((data&0x80)==0?0:1));
								data<<=1;
					}	
				}
				else
				{			
					for(m=0;m<8;m++)
						{
								Drow_point(xc+i,yc+m,0);
						}
				}
		}
}


/*******************************************************************************
* Function Name  : Drow_picture_all
* Description    : 绘制图片
* Input          : 绘制图片的数组地址
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void Drow_picture_all(unsigned char *p)
{
	unsigned char i,j;
	for(i=0; i<Row ; i++)
	{
		for(j=0;j<Col/8;j++)
		{
			disBuff[i][j]=*(p+i*(Col/8)+j);
		}
	}
}


/*******************************************************************************
* Function Name  : Drow_circle
* Description    : 绘制圆
* Input          : x1,y1,圆心，r半径。 mod 扫描方式. c,1为画圆，0为擦除圆，speed画圆速度
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/

void _draw_circle_8(int xc, int yc, int x, int y, unsigned char c)   
{    
   
	    Drow_point(xc + x, yc + y, c);    
	    Drow_point(xc - x, yc + y, c);    
	    Drow_point(xc + x, yc - y, c);   
	    Drow_point(xc - x, yc - y, c);    
			Drow_point(xc + y, yc + x, c);   
	    Drow_point(xc - y, yc + x, c);    
	    Drow_point(xc + y, yc - x, c);    
	    Drow_point(xc - y, yc - x, c);    
}       

void Drow_circle(int xc,int yc,int r,int mod,int c )
{
	  //xc、yc为圆心坐标，
	   int x = 0, y = r, yi, d;   
		//int x = 0, y = r, yi ; 
	 // float d=0.0;
	if(xc + r < 0 || xc - r >= Row || yc + r < 0 || yc - r >= Col)   
	    {  
	        return;  
	    }  
			
         // d = 3 - 2 * r;    
					//d=1.25-r;
			   d=1-r;
	 /*   if(mod)  
	    {    
	        // 画实心圆  
	        while(x <= y)   
	        {    
	            for(yi = x; yi <= y; yi ++)    
	            {  
	                _draw_circle_8( xc, yc, x, yi, c);    
	            }  
             if(d < 0)   
	            {    
	                d = d + 4 * x + 6;    
	            }   
	            else   
	            {    
	                d = d + 4 * (x - y) + 10;    
	                y --;    
	            }    
	  
	            x++;    
	        }    
	    }   
	    else   
	    {    
	        // 画空心圆    
	        while (x <= y)   
	        {    
	            _draw_circle_8(xc, yc, x, y, c);    
	  
	            if(d < 0)   
	            {    
	                d = d + 4 * x + 6;    
	            }   
	            else   
	            {    
	                d = d + 4 * (x - y) + 10;    
	                y --;    
	            }    
	  
	            x ++;    
	        }    
	    } */
			 if(mod)  
	    {    
	        // 画实心圆  
	        while(x <= y)   
	        {    
	            for(yi = x; yi <= y; yi ++)    
	            {  
	                _draw_circle_8( xc, yc, x, yi, c);    
	            }  
             if(d < 0)   
	            {    
	                d = d + 2 * x + 3;    
	            }   
	            else   
	            {    
	                d = d + 2 * (x - y) + 5;    
	                y --;    
	            }    
	  
	            x++;    
	        }    
	    }   
	    else   
	    {    
	        // 画空心圆    
	        while (x <= y)   
	        {    
	            _draw_circle_8(xc, yc, x, y, c);    
	  
	            if(d < 0)   
	            {    
	                d = d + 2 * x + 3;    
	            }   
	            else   
	            {    
	                d = d + 2 * (x - y) + 5;    
	                y --;    
	            }    
	  
	            x ++;    
	        }    
	    } 
}   



/*******************************************************************************
* Function Name  : square_door
* Description    : 矩形范围开门
* Input          : x1,y1,x2,y2正方形对角坐标，左上角为1顺时针方向 ,  mod 扫描方式 0是左边开门，1是中间往两边开 .   speed扫描速度
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/

void square_door(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t mod,uint8_t speed)
{
	uint8_t i=0;
	if(mod==0)
	{
		for(i=0;i<(y2-y1)+1;i++)
		{
			Drow_line(x1,y1+i,x2,i+y1,1);
			delay_ms(speed);
		}
	}
	if(mod==1)
	{
		uint8_t midx,midy;
		midx=x1+(x2-x1)/2;
		midy=y1+(y2-y1)/2;
		for(i=0;i<((y2-y1)/2)+1;i++)
		{
			Drow_line(x1,midy+i,x2,midy+i,1);
			Drow_line(x1,midy-i,x2,midy-i,1);
			delay_ms(speed);
		}
	}
}

/*******************************************************************************
* Function Name  : square_rim
* Description    : 矩形轮廓扫描
* Input          : x1,y1,x2,y2矩形对角坐标，左上角为1顺时针方向 , speed扫描速度
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/

void square_rim(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t speed)
{
	uint8_t i=0;
	for(i=0;i<(y2-y1)+1;i++)
	{
		Drow_line(x1,y1,x1,i+y1,1);
		delay_ms(speed);
	}
	for(i=0;i<(x2-x1)+1;i++)
	{
		Drow_line(x1,y2,i+x1,y2,1);
		delay_ms(speed);
	}
	for(i=0;i<(y2-y1)+1;i++)
	{
		Drow_line(x2,y2,x2,y2-i,1);
		delay_ms(speed);
	}
	for(i=0;i<(x2-x1)+1;i++)
	{
		Drow_line(x2,y1,x2-i,y1,1);
		delay_ms(speed);
	}
}


/*******************************************************************************
* Function Name  : square_clock
* Description    : 矩形轮廓以钟表扫描方式填充
* Input          : x1,y1,x2,y2正方形对角坐标，左上角为1顺时针方向 ,  mod 扫描方式，1为填充扫描，0为指针扫描 .   speed扫描速度
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void square_clock(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t mod,uint8_t speed)
{
	uint8_t midx,midy,i;
	midx=x1+(x2-x1)/2;
	midy=y1+(y2-y1)/2;
		    for(i=0; i<(y2-y1)+1 ; i++)
				{
					 Drow_line(midx,midy,x1,i+y1,1);
					if(mod==0)
					{
						delay_ms(speed);
						Drow_line(midx,midy,x1,i+y1,0);
					}
					 delay_ms(speed);
				}
				
				for(i=0; i<(x2-x1)+1 ; i++)
				{
					 Drow_line(midx,midy,i+x1,y2,1);
					if(mod==0)
						{
							delay_ms(speed);
							Drow_line(midx,midy,i+x1,y2,0);
						}
					 delay_ms(speed);
				}
				
				for(i=0; i<(y2-y1)+1 ; i++)
				{
					 Drow_line(midx,midy,x2,y2-i,1);
					if(mod==0)
						{
							delay_ms(speed);
							Drow_line(midx,midy,x2,y2-i,0);
						}
					 delay_ms(speed);
				}
				
	      for(i=0; i<(x2-x1)+1 ; i++)
				{
					 Drow_line(midx,midy,x2-i,y1,1);
					if(mod==0)
						{
							delay_ms(speed);
							Drow_line(midx,midy,x2-i,y1,0);
						}
					 delay_ms(speed);
				}
}

/*******************************************************************************
* Function Name  : Line_move
* Description    : 线段移动   水平垂直移动
* Input          : x1,y1线段的头坐标。x2，y2线段运动终点坐标。l：线长度。h：线段宽度。speed：移动速度
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/

void Line_move(int x1,int y2,uint8_t l,uint8_t h,uint8_t speed)
{
	
}



/*******************************************************************************
* Function Name  : Drow_point
* Description    : 绘制点
* Input          : 要绘制点的x，y坐标，要绘制的值dat,1为亮
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void Drow_point (int x,int y,unsigned char dat)
{
	if(x<0||y<0||x>Row||y>Col)
	{
		return;
	}
	else{
		if(dat==1)disBuff[x][y/8]|=0x80>>(y%8);
		else disBuff[x][y/8]&=~(0x80>>(y%8));		
	}
}



/*******************************************************************************
* Function Name  : Drow_line
* Description    : 绘制线
* Input          : 起点x1，y1.终点x2，y2. 绘制的值dat，1为亮
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void swap_int(int *a, int *b)   
{    
	    *a ^= *b;    
	    *b ^= *a;    
	    *a ^= *b;    
}

int abs (int x)
{
	return x=x>0?x:-x;
}

void Drow_line(int x1,int y1,int x2,int y2,int dat)
{
		int ix,iy,cx,cy,n2dy,n2dydx,d;
		  int dx = abs(x2 - x1),    
	        dy = abs(y2 - y1),    
	        yy = 0;    
	  
	    if(dx < dy)   
	    {    
	        yy = 1;    
	        swap_int(&x1, &y1);    
	        swap_int(&x2, &y2);    
	        swap_int(&dx, &dy);    
	    }        
	    
					ix = (x2 - x1) > 0 ? 1 : -1;    
	        iy = (y2 - y1) > 0 ? 1 : -1;    
	        cx = x1;   
	        cy = y1;    
	        n2dy = dy * 2;    
	        n2dydx = (dy - dx) * 2;    
	        d = dy * 2 - dx;        
  
	//如果直线与x轴夹角大于45度
	    if(yy)  
	    {   
				while((x2 - x1) > 0?cx != x2+1:cx != x2-1)   
	        {   
						 Drow_point(cy, cx, dat);
	            if(d < 0)   
            {    
	                d += n2dy;    
	            }   
	            else   
	            {    
	                cy += iy;    
	                d += n2dydx;    
	            }           
	  
            cx += ix;    
	        }    
	    }  
	      
	// 如果直线与x轴夹角小于45度
	    else   
	    {   
	        while((x2 - x1) > 0?cx != x2+1:cx != x2-1)   
	        {    
						  Drow_point(cx, cy, dat);
	            if(d < 0)  
	            {    
	                d += n2dy;    
	            }  
	            else   
	            {    
	                cy += iy;    
	                d += n2dydx;    
	            }    
	      
	            cx += ix;    
					}  
			}
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
  
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG | RCC_APB2Periph_GPIOE, ENABLE); 						 
				 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_5| GPIO_Pin_12 ;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 
  GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_15 ;
	GPIO_Init(GPIOG, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5 | GPIO_Pin_14 | GPIO_Pin_15 ;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
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
					
					
					Delay(10);
					MBI5026_CLK_H;
				
					Delay(10);
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
		 Delay(50);
		 MBI5026_LE_H;    //锁存
		 Delay(50);
		 MBI5026_LE_L;   
		 Delay(50);
		 HC138_display(linecount);
		// Delay(5);
		 MBI5026_OE_L;
		 Delay(50);
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

