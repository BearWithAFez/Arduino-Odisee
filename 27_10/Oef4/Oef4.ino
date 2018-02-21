#include <TM1636.h>
#include <Wire.h>
#include <TimerOne.h>
#define K1  9
#define K2  10
#define K3  11
#define YEAR        13
#define MONTH       11
#define DAY         21
#define WEEK        4
#define PINTEMP     A0
#define I2CADDR     0x68

int8_t a[4] = {2,1,18,12};
int swap = 0;
bool showTemp = false;
int hour = 0;
int minu = 0;
int sec = 0;
bool flag = false;
TM1636 tm1636(7,8);
bool showDoublePoint = false;

void setup() {
  // put your setup code here, to run once:
  tm1636.init();
  tm1636.display(a);
  tm1636.point(true);
  Wire.begin();
  pinMode ( K1 , INPUT_PULLUP );
  pinMode ( K2 , INPUT_PULLUP ); 
  pinMode ( K3 , INPUT_PULLUP ); 
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);

   Timer1.initialize (500000); //aantal µs voor interupt. 1000= 1ms. 1000000=1s.
   Timer1.attachInterrupt(timerIsr);
};

void timerIsr () {  
  showDoublePoint = (!showTemp && (swap%2 == 0));
  swap++;
}

void pciSetup ( byte pin ){
  * digitalPinToPCMSK ( pin ) |= bit (digitalPinToPCMSKbit ( pin ) ) ; // enable pin
  PCIFR |= bit ( digitalPinToPCICRbit ( pin ) ) ; // clear any outstanding interrupt
  PCICR |= bit ( digitalPinToPCICRbit ( pin ) ) ; // enable interrupt for the group
}

ISR ( PCINT0_vect ){  
  if(!digitalRead(K1)){
    while(!digitalRead(K1)){//antiDender
    }
    minu++;
  }
  if(!digitalRead(K2)){
    while(!digitalRead(K2)){//antiDender
    }
    hour--;
  }
  if(!digitalRead(K3)){
    while(!digitalRead(K3)){//antiDender
    }
    hour++;
    
  }
  showTemp=false;
  swap = 0;
  a[0]=hour/10;
  a[1]=hour%10;
  a[2]=minu/10;
  a[3]=minu%10;
  tm1636.display(a);
  flag = true;
}

void loop() {
  if(flag){            
    setTime(hour, minu, sec +1);    
    flag = false;
  }
  hour = getHour();
  minu = getMin();
  sec =  getSec();
  if(!showTemp){
    a[0]=hour/10;
    a[1]=hour%10;
    a[2]=minu/10;
    a[3]=minu%10;
  }
  else{
    int temp = getTemp();
    a[0] = temp/10;
    a[1] = temp%10;
    a[2] = 18;
    a[3] = 12;
    tm1636.point(false);
  }
  if(swap == 4){
    swap =0;
    showTemp = !showTemp;
  } 
  tm1636.point(showDoublePoint);
  tm1636.display(a);
}

int decToBcd(int val)
{
    return ( (val/10*16) + (val%10) );
}

int bcdToDec(int val)
{
    return ( (val/16*10) + (val%16) );
}

void setTime(int h, int m, int s)
{

    if(h > 24 || h < 0)return;
    if(m > 59 || m < 0)return;
    if(s > 59 || m < 0)return;

    Wire.beginTransmission(I2CADDR);
    Wire.write((int)0x00);
    Wire.write(decToBcd(sec));                              // 0 to bit 7 starts the clock
    Wire.write(decToBcd(m));
    Wire.write(decToBcd(h) | 0x40);                             // If you want 12 hour am/pm you need to set
                                                            // bit 6 (also need to change readDateDs1307)
    Wire.write(decToBcd(WEEK));
    Wire.write(decToBcd(DAY));
    Wire.write(decToBcd(MONTH));
    Wire.write(decToBcd(YEAR));
    Wire.endTransmission();
}

void getTime(int *hour, int *min, int *sec, int *ampm)
{
    Wire.beginTransmission(I2CADDR);
    Wire.write((int)0x00);
    Wire.endTransmission();
    Wire.requestFrom(I2CADDR, 7);

    int tmp = 0;

    *sec  = bcdToDec(Wire.read() & 0x7f);
    *min  = bcdToDec(Wire.read());
    *hour = bcdToDec(Wire.read() & 0x3f);                   // Need to change this if 12 hour am/pm
    tmp   = bcdToDec(Wire.read());
    tmp   = bcdToDec(Wire.read());
    tmp   = bcdToDec(Wire.read());
    tmp   = bcdToDec(Wire.read());

    *ampm = *hour & 0x20;
    *hour = *hour & 0x1f;
}

int getHour()
{
    int h, m, s, ampm;
    getTime(&h, &m, &s, &ampm);
    return h;
}

int getSec()
{
    int h, m, s, ampm;
    getTime(&h, &m, &s, &ampm);
    return s;
}

int getMin()
{
    int h, m, s, ampm;
    getTime(&h, &m, &s, &ampm);
    return m;
}

int getTemp()                                   // get temperature
    {
        int a = 0;

        for(int i=0; i<32; i++)
        {
            a+=analogRead(PINTEMP);
        }
        
        a >>= 5;
        
        float resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
        float temperature=1/(log(resistance/10000)/3975+1/298.15)-273.15;//convert to temperature via datasheet ;
       
        return temperature;
    }
