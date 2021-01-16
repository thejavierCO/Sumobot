/*--Config-----*/
const int Pm[] = {4,5,6,7};
const int Pu[] = {A3/*echo*/,A2/*trigger*/,A0/*echo*/,A1/*trigger*/,A4/*echo*/,A5/*trigger*/};
const int Pl[] = {10/*TracerosL*/,9/*TracerosR*/,2/*DelanterosL*/,3/*DelanterosR*/};
const int Delay = 4000;
/*--firts  Functions--*/
int line = 1;
int Start = 0;
int Attackline = 0;
int c = 0;
// Utilitis
void pin(int pin,bool state,bool Display = false,int Time = 0,bool US = false,bool Type = true){// funcion de encendido y apagado de pines
  if(state>2){
    Serial.println("not exist state 2");
  }else{
    pinMode(pin,Type?OUTPUT:INPUT);
    digitalWrite(pin,Display?state?LOW:HIGH:state?HIGH:LOW);
    US?delayMicroseconds(Time):delay(Time);
    Time>0?digitalWrite(pin,!Display?state?LOW:HIGH:state?HIGH:LOW):delay(0);
    US?delayMicroseconds(0):delay(Time);
  }
}
// Move Motor and all robot
void M(int pin,bool Sentido){// one motor
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
void G(int M1,int M2,int Giro){// two motor
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
// Use Sensors
long US(int echo, int trigger){
  float distancia;
  long tiempo;
  pinMode(echo, INPUT);
  pin(trigger,1,false,10,true);
  tiempo = (pulseIn(echo, HIGH)/2);
  distancia = float(tiempo * 0.0343);
  return distancia;
}
bool L(int pinL){
  return digitalRead(pinL);
}
/*--Second Functions--*/
void RGLeft(int Delay = 0){
  G(Pm[0],Pm[1],1);
  G(Pm[2],Pm[3],1);
  if(Delay>=1){
    delay(Delay);
  }
}
void RGRigth(int Delay=0){
  G(Pm[0],Pm[1],2);
  G(Pm[2],Pm[3],2);
  if(Delay>=1){
    delay(Delay);
  }
}
void RMAvanzar(int Delay=0){
  G(Pm[0],Pm[1],2);
  G(Pm[2],Pm[3],1);
  if(Delay>=1){
    delay(Delay);
  }
}
void RMBack(int Delay=0){
  G(Pm[0],Pm[1],1);
  G(Pm[2],Pm[3],2);
  if(Delay>=1){
    delay(Delay);
  }
}
void RMStop(int Delay=0){
  G(Pm[0],Pm[1],0);
  G(Pm[2],Pm[3],0);
  if(Delay>=1){
    delay(Delay);
  }
}
int Testing(){
  /*RGLeft(2000);
  RMStop(500);
  RGRigth(2000);
  RMStop(500);
  RMAvanzar(2000);
  RMStop(500);
  RMBack(2000);
  RMStop(500);*/
  Serial.print("US :");
  Serial.println(US(Pu[0],Pu[1]));
  Serial.print("US :");
  Serial.println(US(Pu[2],Pu[3]));
  Serial.print("US :");
  Serial.println(US(Pu[4],Pu[5]));
  Serial.print("L1 :");
  Serial.println(L(Pl[0]));
    Serial.print("L1 :");
  Serial.println(L(Pl[1]));
    Serial.print("L1 :");
  Serial.println(L(Pl[2]));
    Serial.print("L1 :");
  Serial.println(L(Pl[3]));
}
//functons in load program 
int La(int P1,int P2){
  if(L(P1)&&L(P2)){
    return 1;
  }else
  if(L(P1)||L(P2)){
    return 1;
  }else
    return 0;
}
void ExistObject(bool Object){
  if(Attackline==1){
     while(1){
      c++;
      if(c>800){
        Attackline=0;
        break;
      }else{
        if(US(Pu[2],Pu[3])>30){
          while(1){
            if(US(Pu[0],Pu[1])<48){
              break;
            }else{
              //RGRigth(100);
              RGLeft(150);
            }
          }
          Attackline=0;
          break;        
        }else{
          if(US(Pu[4],Pu[5])>30){
            while(1){
              if(US(Pu[0],Pu[1])<48){
                break;
              }else{
                //RGLeft(100);
                RGRigth(150);
              }
            }
            Attackline=0;
            break;        
          }else{
            RGRigth();
          }
        }
      }
     }
  }else{
    if(La(Pl[1],Pl[3])){
        if(!Object){
          Attackline=1;
        }
        RMAvanzar(1800);
        Attackline=1;
    }else{
        if(La(Pl[0],Pl[2])){
          if(!Object){
            Attackline=1;
          }
          RMBack(1800);
          Attackline=1;
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
  pin(8,1);
  pin(13,1);
  pin(9,0);
  delay(Delay);
}
void loop() {
  Serial.println("\n");
    if(line==1){
      if(La(Pl[0],Pl[2])==1){
        line=2;
      }else{
        RMAvanzar();
      }
    }
    if(line==2){
      RMBack(1800);
      RGRigth(2350);
      line=4;
    }
    if(line==4){
      if(US(Pu[0],Pu[1])<50){
        delay(150);
        ExistObject(true);
      }else{
        Start=0;
        ExistObject(false);
      }
    }
}
