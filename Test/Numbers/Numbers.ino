void pin(int pin,bool state,bool Display = false,int Time = 0){
  if(state>2){
    Serial.println("not exist pin state 2 or pin greater than 13");
  }else{
    pinMode(pin,OUTPUT);
    switch(state){
      case 0:
        if(Time!=0){
          if(Display){
            digitalWrite(pin,HIGH);
            delay(Time);
            digitalWrite(pin,LOW);
          }else{
            digitalWrite(pin,LOW);
            delay(Time);
            digitalWrite(pin,HIGH);
          }
        }else{
          if(Display){
            digitalWrite(pin,HIGH);
          }else{
            digitalWrite(pin,LOW);
          }
        }
      break;
      case 1:
        if(Time!=0){
          if(Display){
            digitalWrite(pin,LOW);
            delay(Time);
            digitalWrite(pin,HIGH);
            delay(Time);
          }else{
            digitalWrite(pin,HIGH);
            delay(Time);
            digitalWrite(pin,LOW);
            delay(Time);
          }
        }else{
          if(Display){
            digitalWrite(pin,LOW);
          }else{
            digitalWrite(pin,HIGH);
          }
        }
        break;
    }
  }
}
int num(int num,int Delay = 0){
  const int pinUse[] = {12,11,10,9,8,7,6};
  switch(num){
    case 0:
      pin(pinUse[0],1,true);
      pin(pinUse[1],1,true);
      pin(pinUse[2],1,true);
      pin(pinUse[3],0,true);
      pin(pinUse[4],1,true);
      pin(pinUse[5],1,true);
      pin(pinUse[6],1,true);
    break;
    case 1:
      pin(pinUse[0],1,true);
      pin(pinUse[1],0,true);
      pin(pinUse[2],0,true);
      pin(pinUse[3],0,true);
      pin(pinUse[4],0,true);
      pin(pinUse[5],0,true);
      pin(pinUse[6],1,true);
    break;
    case 2:
      pin(pinUse[0],1,true);
      pin(pinUse[1],1,true);
      pin(pinUse[2],0,true);
      pin(pinUse[3],1,true);
      pin(pinUse[4],1,true);
      pin(pinUse[5],1,true);
      pin(pinUse[6],0,true);
    break;
    case 3:
      pin(pinUse[0],1,true);
      pin(pinUse[1],1,true);
      pin(pinUse[2],0,true);
      pin(pinUse[3],1,true);
      pin(pinUse[4],0,true);
      pin(pinUse[5],1,true);
      pin(pinUse[6],1,true);
    break;
    case 4:
      pin(pinUse[0],1,true);
      pin(pinUse[1],0,true);
      pin(pinUse[2],1,true);
      pin(pinUse[3],1,true);
      pin(pinUse[4],0,true);
      pin(pinUse[5],0,true);
      pin(pinUse[6],1,true);
    break;
    case 5:
      pin(pinUse[0],0,true);
      pin(pinUse[1],1,true);
      pin(pinUse[2],1,true);
      pin(pinUse[3],1,true);
      pin(pinUse[4],0,true);
      pin(pinUse[5],1,true);
      pin(pinUse[6],1,true);
    break;
    case 6:
      pin(pinUse[0],0,true);
      pin(pinUse[1],1,true);
      pin(pinUse[2],1,true);
      pin(pinUse[3],1,true);
      pin(pinUse[4],1,true);
      pin(pinUse[5],1,true);
      pin(pinUse[6],1,true);
    break;
    case 7:
      pin(pinUse[0],1,true);
      pin(pinUse[1],1,true);
      pin(pinUse[2],0,true);
      pin(pinUse[3],0,true);
      pin(pinUse[4],0,true);
      pin(pinUse[5],0,true);
      pin(pinUse[6],1,true);
    break;
    case 8:
      pin(pinUse[0],1,true);
      pin(pinUse[1],1,true);
      pin(pinUse[2],1,true);
      pin(pinUse[3],1,true);
      pin(pinUse[4],1,true);
      pin(pinUse[5],1,true);
      pin(pinUse[6],1,true);
    break;
    case 9:
      pin(pinUse[0],1,true);
      pin(pinUse[1],1,true);
      pin(pinUse[2],1,true);
      pin(pinUse[3],1,true);
      pin(pinUse[4],0,true);
      pin(pinUse[5],1,true);
      pin(pinUse[6],1,true);
    break;
  }
  if(Delay!=0){
    delay(Delay);
  }
}
void setup(){
  
}

void loop(){
  pin(13,1);
  num(0,1000);
  num(1,1000);
  num(2,1000);
  num(3,1000);
  num(4,1000);
  num(5,1000);
  num(6,1000);
  num(7,1000);
  num(8,1000);
  num(9,1000);
  pin(13,0);
  pin(5,1,false,1000);
}
