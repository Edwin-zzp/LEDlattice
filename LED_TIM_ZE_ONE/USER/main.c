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
		//��д���������ʾ��disBuff���飻
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
* Description    : ����Բ
* Input          : xc��yc��ͼ���Ͻ�λ�á�w��hΪͼƬ��ߡ�pλͼƬ���顣modΪ1ʱ��ͼ��Ϊ0ʱɾͼ
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
* Description    : ����ͼƬ
* Input          : ����ͼƬ�������ַ
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
* Description    : ����Բ
* Input          : x1,y1,Բ�ģ�r�뾶�� mod ɨ�跽ʽ. c,1Ϊ��Բ��0Ϊ����Բ��speed��Բ�ٶ�
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
	  //xc��ycΪԲ�����꣬
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
	        // ��ʵ��Բ  
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
	        // ������Բ    
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
	        // ��ʵ��Բ  
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
	        // ������Բ    
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
* Description    : ���η�Χ����
* Input          : x1,y1,x2,y2�����ζԽ����꣬���Ͻ�Ϊ1˳ʱ�뷽�� ,  mod ɨ�跽ʽ 0����߿��ţ�1���м������߿� .   speedɨ���ٶ�
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
* Description    : ��������ɨ��
* Input          : x1,y1,x2,y2���ζԽ����꣬���Ͻ�Ϊ1˳ʱ�뷽�� , speedɨ���ٶ�
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
* Description    : �����������ӱ�ɨ�跽ʽ���
* Input          : x1,y1,x2,y2�����ζԽ����꣬���Ͻ�Ϊ1˳ʱ�뷽�� ,  mod ɨ�跽ʽ��1Ϊ���ɨ�裬0Ϊָ��ɨ�� .   speedɨ���ٶ�
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
* Description    : �߶��ƶ�   ˮƽ��ֱ�ƶ�
* Input          : x1,y1�߶ε�ͷ���ꡣx2��y2�߶��˶��յ����ꡣl���߳��ȡ�h���߶ο�ȡ�speed���ƶ��ٶ�
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/

void Line_move(int x1,int y2,uint8_t l,uint8_t h,uint8_t speed)
{
	
}



/*******************************************************************************
* Function Name  : Drow_point
* Description    : ���Ƶ�
* Input          : Ҫ���Ƶ��x��y���꣬Ҫ���Ƶ�ֵdat,1Ϊ��
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
* Description    : ������
* Input          : ���x1��y1.�յ�x2��y2. ���Ƶ�ֵdat��1Ϊ��
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
  
	//���ֱ����x��нǴ���45��
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
	      
	// ���ֱ����x��н�С��45��
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
* Description    : �����ʾ��
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
			disBuff[i][j]=0x00;   //ȫ��
		}
	}
}


/*******************************************************************************
* Function Name  : Light
* Description    : ȫ��������
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
								disBuff[i][j]=0xFF;   //ȫ��
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
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;		  //����һ���ṹ��
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);	  //ʹ��TIM2����
  TIM_DeInit(TIM2);
  TIM_TimeBaseStructure.TIM_Period=100;		 		  /*�Զ���װ�ؼĴ�
  															�����ڵ�ֵ(����ֵ) 
												            �ۼ� TIM_Period��
															Ƶ�ʺ����һ������
															�����ж� */
  TIM_TimeBaseStructure.TIM_Prescaler= (720 - 1);		 // ʱ��Ԥ��Ƶ��   �ֳ�ʱ��=��Ƶ/����Ƶϵ��-1��10us��100kHz��
  TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;  // ������Ƶ 
  TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;// ���ϼ���ģʽ 
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);/*����TIM_TimeBaseStructure��ָ��
  												  �Ĳ�����ʼ��TIM2��ʱ�������λ */
  TIM_ClearFlag(TIM2, TIM_FLAG_Update);					// �������жϱ�־ 
  TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);				//ʹ���ж�
  TIM_Cmd(TIM2, ENABLE);								// ����ʱ�� 
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
  NVIC_InitTypeDef NVIC_InitStructure;            //����һ���ṹ��	 
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); //�������ȼ���  													
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; //���� TIM2���ȼ�	  
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//�����������ȼ�
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;   //������Ӧ���ȼ�	
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	 //ʹ�����ȼ�
  NVIC_Init(&NVIC_InitStructure);
}





/*******************************************************************************
* Function Name  : MBIsenddata
* Description    : ��������λ���� 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void MBIsenddata(uint8_t k)
{
	  int8_t i;
		uint8_t j;
		uint8_t data1,data2,data3,data4,data5,data6,data7;//�߿�������һ����λ
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
* Description    : �п��Ƴ���
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void HC138_display(uint8_t m)
{
	switch(m)
	{ //��һƬ138
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
	{	//����Ƿ�����������¼�
		TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);
		
     MBIsenddata(linecount);  
		 MBI5026_OE_H;
		 Delay(50);
		 MBI5026_LE_H;    //����
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

