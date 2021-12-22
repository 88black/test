/**********************ZYWIFI0939C-WIFI机器人实验板例程************************
*  平台：ZYWIFI0939C-WIFI机器人 + Keil U4 + STC89C52
*  名称：ZY-1智能小车参考程序
*  公司：湖南智宇科教设备有限公司                        
/蓝牙模块出厂默认参数：
从机，波特率：9600，N，8，1。配对密码：1234
*  平台：ZYWIFI0939C-WIFI机器人 + Keil U4 + STC89C52
*  名称：ZY-1智能小车参考程序
*  公司：湖南智宇科教设备有限公司
*  淘宝：https://hnzyrobot1688.taobao.com/     
*  网站：www.hnzhiyu.cn	
*  编写：智宇公司研发一部
*  日期：2015-1-15
*  交流:智能车QQ:261339276
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析
*  硬件设置：要有自己动手能力，才能完成实验
*  使用说明：根据下面IO口自己用杜邦线连接各种模块，可以自己修改各种模块IO口
*  视频教程：本小车配套学习C语言详细视频教程，资料统一网盘下载
   重点提示：本程序只做参考，不提供技术支持，请自己研究吸收。
    
	//注意程序只做参考之用，要达到最理想的效果，还需要同学们细心调试。	
	//注意蓝牙模块接线，急性之人经常接错线，烧坏模块，请一定要核对好再通电试验，模块接错线烧坏不保修，不换货的。
	/****************************************************************************
	 硬件连接
	 蓝牙有4条线定义：
	  VCC
      GND
	  TDX
	  RXD
	 把蓝牙插入单片机J7接口中	 --注意不要接错线，否则烧坏蓝牙模块，不保修，不换货。
	****************************************************************************/
#include<AT89x52.H>
#include "LCD1602display.h"
	#include<ZY-4WD_PWM.h>
	#define le     'C'//左转
    #define ri    'D'//右转
	#define up       'A'//前进
    #define down     'B'//后退
	#define stop     'F'//停止
	#define gx       'G'//跟随
	#define csb       'S'//超声波

	#define uint    unsigned int                          //重定义无符号整数类型
    #define uchar   unsigned char                         //重定义无符号字符类型

	char code str[] =  "收到指令，向前!\n";
	char code str1[] = "收到指令，向后!\n";
	char code str2[] = "收到指令，向左!\n";
	char code str3[] = "收到指令，向右!\n";
	char code str4[] = "收到指令，停止!\n";
	char code str5[] = "红外循迹模板\n";
	char code str6[] = "避障模板\n";	
	char code str7[] = "测距模板\n";

	bit  flag_REC=0; 
	bit  flag    =0;  
	

sbit TRIG=P2^1;
sbit ECHO=P2^0;
sbit pwm=P2^6;//PWM信号输出口
	unsigned char  i=0;
	unsigned char  dat=0;
    unsigned char  buff[5]=0; //接收缓冲字节
	uchar code  LedShowData[]={0x03,0x9F,0x25,0x0D,0x99,  //定义数码管显示数据
                            0x49,0x41,0x1F,0x01,0x19};//0,1,2,3,4,5,6,7,8,9
	
	unsigned int S=0 ;
	uchar n,count,angle,left,right;//距离标志位，0.5ms次数，角度标识

	#define ShowPort P0                                   //定义数码管显示端口

uchar Left_Distance;
uchar Right_Distance;
uchar Front_Distance;
/************************************************************************/

