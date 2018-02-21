word temperatuur[]={0x3B47,0x0C87,0x000F,0x0007,0xF387};
float temp = 0;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(bitRead(temperatuur[0],i));
  i++;
}
