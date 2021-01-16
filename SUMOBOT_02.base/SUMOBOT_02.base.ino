// Config
int line = 1;
int object = 0;
int PinMotor[] ={8,7,6,5};
// Function on utilitis
void pin(int pin,bool state,bool Display = false,int Time = 0,int Analog = false){
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
  const int pinUse[] = {4,A5,A4,A3,A2,A1,A0};
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
//Functions for Fisics
void M(int pin,bool Sentido){
  pinMode(pin,OUTPUT);
  switch(Sentido){
    case true:
    digitalWrite(pin,HIGH);
    break;
    case false:
    digitalWrite(pin,LOW);
    break;
  }
}
void G(int M1,int M2,int Giro){
  switch(Giro){
    case 2:
      M(M1,true);
      M(M2,false);
    break;
    case 1:
      M(M1,false);
      M(M2,true);
    break;
    case 0:
      M(M1,false);
      M(M2,false);
    break;
  }
}
long US(int echo, int trigger){
  float distancia;
  long tiempo;
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  tiempo = (pulseIn(echo, HIGH)/2);
  distancia = float(tiempo * 0.0343);
  return distancia;
}
bool L(int pinL){
  return digitalRead(pinL);
}
// Fuctions for mover
void RGLeft(int Delay = 0){
  G(PinMotor[0],PinMotor[1],1);
  G(PinMotor[2],PinMotor[3],2);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("LEFT");
}
void RGRigth(int Delay=0){
  G(PinMotor[0],PinMotor[1],2);
  G(PinMotor[2],PinMotor[3],1);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("RIGTH");
}
void RMAvanzar(int Delay=0){
  G(PinMotor[0],PinMotor[1],1);
  G(PinMotor[2],PinMotor[3],1);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("AVANZAR");
}
void RMBack(int Delay=0){
  G(PinMotor[0],PinMotor[1],2);
  G(PinMotor[2],PinMotor[3],2);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("BACK");
}
void RMStop(int Delay=0){
  G(PinMotor[0],PinMotor[1],0);
  G(PinMotor[2],PinMotor[3],0);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("STOP");
}
void ExistObject(bool Object){
        if(L(12)&&L(11)){
          RMStop();
        }else{
          if(L(12)){
            RMAvanzar(1500);
          }else{
            if(L(11)){
              RMBack(1500);
            }else{
              if(!Object){
                RGRigth();
              }else{
                RMAvanzar();
              }
            }
          }
        }
}
void setup() {
  Serial.begin(9600);
  delay(5000);
}
void loop() {
  Serial.println("\n");
  Serial.println("<---------------------->");
    if(line==1){
      if(L(11)){
        line=2;
      }else{
        RMAvanzar();
      }
    }
    if(line==2){
      if(L(12)){
        line=3;
      }else{
        RMBack();
      }
    }
    if(line==3){
      RMAvanzar(2500);
      line=4;
    }
    if(line==4){
      if(US(10,9)<49){
        Serial.println("OBJECT");
        ExistObject(true);
      }else{
        Serial.println("NOT OBJECT");
        ExistObject(false);
      }
    }
  Serial.println("<---------------------->");
}
