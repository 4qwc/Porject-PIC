#include <18f252.h>
#fuses NOWDT,NOPROTECT,NOLVP,XT
#use delay(clock=4000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)

/* ตั้งชื่อ แทนตำแหน่ง ADDRESS  หรือ รีจิสตอร์ใช้งาน*/

#byte PA = getenv("sfr:PORTA")
#byte PB = getenv("sfr:PORTB")
#byte PC = getenv("sfr:PORTC")

#BIT A0 = PA.0
#BIT A1 = PA.1
#BIT MOTOR1 = PA.2
#BIT MOTOR2 = PA.3

#bit C1 = PB.0
#bit C2 = PB.1
#bit C3 = PB.2
#bit R1 = PB.3
#bit R2 = PB.4
#bit R3 = PB.5
#bit R4 = PB.6
#bit R5 = PB.7

#BIT CH1 = PC.0
#BIT CH2 = PC.1
#BIT CH3 = PC.2
#BIT CH4 = PC.3
#BIT CH5 = PC.4
#BIT CH6 = PC.5
#BIT CH7 = PC.6
#BIT CH8 = PC.7


/*    ประกาศตัวแปร */
//int a,b,c;

short F_C1,F_C2,F_C3, F_A0,F_A1,F_R1,F_R2,F_R3,F_R4,F_R5;
 
void main()
{
        /*  เซ็ทค่าเริ่มต้น  */
        set_tris_a(0x03);
        set_tris_b(0xff);   // กำหนดให้ PORT B เป็น OUTPUT หมดทั้ง 8 บิท
        set_tris_c(0);
        
        PC=0;        //------------กำหนดค่าเริ่มต้น portC//-----------------------
        MOTOR1=0;
        MOTOR2=0;
        
         //---------*  ส่วนทำงาน *-----------------------/
        while(true)//----for(;;)----//
         {
                     
                 if(!C1&&!F_C1)
                  { 
                      CH1=~CH1;
                     F_C1=1;delay_ms(10);
                  }  if(C1&&F_C1){F_C1=0;delay_ms(10);}
                                       
            else if(!C2&&!F_C2)
                  { 
                     CH2=~CH2;
                     F_C2=1;delay_ms(10);
                  }if (C2&&F_C2){F_C2=0;delay_ms(10);}
                  
            else if(!C3&&!F_C3)
                  {
                      CH3=~CH3;
                      F_C3=1;delay_ms(10);
                  }if(C3&&F_C3){F_C3=0;delay_ms(10);}
           
            else if(!R1&&!F_R1)
                  {
                      CH4=~CH4;
                      F_R1=1;delay_ms(10);
                  }if(R1&&F_R1){F_R1=0;delay_ms(10);}
                  
            else if(!R2&&!F_R2)
                  {
                      CH5=~CH5;
                      F_R2=1;delay_ms(10);
                  }if(R2&&F_R2){F_R2=0;delay_ms(10);}
                  
            else if(!R3&&!F_R3)
                  {
                      CH6=~CH6;
                      F_R3=1;delay_ms(10);
                  }if(R3&&F_R3){F_R3=0;delay_ms(10);}
                  
            else if(!R4&&!F_R4)
                  {
                      CH7=~CH7;
                      F_R4=1;delay_ms(10);
                  }if(R4&&F_R4){F_R4=0;delay_ms(10);}
                  
            else if(!R5&&!F_R5)
                  {
                      CH8=~CH8;
                      F_R5=1;delay_ms(10);
                  }if(R5&&F_R5){F_R5=0;delay_ms(10);}
                  
            else if(!A0&&!F_A0)
                  {
                      MOTOR1=~MOTOR1;
                      MOTOR2=0;
                      F_A0=1;delay_ms(10);
                  }if(A0&&F_A0){F_A0=0;delay_ms(10);}
                  
            else if(!A1&&!F_A1)
                  {
                      MOTOR2=~MOTOR2;
                      MOTOR1=0;
                      F_A1=1;delay_ms(10);
                  }if(A1&&F_A1){F_A1=0;delay_ms(10);}
         }
}
