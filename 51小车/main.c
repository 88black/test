/**********************ZYWIFI0939C-WIFI������ʵ�������************************
*  ƽ̨��ZYWIFI0939C-WIFI������ + Keil U4 + STC89C52
*  ���ƣ�ZY-1����С���ο�����
*  ��˾����������ƽ��豸���޹�˾                        
/����ģ�����Ĭ�ϲ�����
�ӻ��������ʣ�9600��N��8��1��������룺1234
*  ƽ̨��ZYWIFI0939C-WIFI������ + Keil U4 + STC89C52
*  ���ƣ�ZY-1����С���ο�����
*  ��˾����������ƽ��豸���޹�˾
*  �Ա���https://hnzyrobot1688.taobao.com/     
*  ��վ��www.hnzhiyu.cn	
*  ��д�����˾�з�һ��
*  ���ڣ�2015-1-15
*  ����:���ܳ�QQ:261339276
*  ����:11.0592MHZ
*  ˵������ѿ�Դ�����ṩԴ�������
*  Ӳ�����ã�Ҫ���Լ������������������ʵ��
*  ʹ��˵������������IO���Լ��öŰ������Ӹ���ģ�飬�����Լ��޸ĸ���ģ��IO��
*  ��Ƶ�̳̣���С������ѧϰC������ϸ��Ƶ�̳̣�����ͳһ��������
   �ص���ʾ��������ֻ���ο������ṩ����֧�֣����Լ��о����ա�
    
	//ע�����ֻ���ο�֮�ã�Ҫ�ﵽ�������Ч��������Ҫͬѧ��ϸ�ĵ��ԡ�	
	//ע������ģ����ߣ�����֮�˾����Ӵ��ߣ��ջ�ģ�飬��һ��Ҫ�˶Ժ���ͨ�����飬ģ��Ӵ����ջ������ޣ��������ġ�
	/****************************************************************************
	 Ӳ������
	 ������4���߶��壺
	  VCC
      GND
	  TDX
	  RXD
	 ���������뵥Ƭ��J7�ӿ���	 --ע�ⲻҪ�Ӵ��ߣ������ջ�����ģ�飬�����ޣ���������
	****************************************************************************/
#include<AT89x52.H>
#include "LCD1602display.h"
	#include<ZY-4WD_PWM.h>
	#define le     'C'//��ת
    #define ri    'D'//��ת
	#define up       'A'//ǰ��
    #define down     'B'//����
	#define stop     'F'//ֹͣ
	#define gx       'G'//����
	#define csb       'S'//������

	#define uint    unsigned int                          //�ض����޷�����������
    #define uchar   unsigned char                         //�ض����޷����ַ�����

	char code str[] =  "�յ�ָ���ǰ!\n";
	char code str1[] = "�յ�ָ����!\n";
	char code str2[] = "�յ�ָ�����!\n";
	char code str3[] = "�յ�ָ�����!\n";
	char code str4[] = "�յ�ָ�ֹͣ!\n";
	char code str5[] = "����ѭ��ģ��\n";
	char code str6[] = "����ģ��\n";	
	char code str7[] = "���ģ��\n";

	bit  flag_REC=0; 
	bit  flag    =0;  
	

