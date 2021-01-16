void pin(int pin ,int state,bool Type = true,bool active = true){// funcion de encendido y apagado de pines
  pinMode(pin,Type?OUTPUT:INPUT);
  active?digitalWrite(pin,state?HIGH:LOW):delay(0);
}
class Config{
  private:
    int _console;
  public:
    Config(int type = 0){
      _console = type==0?9600:type;
    }
    Start(){
       Serial.begin(_console==0?9600:_console);
    }
    GetBaud(){
      return _console;
    }
};
class Motor{
  private:
    int _motor1;
    int _motor2;
  public:
    Motor(int Mp1,int Mp2){
      _motor1 = Mp1;
      _motor2 = Mp2;
    }
    Giro(bool direcction){
      switch(direcction){
        case 0:
        pin(_motor1,false);
        pin(_motor2,false);
        break;
        case 1:
        pin(_motor1,true);
        pin(_motor2,false);
        break;
        case 2:
        pin(_motor1,false);
        pin(_motor2,true);
        break;
      }
    }
    GetPin(int type){
      switch(type){
        case 0:
          return _motor1;
        break;
        case 1:
          return _motor2;
        break;
      }
    }
};
class Line{
  private:
    int _PinLine;
  public:
    Line(int v1){
      _PinLine = v1;
    }
    GetPin(){
      return _PinLine;
    }
    White(){
      return digitalRead(_PinLine);
    }
    Black(){
      return !digitalRead(_PinLine);
    }
};
class US{
  private:
    int _PinUSE;
    int _PinUST;
  public:
    US(int v1, int v2){_PinUSE = v1;_PinUST = v2;}
    GetEcho(){return _PinUSE;}
    GetTrigger(){return _PinUST;}
    GetTime(){
      pin(_PinUSE,false,false);
      pin(_PinUST,true);
      delayMicroseconds(10);
      pin(_PinUST,false);
      return (pulseIn(_PinUSE, HIGH)/2);
    }
    GetLength(){
      long Time;
      pin(_PinUSE,false,false);
      pin(_PinUST,true);
      delayMicroseconds(10);
      pin(_PinUST,false);
      Time = (pulseIn(_PinUSE, HIGH)/2);
      return float(Time*0.0343);
    }
};
/* Config pins*/
const int Pm[] = {4,5,6,7};
const int Pu[] = {A3/*echo*/,A2/*trigger*/,A0/*echo*/,A1/*trigger*/,A4/*echo*/,A5/*trigger*/};
const int Pl[] = {10/*TracerosL*/,9/*TracerosR*/,2/*DelanterosL*/,3/*DelanterosR*/};
const int DelayStart = 4000;
const int Test[] = {0/*Motors*/,0/*Sensors*/};
int c = 0;
int Attackline = 0;
/*Load Config*/
Config console(9600);
Motor MotorL(Pm[0],Pm[1]);
Motor MotorR(Pm[2],Pm[3]);
US Us1(Pu[0],Pu[1]);
US Us2(Pu[2],Pu[3]);
US Us3(Pu[4],Pu[5]);
Line L1(Pl[0]);
Line L2(Pl[1]);
Line L3(Pl[2]);
Line L4(Pl[3]);
/* functions */
void Left(int Delay = 0){
  MotorL.Giro(1);
  MotorL.Giro(1);
  if(Delay>=1){
    delay(Delay);
  }
}
void Right(int Delay=0){
  MotorL.Giro(2);
  MotorL.Giro(2);
  if(Delay>=1){
    delay(Delay);
  }
}
void Top(int Delay=0){
  MotorL.Giro(2);
  MotorL.Giro(1);
  if(Delay>=1){
    delay(Delay);
  }
}
void Bottom(int Delay=0){
  MotorL.Giro(1);
  MotorL.Giro(2);
  if(Delay>=1){
    delay(Delay);
  }
}
void Stop(int Delay=0){
  MotorL.Giro(0);
  MotorL.Giro(0);
  if(Delay>=1){
    delay(Delay);
  }
}
int LineDetect(int P1,int P2){
  if(P1&&P2){
    return 1;
  }else
  if(P1||P2){
    return 1;
  }else
    return 0;
}
int Object(bool exist){
    if(Attackline==1){
     while(1){
      c++;
      if(c>800){
        Attackline=0;
        break;
      }else{
        if(Us2.GetLength()>30){
          while(1){
            if(Us1.GetLength()<48){
              break;
            }else{
              Left(150);
            }
          }
          Attackline=0;
          break;        
        }else{
          if(Us3.GetLength()>30){
            while(1){
              if(Us1.GetLength()<48){
                break;
              }else{
                Right(150);
              }
            }
            Attackline=0;
            break;        
          }else{
            Right();
          }
        }
      }
     }
  }else{
    if(LineDetect(L1.White(),L3.White())){
        if(!exist){
          Attackline=1;
        }
        Top(1800);
        Attackline=1;
    }else{
        if(LineDetect(L2.White(),L4.White())){
          if(!exist){
            Attackline=1;
          }
          Bottom(1800);
          Attackline=1;
        }else{
          if(!exist){
            Right();
          }else{
            Top();
          }
      }
    }
  }
}
int Testing(int Type){
  switch(Type){
    case 1:
      Left(1000);
      Right(1000);
      Top(1000);
      Bottom(1000);
      Stop();
    break;
    case 2:
      Serial.print("US :");
      Serial.println(Us1.GetLength());
      Serial.print("US :");
      Serial.println(Us2.GetLength());
      Serial.print("US :");
      Serial.println(Us3.GetLength());
      delay(1000);
    break;
    case 3:
      Serial.print("L1 :");
      Serial.println(L1.White());
      Serial.print("L2 :");
      Serial.println(L2.White());
      Serial.print("L3 :");
      Serial.println(L3.White());
      Serial.print("L4 :");
      Serial.println(L4.White());
      delay(1000);
    break;
  }
}
void setup(){
  console.Start();
  pin(8,1);
  pin(13,1);
  pin(9,0);
  delay(DelayStart);
}
void loop(){
  if(Test[0]!=0){
    Testing(1);
    if(Test[1]!=0){
      Testing(2);
      Testing(3);
    }
  }else
  while(1){
    if(LineDetect(L1.White(),L2.White())==1){
      break;
    }else{
      Top();
    }
  }
  while(1){
    Bottom(1000);
    Right(2350);
    break;
  }
  while(1){
    if(Us1.GetLength()<50){
      delay(150);
      Object(true);
    }else{
      Object(false);
    }
  }
}
