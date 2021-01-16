//--------------------------------//
//                                //
//        Load Main               //
//                                //
//--------------------------------//
void setup(){
    console.Start();
    pin(8,1);
    pin(13,1);
    pin(9,0);
    delay(DelayStart);
}
void loop(){
    if(T(0)){
      T(1);
    }else{
        while(1){
          if(LineDetect(L1.White(),L3.White())==1){break;}else{Top();}
        }
        while(1){
          Bottom(1000);Right(2350);break;
        }
        while(1){
          //if(Us1.GetLength()<50){delay(150);Object(true);}else{Object(false);}
        }
    }
}