void DelayUs2x(uchar t)
{   
	while(--t);
}
void DelayMs(uchar t)
{
	while(t--)
	{
	    //大致延时1mS	
		DelayUs2x(245);
	    DelayUs2x(245);
	}
}
//字符串发送函数
	 void send_str( )
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str[i] != '\0')
	   {
		SBUF = str[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }
	
		  void send_str1( )
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str1[i] != '\0')
	   {
		SBUF = str1[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	

			  void send_str2( )
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str2[i] != '\0')
	   {
		SBUF = str2[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	
	    	
			  void send_str3()
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str3[i] != '\0')
	   {
		SBUF = str3[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	

	      void send_str4()
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str4[i] != '\0')
	   {
		SBUF = str4[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	
	        void send_str5()			//使其循迹模板
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str5[i] != '\0')
	   {
		SBUF = str5[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	 
		
			        void send_str6()			//使其循迹模板
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str6[i] != '\0')
	   {
		SBUF = str6[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	
		
			        void send_str7()			//使其循迹模板
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str7[i] != '\0')
	   {
		SBUF = str7[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	
	    	
	    	
/************************************************************************/
		
		
/**********************************************************************/


#define uchar unsigned char
#define uint  unsigned int
unsigned char disbuff[6]={0};//用于分别放距离的值	
unsigned char code Range[] ="==Range Finder==";//LCD1602显示格式
unsigned char code ASCII[15] ="0123456789CM S";

unsigned char code ASCIIR[13] = "distance:";
unsigned char code ASCIIL[13] = "LMspeed:";
unsigned char code table[]="Distance:001.0cm";
unsigned char code table1[]="!!! Out of range";
unsigned  int  time3=0;
uchar n,count,angle,left,right;//距离标志位，0.5ms次数，角度标识

uchar Left_Distance;
uchar Right_Distance;
uchar Front_Distance;


sbit led1=P0^0;

void  Display_LCD()
{
		led1=1;
    DisplayOneChar(0, 1, ASCIIR[0]);	  //
	  DisplayOneChar(1, 1, ASCIIR[1]);	  //
	  DisplayOneChar(2, 1, ASCIIR[2]);	  //
	  DisplayOneChar(3, 1, ASCIIR[3]);	  //
	  DisplayOneChar(4, 1, ASCIIR[4]);	  //
	  DisplayOneChar(5, 1, ASCIIR[5]);	  //
	  DisplayOneChar(6, 1, ASCIIR[6]);	  //
	  DisplayOneChar(7, 1, ASCIIR[7]);	  //
	  DisplayOneChar(8, 1, ASCIIR[8]);	  //

	  DisplayOneChar(9, 1, ASCII[disbuff[0]]);	  //右电机速度值百位
	  DisplayOneChar(10, 1, ASCII[disbuff[1]]);	  //右电机速度值十位
	  DisplayOneChar(11, 1, ASCII[disbuff[2]]);	   //右电机速度值个位
	  DisplayOneChar(12, 1, ASCII[10]);	   //
	  DisplayOneChar(13, 1, ASCII[11]);	   //

}
/*------------------------------------------------
                    定时器01初始化
------------------------------------------------*/
void TIM0init(void)
{
	TMOD|=0x11;//定时器1工作方式1 (超声波)，定时器0舵机
	TH1=0x00;    
  TL1=0x00;  //超声波
  TH0=(65536-100)/256;
	TL0=(65536-100)%256;
    ET1=1;
    ET0=1;
    EA=1;
    TR0=1;//定时器开始
    IE=0x92;
}
void chaoshengbo()
{
	  TRIG=1;//触发信号是高电平脉冲，宽度大于10us
    DelayUs2x(10);
    TRIG=0;
    while(!ECHO);//等待高电平
    TR1=1;
    while(ECHO);//等待低电平
    TR1=0;
    S=TH1*256+TL1;//取出定时器值高8位和低8位合并
    S=S/58;       //为什么除以58等于厘米，  Y米=（X秒*344）/2
                  // X秒=（ 2*Y米）/344 -> X秒=0.0058*Y米 -> 厘米=微秒/58 

	disbuff[0]=S/100;		    //距离值百位
	disbuff[1]=S%100/10;		//距离值十位
    disbuff[2]=S%100%10;		//距离值个位

    if(S>=25)
    {n=1;}
    if(S<25)
    {n=0;}
    TH1=0;
    TL1=0;//清除定时器0寄存器中的值
}
/*------------------------------------------------
                    主函数
------------------------------------------------*/
void CSB()
{
	
	Delay1ms(5);//延时片刻
	angle=12;//舵机居中
    count=0;
	//Display_LCD();
    TIM0init();//初始化定时器
    while(1)
    {          
		chaoshengbo();
		Display_LCD();
		Front_Distance = S;
        DelayMs(20);
		
        if(Front_Distance > 30)//如果大于一定距离
        {run();}//前进
        
		if(Front_Distance < 30)//如果小于一定距离
        {
			stoprun();//停车
            
            angle=4;
            count=0;
            DelayMs(400);
            chaoshengbo();
			Display_LCD();
			Right_Distance= S;
            DelayMs(20);

            angle=12;
            count=0;
            DelayMs(400);

            angle=20;
            count=0;
            DelayMs(400);
            chaoshengbo();
			Display_LCD();
			Left_Distance = S;
            DelayMs(20);
          
			angle=12;
            count=0;	
            DelayMs(400);
 			
			
			 if((Left_Distance < 30 ) &&( Right_Distance < 30 ))  //左右两边距离都小于30
   		    {
        		backrun();//后退
        		DelayMs(80);
        		leftrun;//左转
        		DelayMs(40);
					}
				else 
				{
					
				if(Left_Distance < Right_Distance)	  //左边距离小于右边的距离
            {
            	rightrun();		   //调用小车右转	函数
            	DelayMs(100);
        	}
            
				if(Left_Distance >= Right_Distance)
            {
           		leftrun();		  //调用小车左转  函数
            	DelayMs(100);
            }
				
				}					
					
		}
	if(buff[2]!=csb) return;
	}
		return;
}


void CSBCJ()
{
	Delay1ms(5);//延时片刻       
	chaoshengbo();
	Display_LCD();
	DelayMs(20);	
}
/*------------------------------------------------
                 定时器中断子程序
------------------------------------------------*/
void Time0_0(void) interrupt 3
{
	ECHO=0;
}
void Time1_Int() interrupt 1//舵机
{
	 TH0=(65536-100)/256;
	 TL0=(65536-100)%256;
	 if(count<angle)//判断0.5ms次数是否小于角度标识
     pwm=1;//确实小于，pwm输出高电平
     else
     pwm=0;//大于则输出低电平
	 count=(count+1);//0.5ms次数加1
  //	count=count%40;//次数始终保持为40即保持周期为20ms
     if(count == 200)   //	保持周期为20ms
	 count = 0;
	 time3++;
	 pwm_val_left++;
	 pwm_val_right++;
	 pwm_out_left_moto();
	 pwm_out_right_moto();
}


     void  GX(void)
	{ 
	while(1)
	 {
     if(Left_1_led==1&&Right_1_led==1)

			  stoprun();	 //调用停止函数	  前面没有光线

			  else
			 {			  
				      if(Left_1_led==1&&Right_1_led==0)	    //右边检测到红外信号
			 	 {
				 	  rightrun();	 //调用小车右转函数
					  delay(20);

			     }
			   
				 	  if(Right_1_led==1&&Left_1_led==0)		//左边检测到红外信号
				  {	  
				      
					  leftrun();	  //调用小车左转函数
					  delay(20);

				  }
				  	 if(Right_1_led==0&&Left_1_led==0)		//两边传感器同时检测到红外
				  {	  
				    run();		    //调用前进函数
					delay(20);		//前进40毫秒
				
				  }
			}	

	  if(buff[2]!=gx) return;
	}		
 	return;  
 }
/************************************************************************/
void sint() interrupt 4	  //中断接收3个字节
{ 
 
    if(RI)	                 //是否接收中断
    {
       RI=0;
       dat=SBUF;
       if(dat=='O'&&(i==0)) //接收数据第一帧
         {
            buff[i]=dat;
            flag=1;        //开始接收数据
         }
       else
      if(flag==1)
     {
      i++;
      buff[i]=dat;
      if(i>=2)
      {i=0;flag=0;flag_REC=1 ;}  // 停止接收
     }
	 }
}
/*********************************************************************/		 
/*--主函数--*/

void Init()
{

		TMOD|=0x11;//定时器1工作方式1 (超声波)，定时器0舵机
		TH1=0x00;    
		TL1=0x00;  //超声波
		TH0=(65536-100)/256;
		TL0=(65536-100)%256;
    ET1=1;
    ET0=1;
    EA=1;
    TR0=1;//定时器开始
    IE=0x92;//中断允许控制寄存亲
	
	
		T2MOD=0x01;//定时器1工作方式1 (超声波)，定时器0舵机
		T2CON = 0x30;
		TH2=0xFd;    
		TL2=0xfd;  //蓝牙
		RCAP2H =0XFF;
		RCAP2L=0xDC;
		SCON=0x50;
		PCON=0x00;
		PS=1;
		TR2=1;
		PT1=0;
    EA=1;
		ES=1; 
//		TMOD=0x20;  
//    TH1=0xFd;  		   //11.0592M晶振，9600波特率
//    TL1=0xFd;
//    SCON=0x50;  
//    PCON=0x00; 
//    TR1=1;
		  
	  EA = 1;			   //开总中断;   
}
	void main(void)
{
	TIM0init();//初始化定时器 
	Init(); 	 
	ShowPort=LedShowData[0];
	Delay1ms(400); //启动等待，等LCM讲入工作状态
	LCMInit(); //LCM初始化
	while(1)							/*无限循环*/
	{ 
		CSBCJ();
	  if(flag_REC==1)				    //
	   {
		flag_REC=0;
		if(buff[0]=='O'&&buff[1]=='N')	//第一个字节为O，第二个字节为N，第三个字节为控制码
		switch(buff[2])
	     {
		    case up :						    // 前进
			  send_str( );
			  run();
			  ShowPort=LedShowData[1]; 
			  break;
		    case down:						// 后退
			  send_str1( );
			  backrun();
			  ShowPort=LedShowData[2]; 
			  break;
		     case le:						// 左转
			   send_str3( );
			  leftrun();
			  ShowPort=LedShowData[3];  
			  break;
		      case ri:						// 右转
			  send_str2( );
			  rightrun();
			  ShowPort=LedShowData[4];
			  break;
		      case stop:						// 停止
			   send_str4( );
			  ShowPort=LedShowData[0];
			  stoprun();
			  break;
			  case  gx:						    //循迹
			   send_str5( );
               ShowPort=LedShowData[5];		    
			   GX();
			  break;
			  case  csb:						    //循迹
			   send_str6( );
               ShowPort=LedShowData[5];		    
			   CSB();
			  break;
			  

	     }
		 }			 
	 }
	}	