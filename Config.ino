//--------------------------------//
//        Config Pins             //
//--------------------------------//
const int Pm[] = {4,5,6,7};
const int Pu[] = {A3/*echo*/,A2/*trigger*/,A0/*echo*/,A1/*trigger*/,A4/*echo*/,A5/*trigger*/};
const int Pl[] = {10/*TracerosL*/,9/*TracerosR*/,2/*DelanterosL*/,3/*DelanterosR*/};
const int Test[] = {0/*Motors*/,0/*SensorsL*/,0/*SensorsUS*/,1/* Libre*/};
const int DelayStart = 4000;
const int DelayAtack = 0;
int Attackline = 0;
//--------------------------------//
//        Config Load             //
//--------------------------------//
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
//--------------------------------//
//         Funcions               //
//--------------------------------//
void Left(int Delay = 0){
  MotorL.Giro(1);MotorR.Giro(1);
  delay(Delay>=1?Delay:0);
}
void Right(int Delay=0){
  MotorL.Giro(2);MotorR.Giro(2);
  delay(Delay>=1?Delay:0);
}
void Top(int Delay=0){
  MotorL.Giro(2);MotorR.Giro(1);
  delay(Delay>=1?Delay:0);
}
void Bottom(int Delay=0){
  MotorL.Giro(1);MotorR.Giro(2);
  delay(Delay>=1?Delay:0);
}
void Stop(int Delay=0){
  MotorL.Giro(0);MotorR.Giro(0);
  delay(Delay>=1?Delay:0);
}
int LineDetect(int P1,int P2){return (P1&&P2)?1:(P1||P2)?1:0;}
int Object(bool exist){
    if(Attackline==1){
      int c = 0;
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
          }
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
        delay(1);
      }
  }else{
    if(LineDetect(L1.White(),L3.White())){// Linea tracera
      Attackline = exist;
      Top(1800);
    }else{
      if(LineDetect(L2.White(),L4.White())){// Linea delantera
        Attackline = exist;
        Bottom(1800);
      }else{
        !exist?Right():Top();
      }
    }
  }
}
int Testing(int Type){
  switch(Type){
    case 1:
      Serial.println("Move");
      Left(1000);Right(1000);Top(1000);Bottom(1000);Stop();
    break;
    case 2:
      Serial.println("UtraSonido");
      Serial.print("US :");Serial.println(Us1.GetLength());
      Serial.print("US :");Serial.println(Us2.GetLength());
      Serial.print("US :");Serial.println(Us3.GetLength());
      delay(1000);
    break;
    case 3:
      Serial.println("Line");
      Serial.print("L1 :");Serial.println(L1.White());
      Serial.print("L2 :");Serial.println(L2.White());
      Serial.print("L3 :");Serial.println(L3.White());
      Serial.print("L4 :");Serial.println(L4.White());
      delay(1000);
    break;
    case 4:
    /*   (Insert Testing)     */
    /*  (End Insert Testing)  */
    break;
  }
}

bool T(int type){
  switch(type){
        case 0:
        return (Test[0]!=0||Test[1]!=0||Test[2]!=0||Test[3]!=0)?true:false;
        break;
        case 1:
        return true;
        (Test[0]!=0)?Testing(1):1;
        (Test[1]!=0)?Testing(2):1;
        (Test[2]!=0)?Testing(3):1;
        (Test[3]!=0)?Testing(4):1;
        break;
    }
}
