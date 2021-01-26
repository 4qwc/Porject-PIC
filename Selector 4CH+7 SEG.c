// hs4qwc
//26/7/2557


#include <16F84A>

#fuses NOWDT,NOPROTECT,HS
#use delay(clock=4000000)

#use fast_io(a)
#use fast_io(b)



/* ��駪��� ᷹���˹� ADDRESS  ���� �ը�ʵ�����ҹ*/

#byte PA = getenv("sfr:PORTA")
#byte PB = getenv("sfr:PORTB")


#bit SW1=PA.4
#bit CH1=PA.0
#bit CH2=PA.1
#bit CH3=PA.2
#bit CH4=PA.3
short F_SW1 ;
/*    ��С�ȵ���� */

int a;
void main()
{
        /*  �緤���������  */
        set_tris_a(0x10);  // ��˹���� PORT a �� OUTPUT ������ 8 �Է
        set_tris_b(0);  // ��˹���� PORT b �� inPUT ������ 8 �Է
        a=0;       
        PB=0;
        CH1=0;CH2=0;CH3=0;CH4=0;     
         /*  ��ǹ�ӧҹ */
  
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