sbit TRIG=P2^1;
sbit ECHO=P2^0;
sbit pwm=P2^6;//PWM�ź������
	unsigned char  i=0;
	unsigned char  dat=0;
    unsigned char  buff[5]=0; //���ջ����ֽ�
	uchar code  LedShowData[]={0x03,0x9F,0x25,0x0D,0x99,  //�����������ʾ����
                            0x49,0x41,0x1F,0x01,0x19};//0,1,2,3,4,5,6,7,8,9
	
	unsigned int S=0 ;
	uchar n,count,angle,left,right;//�����־λ��0.5ms�������Ƕȱ�ʶ

	#define ShowPort P0                                   //�����������ʾ�˿�

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
	    //������ʱ1mS	
		DelayUs2x(245);
	    DelayUs2x(245);
	}
}
//�ַ������ͺ���
	 void send_str( )
                   // �����ִ�
    {
	    unsigned char i = 0;
	    while(str[i] != '\0')
	   {
		SBUF = str[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	   }	
    }
	
		  void send_str1( )
                   // �����ִ�
    {
	    unsigned char i = 0;
	    while(str1[i] != '\0')
	   {
		SBUF = str1[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	   }	
    }	

			  void send_str2( )
                   // �����ִ�
    {
	    unsigned char i = 0;
	    while(str2[i] != '\0')
	   {
		SBUF = str2[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	   }	
    }	
	    	
			  void send_str3()
                   // �����ִ�
    {
	    unsigned char i = 0;
	    while(str3[i] != '\0')
	   {
		SBUF = str3[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	   }	
    }	

	      void send_str4()
                   // �����ִ�
    {
	    unsigned char i = 0;
	    while(str4[i] != '\0')
	   {
		SBUF = str4[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	   }	
    }	
	        void send_str5()			//ʹ��ѭ��ģ��
                   // �����ִ�
    {
	    unsigned char i = 0;
	    while(str5[i] != '\0')
	   {
		SBUF = str5[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	   }	
    }	 
		
			        void send_str6()			//ʹ��ѭ��ģ��
                   // �����ִ�
    {
	    unsigned char i = 0;
	    while(str6[i] != '\0')
	   {
		SBUF = str6[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	   }	
    }	
		
			        void send_str7()			//ʹ��ѭ��ģ��
                   // �����ִ�
    {
	    unsigned char i = 0;
	    while(str7[i] != '\0')
	   {
		SBUF = str7[i];
		while(!TI);				// �������ݴ���
		TI = 0;					// ������ݴ��ͱ�־
		i++;					// ��һ���ַ�
	   }	
    }	
	    	
	    	
/************************************************************************/
		
		
/**********************************************************************/


#define uchar unsigned char
#define uint  unsigned int
unsigned char disbuff[6]={0};//���ڷֱ�ž����ֵ	
unsigned char code Range[] ="==Range Finder==";//LCD1602��ʾ��ʽ
unsigned char code ASCII[15] ="0123456789CM S";

unsigned char code ASCIIR[13] = "distance:";
unsigned char code ASCIIL[13] = "LMspeed:";
unsigned char code table[]="Distance:001.0cm";
unsigned char code table1[]="!!! Out of range";
unsigned  int  time3=0;
uchar n,count,angle,left,right;//�����־λ��0.5ms�������Ƕȱ�ʶ

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

	  DisplayOneChar(9, 1, ASCII[disbuff[0]]);	  //�ҵ���ٶ�ֵ��λ
	  DisplayOneChar(10, 1, ASCII[disbuff[1]]);	  //�ҵ���ٶ�ֵʮλ
	  DisplayOneChar(11, 1, ASCII[disbuff[2]]);	   //�ҵ���ٶ�ֵ��λ
	  DisplayOneChar(12, 1, ASCII[10]);	   //
	  DisplayOneChar(13, 1, ASCII[11]);	   //

}
/*------------------------------------------------
                    ��ʱ��01��ʼ��
------------------------------------------------*/
void TIM0init(void)
{
	TMOD|=0x11;//��ʱ��1������ʽ1 (������)����ʱ��0���
	TH1=0x00;    
  TL1=0x00;  //������
  TH0=(65536-100)/256;
	TL0=(65536-100)%256;
    ET1=1;
    ET0=1;
    EA=1;
    TR0=1;//��ʱ����ʼ
    IE=0x92;
}
void chaoshengbo()
{
	  TRIG=1;//�����ź��Ǹߵ�ƽ���壬��ȴ���10us
    DelayUs2x(10);
    TRIG=0;
    while(!ECHO);//�ȴ��ߵ�ƽ
    TR1=1;
    while(ECHO);//�ȴ��͵�ƽ
    TR1=0;
    S=TH1*256+TL1;//ȡ����ʱ��ֵ��8λ�͵�8λ�ϲ�
    S=S/58;       //Ϊʲô����58�������ף�  Y��=��X��*344��/2
                  // X��=�� 2*Y�ף�/344 -> X��=0.0058*Y�� -> ����=΢��/58 

	disbuff[0]=S/100;		    //����ֵ��λ
	disbuff[1]=S%100/10;		//����ֵʮλ
    disbuff[2]=S%100%10;		//����ֵ��λ

    if(S>=25)
    {n=1;}
    if(S<25)
    {n=0;}
    TH1=0;
    TL1=0;//�����ʱ��0�Ĵ����е�ֵ
}
/*------------------------------------------------
                    ������
------------------------------------------------*/
void CSB()
{
	
	Delay1ms(5);//��ʱƬ��
	angle=12;//�������
    count=0;
	//Display_LCD();
    TIM0init();//��ʼ����ʱ��
    while(1)
    {          
		chaoshengbo();
		Display_LCD();
		Front_Distance = S;
        DelayMs(20);
		
        if(Front_Distance > 30)//�������һ������
        {run();}//ǰ��
        
		if(Front_Distance < 30)//���С��һ������
        {
			stoprun();//ͣ��
            
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
 			
			
			 if((Left_Distance < 30 ) &&( Right_Distance < 30 ))  //�������߾��붼С��30
   		    {
        		backrun();//����
        		DelayMs(80);
        		leftrun;//��ת
        		DelayMs(40);
					}
				else 
				{
					
				if(Left_Distance < Right_Distance)	  //��߾���С���ұߵľ���
            {
            	rightrun();		   //����С����ת	����
            	DelayMs(100);
        	}
            
				if(Left_Distance >= Right_Distance)
            {
           		leftrun();		  //����С����ת  ����
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
	Delay1ms(5);//��ʱƬ��       
	chaoshengbo();
	Display_LCD();
	DelayMs(20);	
}
/*------------------------------------------------
                 ��ʱ���ж��ӳ���
------------------------------------------------*/
void Time0_0(void) interrupt 3
{
	ECHO=0;
}
void Time1_Int() interrupt 1//���
{
	 TH0=(65536-100)/256;
	 TL0=(65536-100)%256;
	 if(count<angle)//�ж�0.5ms�����Ƿ�С�ڽǶȱ�ʶ
     pwm=1;//ȷʵС�ڣ�pwm����ߵ�ƽ
     else
     pwm=0;//����������͵�ƽ
	 count=(count+1);//0.5ms������1
  //	count=count%40;//����ʼ�ձ���Ϊ40����������Ϊ20ms
     if(count == 200)   //	��������Ϊ20ms
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

			  stoprun();	 //����ֹͣ����	  ǰ��û�й���

			  else
			 {			  
				      if(Left_1_led==1&&Right_1_led==0)	    //�ұ߼�⵽�����ź�
			 	 {
				 	  rightrun();	 //����С����ת����
					  delay(20);

			     }
			   
				 	  if(Right_1_led==1&&Left_1_led==0)		//��߼�⵽�����ź�
				  {	  
				      
					  leftrun();	  //����С����ת����
					  delay(20);

				  }
				  	 if(Right_1_led==0&&Left_1_led==0)		//���ߴ�����ͬʱ��⵽����
				  {	  
				    run();		    //����ǰ������
					delay(20);		//ǰ��40����
				
				  }
			}	

	  if(buff[2]!=gx) return;
	}		
 	return;  
 }
/************************************************************************/
void sint() interrupt 4	  //�жϽ���3���ֽ�
{ 
 
    if(RI)	                 //�Ƿ�����ж�
    {
       RI=0;
       dat=SBUF;
       if(dat=='O'&&(i==0)) //�������ݵ�һ֡
         {
            buff[i]=dat;
            flag=1;        //��ʼ��������
         }
       else
      if(flag==1)
     {
      i++;
      buff[i]=dat;
      if(i>=2)
      {i=0;flag=0;flag_REC=1 ;}  // ֹͣ����
     }
	 }
}
/*********************************************************************/		 
/*--������--*/

void Init()
{

		TMOD|=0x11;//��ʱ��1������ʽ1 (������)����ʱ��0���
		TH1=0x00;    
		TL1=0x00;  //������
		TH0=(65536-100)/256;
		TL0=(65536-100)%256;
    ET1=1;
    ET0=1;
    EA=1;
    TR0=1;//��ʱ����ʼ
    IE=0x92;//�ж�������ƼĴ���
	
	
		T2MOD=0x01;//��ʱ��1������ʽ1 (������)����ʱ��0���
		T2CON = 0x30;
		TH2=0xFd;    
		TL2=0xfd;  //����
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
//    TH1=0xFd;  		   //11.0592M����9600������
//    TL1=0xFd;
//    SCON=0x50;  
//    PCON=0x00; 
//    TR1=1;
		  
	  EA = 1;			   //�����ж�;   
}
	void main(void)
{
	TIM0init();//��ʼ����ʱ�� 
	Init(); 	 
	ShowPort=LedShowData[0];
	Delay1ms(400); //�����ȴ�����LCM���빤��״̬
	LCMInit(); //LCM��ʼ��
	while(1)							/*����ѭ��*/
	{ 
		CSBCJ();
	  if(flag_REC==1)				    //
	   {
		flag_REC=0;
		if(buff[0]=='O'&&buff[1]=='N')	//��һ���ֽ�ΪO���ڶ����ֽ�ΪN���������ֽ�Ϊ������
		switch(buff[2])
	     {
		    case up :						    // ǰ��
			  send_str( );
			  run();
			  ShowPort=LedShowData[1]; 
			  break;
		    case down:						// ����
			  send_str1( );
			  backrun();
			  ShowPort=LedShowData[2]; 
			  break;
		     case le:						// ��ת
			   send_str3( );
			  leftrun();
			  ShowPort=LedShowData[3];  
			  break;
		      case ri:						// ��ת
			  send_str2( );
			  rightrun();
			  ShowPort=LedShowData[4];
			  break;
		      case stop:						// ֹͣ
			   send_str4( );
			  ShowPort=LedShowData[0];
			  stoprun();
			  break;
			  case  gx:						    //ѭ��
			   send_str5( );
               ShowPort=LedShowData[5];		    
			   GX();
			  break;
			  case  csb:						    //ѭ��
			   send_str6( );
               ShowPort=LedShowData[5];		    
			   CSB();
			  break;
			  

	     }
		 }			 
	 }
	}	