String meet[3] = { "17.89;9.38E-3;STABLE;" , "17.94;9.28E-3;STABLE;" , "17.32;9.29E-2;UNSTABLE;" };
String sub[3] = {"", "", ""};
float gemStroom = 0;
int stabiele = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  Serial.println("Spanningen");
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){      
      sub[j] = getValue(meet[i], ';', j);
    }
    Serial.println(sub[0].toFloat(),1);
    
    //voor meetwaarde de Stroom oplsaan indien...
    if(sub[2] == "STABLE;"){
      stabiele++;
      gemStroom += sub[1].toFloat();
    }
  }
  //delen door opgeslagen
  gemStroom /= stabiele;
  
  Serial.print("Gemmidelde Stabiele Stroom: ");
  Serial.println(gemStroom,5);
  Serial.print("aantal Stable: ");
  Serial.println(stabiele);
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return (found>index ? data.substring(strIndex[0], strIndex[1]) : "");
}

void loop() {
  // put your main code here, to run repeatedly:
}
