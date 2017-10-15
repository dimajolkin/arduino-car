//L293D

class Car {
  //Motor A
  private:
      int motorFirstUp  = 8;  // Pin 14 of L293
      int motorFirstDown  = 9;  // Pin 10 of L293
  //Motor B
      int motorControltLeft  = 10; // Pin  7 of L293
      int motorControltRight  = 11;  // Pin  2 of L293
  public:
    void init()
    {
        //Set pins as outputs
      pinMode(motorFirstUp, OUTPUT);
      pinMode(motorFirstDown, OUTPUT);
      pinMode(motorControltLeft, OUTPUT);
      pinMode(motorControltRight, OUTPUT);
    }

    void down()
    {
        analogWrite(motorFirstUp, 0);
        analogWrite(motorFirstDown, 180);
    }
    
    void up()
    {
        analogWrite(motorFirstUp, 180);
        analogWrite(motorFirstDown, 0);
    }

    void left()
    {
        analogWrite(motorControltLeft, 180);
        analogWrite(motorControltRight, 0);
    }

    void right()
    {
        analogWrite(motorControltRight, 180);
        analogWrite(motorControltLeft, 0);
    }

    void center()
    {
        analogWrite(motorControltRight, 0);
        analogWrite(motorControltLeft, 0);
    }

    void stop()
    {
        analogWrite(motorFirstUp, 0);
        analogWrite(motorFirstDown, 0);
    }
};

class Control {
  private:
     int gnd = 2;
     int vcc = 3;

  public:
  
     void init()
     {
          Serial.begin(9600);
      
          pinMode(gnd, OUTPUT);
          pinMode(vcc, OUTPUT);

          digitalWrite(gnd, LOW);
          digitalWrite(vcc, HIGH);
     }

     int available()
     {
        return Serial.available();
     }

     int read()
     {
         return Serial.read();
     }
};

Car car;
Control control;
int c;
//This will run only one time.
void setup(){
   car.init();
   control.init();
}


void loop() {
  if (control.available()) {
    c = control.read();
    Serial.println(c);
    if (c == 'w') {
       car.up();
       Serial.println("car up");
    } else if (c == 's') {
      car.down();
      Serial.println("car down");
    } else if (c == 'a') {
      car.left();
      Serial.println("car left");
    } else if (c == 'd') {
      car.right();
      Serial.println("car right");
    } else if (c == 'q') {
      car.stop();
      car.center();
      Serial.println("car stop");
    } 
    c = 0;
  }

}

