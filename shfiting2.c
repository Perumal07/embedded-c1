#include<htc.h>
#define _XTAL_FREQ 20000000
__CONFIG(0X1F7A);
void delay();
int main()
{
 int i;
 char k=0x08;
 char l=0x10;
 TRISB=0;
while(1)
{
 for(i=0;i<3;i++)
 {
  PORTB=(k+l);
  delay();
  k=k>>1;
  l=l<<1;
 }
for(i=0;i<3;i++)
 {
    PORTB=(k+l);
    delay();
    k=k<<1;
    l=l>>1;
 }
}
}
  
void delay()
 {
  int i;
  TMR1CS=0;
  T1CKPS0=1;
  T1CKPS1=1;
  TMR1ON=1;
  for(i=0;i<10;i++)
  {
    TMR1H=0x0B;
    TMR1L=0xDB;
     while(!TMR1IF);
     TMR1IF=0;
  }
}