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
    Giro(int direcction){
      switch(direcction){
        case 0:
        pin(_motor1,false);
        pin(_motor2,false);
        break;
        case 1:
        pin(_motor1,false);
        pin(_motor2,true);
        break;
        case 2:
        pin(_motor1,true);
        pin(_motor2,false);
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
