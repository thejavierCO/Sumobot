/*--Config-----*/
int line = 1;
const int Pm[] = {4,5,6,7};
const int Pu[] = {A3/*echo*/,A2/*trigger*/};
const int Pl[] = {3/*TracerosL*/,12/*TracerosR*/,2/*DelanterosL*/,11/*DelanterosR*/};
const int Delay = 5000;
int Start = 0;
/*--firts  Functions--*/
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
  pin(Pu[1],1,false,10,true);
  tiempo = (pulseIn(echo, HIGH)/2);
  distancia = float(tiempo * 0.0343);
  return distancia;
}
bool L(int pinL){
  return digitalRead(pinL);
}
/*--Second Functions--*/
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
void RGLeft(int Delay = 0){
  G(Pm[0],Pm[1],1);
  G(Pm[2],Pm[3],1);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("LEFT");
}
void RGRigth(int Delay=0){
  G(Pm[0],Pm[1],2);
  G(Pm[2],Pm[3],2);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("RIGTH");
}
void RMAvanzar(int Delay=0){
  G(Pm[0],Pm[1],2);
  G(Pm[2],Pm[3],1);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("AVANZAR");
}
void RMBack(int Delay=0){
  G(Pm[0],Pm[1],1);
  G(Pm[2],Pm[3],2);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("BACK");
}
void RMStop(int Delay=0){
  G(Pm[0],Pm[1],0);
  G(Pm[2],Pm[3],0);
  if(Delay>=1){
    delay(Delay);
  }
  Serial.println("STOP");
}
//functons in load program 
int La(int P1,int P2){
  if(L(P1)&&L(P2)){
    return 0;
  }else
  if(L(P1)||L(P2)){
    return 1;
  }/*else
  if(L(P2)){
    return 3;
  }*/
}
void ExistObject(bool Object){
 if(La(Pl[1],Pl[3])==1){
      RMAvanzar(1500);
 }else{
   if(La(Pl[0],Pl[2])==1){
      RMBack(1500);
   }else{
      if(!Object){
        RGRigth();
      }else{
       RMAvanzar();
      }
   }
 }

void setup() {
  Serial.begin(9600);
  pin(8,1);
  //pin(,1);
  pin(9,0);
  //pin(A3,0);
  //delay(Delay);
}
void loop() {
  Serial.println("\n");
  Serial.print("<----------(");
  Serial.println(")---------->");
    if(line==1){
      if(La(Pl[1],Pl[3])==1){
        line=2;
      }else{
        RMAvanzar();
      }
    }
    if(line==2){
      RMBack();
      delay(1000);
      line=3;
    }
    if(line==3){
      RMAvanzar(500);
      line=4;
    }
    if(line==4){
      if(US(Pu[0],Pu[1])<49){
        if(Start>30){
          Start=0;
          RGRigth();
          delay(1500);
        }else{
          Start++;
          ExistObject(true);
        }
      }else{
        Start=0;
        ExistObject(false);
      }
    }
   Serial.println("----------------------->");
}
