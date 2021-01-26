// hs4qwc
//26/7/2557


#include <16F84A>

#fuses NOWDT,NOPROTECT,HS
#use delay(clock=4000000)

#use fast_io(a)
#use fast_io(b)



/* ตั้งชื่อ แทนตำแหน่ง ADDRESS  หรือ รีจิสตอร์ใช้งาน*/

#byte PA = getenv("sfr:PORTA")
#byte PB = getenv("sfr:PORTB")


#bit SW1=PA.4
#bit CH1=PA.0
#bit CH2=PA.1
#bit CH3=PA.2
#bit CH4=PA.3
short F_SW1 ;
/*    ประกาศตัวแปร */

int a;
void main()
{
        /*  เซ็ทค่าเริ่มต้น  */
        set_tris_a(0x10);  // กำหนดให้ PORT a เป็น OUTPUT หมดทั้ง 8 บิท
        set_tris_b(0);  // กำหนดให้ PORT b เป็น inPUT หมดทั้ง 8 บิท
        a=0;       
        PB=0;
        CH1=0;CH2=0;CH3=0;CH4=0;     
         /*  ส่วนทำงาน */
  
  write_eeprom(0,a);
  a= read_eeprom(0);
  for(;;)
   {
         //----  sw1  -----//                        
          if(!SW1&&!F_SW1)
          { 
            if(a<4)a++; 
            F_SW1 = 1;
            delay_ms(10);
          }  
             if(SW1&&F_SW1)
              {
                F_SW1 = 0;
                delay_ms(10);
              }
      // DATA[]0x0c,0xB6,0x9E,0xcc
          if(a==1){;CH1=1;CH2=0;CH3=0;CH4=0;}
          if(a==2){;CH1=0;CH2=1;CH3=0;CH4=0;}    
          if(a==3){;CH1=0;CH2=0;CH3=1;CH4=0;}
          if(a==4){;CH1=0;CH2=0;CH3=0;CH4=1;}
          if(a==4)a=0;

              
   }           /* END WHILE  */

} /* END MAIN */



