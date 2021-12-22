//====================== Code Information =======================//
//
//  Creator:  Fabian Noll
//  Date of Creation: 10.05.2021
//  Purpous: The "Operating System" of the Robot Dog R.A.G.N.A. A recreation of the Boston Dynamics Spot robot
//
//===============================================================//

//======== Libraries
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h> 

Adafruit_PWMServoDriver myServos = Adafruit_PWMServoDriver();

SoftwareSerial BlueArm(10, 9); // RX | TX //To keep the standard Serial Port open Software Serial is used

//======== Number / Position / Adress of the Servos =============//
#define TopRFront 0
#define BottomRFront 1
#define TopLFront 12
#define BottomLFront 13
#define TopRBack 2
#define BottomRBack 3
#define TopLBack 14
#define BottomLBack 15

//======= Different Variables for saving and testing purpouses ==============//

int Command = 20;                                                           // Variable for saving the Bluetooth command
boolean testActivated = true;

//====================== Begin of Code =====================================//
void setup() {

  Serial.begin(9600);
  BlueArm.begin(9600);
  
  //binding and setting up the pwm driver

  myServos.begin();
  myServos.setPWMFreq(60);
  delay(10);
}

void loop() {
  if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
    Command = BlueArm.read(); // Reads the data from the serial port ans saves it
  }
  if (Command == 0) {
    standUp();
    Command = 20;
  }
  if (Command == 1) {
    sitDown();
    Command = 20;
  }
  if (Command == 2) {
    walkForward();
    Command = 20;
  }
  if (Command == 4) {
    walkRight();
    Command = 20;
  }
  if (Command == 6) {
    sit();
    Command == 20;
  }
  if (Command == 7) {
    test();
  }
  if (Command == 3) {
    walkLeft();
  }
}

void standUp() {
  myServos.setPWM(TopRFront, 0, map(180 - 130, 0, 180, 130, 600));
  myServos.setPWM(BottomRFront, 0, map(180 - 90, 0, 180, 130, 600));
  myServos.setPWM(TopLFront, 0, map(130, 0, 180, 130, 600));
  myServos.setPWM(BottomLFront, 0, map(90, 0, 180, 130, 600));

  delay(150);

  myServos.setPWM(TopRBack, 0, map(180 - 130, 0, 180, 130, 600));
  myServos.setPWM(BottomRBack, 0, map(180 - 90, 0, 180, 130, 600));
  myServos.setPWM(TopLBack, 0, map(130, 0, 180, 130, 600));
  myServos.setPWM(BottomLBack, 0, map(90, 0, 180, 130, 600));
}

void sitDown() {
  myServos.setPWM(TopRBack, 0, map(180 - 160, 0, 180, 130, 600));
  myServos.setPWM(BottomRBack, 0, map(180 - 20, 0, 180, 130, 600));
  myServos.setPWM(TopLBack, 0, map(160, 0, 180, 130, 600));
  myServos.setPWM(BottomLBack, 0, map(20, 0, 180, 130, 600));

  delay(150);

  myServos.setPWM(TopRFront, 0, map(180 - 160, 0, 180, 130, 600));
  myServos.setPWM(BottomRFront, 0, map(180 - 20, 0, 180, 130, 600));
  myServos.setPWM(TopLFront, 0, map(160, 0, 180, 130, 600));
  myServos.setPWM(BottomLFront, 0, map(20, 0, 180, 130, 600));
}

void sit() {

  myServos.setPWM(TopRFront, 0, map(180 - 120, 0, 180, 130, 600));
  myServos.setPWM(BottomRFront, 0, map(180 - 120, 0, 180, 130, 600));

  myServos.setPWM(TopLFront, 0, map(120, 0, 180, 130, 600));
  myServos.setPWM(BottomLFront, 0, map(120, 0, 180, 130, 600));

  myServos.setPWM(TopRBack, 0, map(180 - 160, 0, 180, 130, 600));
  myServos.setPWM(BottomRBack, 0, map(180 - 50, 0, 180, 130, 600));

  myServos.setPWM(TopLBack, 0, map(160, 0, 180, 130, 600));
  myServos.setPWM(BottomLBack, 0, map(50, 0, 180, 130, 600));

}

void walkForward() {
  while (!(Command == 10)) {

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 4) {
        walkRight();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    myServos.setPWM(TopRFront, 0, map(180 - 150, 0, 180, 130, 600));
    myServos.setPWM(BottomRFront, 0, map(180 - 88, 0, 180, 130, 600));
    myServos.setPWM(TopLFront, 0, map(150, 0, 180, 130, 600));
    myServos.setPWM(BottomLFront, 0, map(90, 0, 180, 130, 600));
    myServos.setPWM(TopRBack, 0, map(180 - 150, 0, 180, 130, 600));
    myServos.setPWM(BottomRBack, 0, map(180 - 88, 0, 180, 130, 600));
    myServos.setPWM(TopLBack, 0, map(150, 0, 180, 130, 600));
    myServos.setPWM(BottomLBack, 0, map(90, 0, 180, 130, 600));
    delay(150);

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 4) {
        walkRight();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    //Leg Front Right Forward
    myServos.setPWM(BottomRFront, 0, map(180 - 50, 0, 180, 130, 600));
    myServos.setPWM(TopRFront, 0, map(180 - 70, 0, 180, 130, 600));
    delay(150);
    myServos.setPWM(BottomRFront, 0, map(180 - 118, 0, 180, 130, 600));
    //delay(300);

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 4) {
        walkRight();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    //Leg Back Left Forward
    myServos.setPWM(BottomLBack, 0, map(50, 0, 180, 130, 600));
    myServos.setPWM(TopLBack, 0, map(70, 0, 180, 130, 600));
    delay(150);
    myServos.setPWM(BottomLBack, 0, map(118, 0, 180, 130, 600));
    delay(150);

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 4) {
        walkRight();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    //Both Legs pulling back
    myServos.setPWM(TopRFront, 0, map(180 - 150, 0, 180, 130, 600));
    myServos.setPWM(TopLBack, 0, map(150, 0, 180, 130, 600));
    delay(100);
    myServos.setPWM(BottomRFront, 0, map(180 - 90, 0, 180, 130, 600));
    myServos.setPWM(BottomLBack, 0, map(90, 0, 180, 130, 600));
    delay(100);

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 4) {
        walkRight();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    myServos.setPWM(BottomLFront, 0, map(50, 0, 180, 130, 600));
    myServos.setPWM(TopLFront, 0, map(70, 0, 180, 130, 600));
    delay(150);
    myServos.setPWM(BottomLFront, 0, map(120, 0, 180, 130, 600));
    //delay(300);

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 4) {
        walkRight();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    myServos.setPWM(BottomRBack, 0, map(180 - 50, 0, 180, 130, 600));
    myServos.setPWM(TopRBack, 0, map(180 - 70, 0, 180, 130, 600));
    delay(150);
    myServos.setPWM(BottomRBack, 0, map(180 - 120, 0, 180, 130, 600));
    delay(150);

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 4) {
        walkRight();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    myServos.setPWM(TopLFront, 0, map(150, 0, 180, 130, 600));
    myServos.setPWM(TopRBack, 0, map(180 - 150, 0, 180, 130, 600));
    delay(100);
    myServos.setPWM(BottomLFront, 0, map(90, 0, 180, 130, 600));
    myServos.setPWM(BottomRBack, 0, map(180 - 90, 0, 180, 130, 600));
    delay(100);
  }
  standUp();
}

void walkRight() {
  
  myServos.setPWM(TopRFront, 0, map(180 - 130, 0, 180, 130, 600));
  myServos.setPWM(BottomRFront, 0, map(180 - 80, 0, 180, 130, 600));
  myServos.setPWM(TopLFront, 0, map(130, 0, 180, 130, 600));
  myServos.setPWM(BottomLFront, 0, map(90, 0, 180, 130, 600));
  myServos.setPWM(TopRBack, 0, map(180 - 130, 0, 180, 130, 600));
  myServos.setPWM(BottomRBack, 0, map(180 - 90, 0, 180, 130, 600));
  myServos.setPWM(TopLBack, 0, map(130, 0, 180, 130, 600));
  myServos.setPWM(BottomLBack, 0, map(90, 0, 180, 130, 600));

  while (!(Command == 10)) {

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 2) {
        walkForward();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    myServos.setPWM(BottomRBack, 0, map(180 - 50, 0, 180, 130, 600));
    myServos.setPWM(TopRBack, 0, map(180 - 170, 0, 180, 130, 600));
    delay(250);
    myServos.setPWM(BottomRBack, 0, map(180 - 80, 0, 180, 130, 600));
    delay(200);

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 2) {
        walkForward();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    //Leg Front Left Forward
    myServos.setPWM(BottomLFront, 0, map(80, 0, 180, 130, 600));
    myServos.setPWM(TopLFront, 0, map(70, 0, 180, 130, 600));
    delay(250);
    myServos.setPWM(BottomLFront, 0, map(120, 0, 180, 130, 600));
    delay(300);
    
    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 2) {
        walkForward();
        break;
      }
      if (Command == 3) {
        walkLeft();
        break;
      }
    }
    //========================================================//

    myServos.setPWM(TopLFront, 0, map(130, 0, 180, 130, 600));
    myServos.setPWM(TopRBack, 0, map(180 - 130, 0, 180, 130, 600));
    delay(100);
    myServos.setPWM(BottomLFront, 0, map(90, 0, 180, 130, 600));
    myServos.setPWM(BottomRBack, 0, map(180 - 90, 0, 180, 130, 600));
    delay(300);
  }
  standUp();
}

void walkLeft() {
 
  myServos.setPWM(TopRFront, 0, map(180 - 130, 0, 180, 130, 600));
  myServos.setPWM(BottomRFront, 0, map(180 - 80, 0, 180, 130, 600));
  myServos.setPWM(TopLFront, 0, map(130, 0, 180, 130, 600));
  myServos.setPWM(BottomLFront, 0, map(90, 0, 180, 130, 600));
  myServos.setPWM(TopRBack, 0, map(180 - 130, 0, 180, 130, 600));
  myServos.setPWM(BottomRBack, 0, map(180 - 90, 0, 180, 130, 600));
  myServos.setPWM(TopLBack, 0, map(130, 0, 180, 130, 600));
  myServos.setPWM(BottomLBack, 0, map(90, 0, 180, 130, 600));

  while (!(Command == 10)) {

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 2) {
        walkForward();
        break;
      }
      if (Command == 3) {
        walkRight();
        break;
      }
    }
    //========================================================//

    myServos.setPWM(BottomLBack, 0, map(50, 0, 180, 130, 600));
    myServos.setPWM(TopLBack, 0, map(170, 0, 180, 130, 600));
    delay(250);
    myServos.setPWM(BottomLBack, 0, map(80, 0, 180, 130, 600));
    delay(200);

    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 2) {
        walkForward();
        break;
      }
      if (Command == 3) {
        walkRight();
        break;
      }
    }
    //========================================================//

    //Leg Front Left Forward
    myServos.setPWM(BottomRFront, 0, map(180 - 80, 0, 180, 130, 600));
    myServos.setPWM(TopRFront, 0, map(180 - 70, 0, 180, 130, 600));
    delay(250);
    myServos.setPWM(BottomRFront, 0, map(180 - 140, 0, 180, 130, 600));
    delay(300);
    
    //=================== STOP Check =========================//
    if (BlueArm.available() > 0) { // Checks whether data is comming from the serial port
      Command = BlueArm.read(); // Reads the data from the serial port ans saves it
      if (Command == 10) break;
      if (Command == 2) {
        walkForward();
        break;
      }
      if (Command == 3) {
        walkRight();
        break;
      }
    }
    //========================================================//

    myServos.setPWM(TopRFront, 0, map(180 - 130, 0, 180, 130, 600));
    myServos.setPWM(TopLBack, 0, map(130, 0, 180, 130, 600));
    delay(100);
    myServos.setPWM(BottomRFront, 0, map(180 - 90, 0, 180, 130, 600));
    myServos.setPWM(BottomLBack, 0, map(90, 0, 180, 130, 600));
    delay(300);
  }
  standUp();
}

void test() {
  myServos.setPWM(TopRFront, 0, map(180 - 90, 0, 180, 130, 600));
  myServos.setPWM(BottomRFront, 0, map(180 - 90, 0, 180, 130, 600));
  myServos.setPWM(TopLFront, 0, map(90, 0, 180, 130, 600));
  myServos.setPWM(BottomLFront, 0, map(90, 0, 180, 130, 600));

  delay(150);

  myServos.setPWM(TopRBack, 0, map(180 - 90, 0, 180, 130, 600));
  myServos.setPWM(BottomRBack, 0, map(180 - 90, 0, 180, 130, 600));
  myServos.setPWM(TopLBack, 0, map(90, 0, 180, 130, 600));
  myServos.setPWM(BottomLBack, 0, map(90, 0, 180, 130, 600));
}
/*
  void standUp(){
  DegreeTop = (((acos((pow(b, 2) + pow(height, 2) - pow(a, 2)) / (2 * b * height))) * 4068) / 71) + 90;
  DegreeBottom = ((acos((pow(a, 2) + pow(height, 2) - pow(b, 2)) / (2 * a * height))) * 4068) / 71;
  DegreeTopRight = 180 - DegreeTop;
  DegreeBottomRight = 180 - DegreeBottom;

  pulseTop = map(DegreeTop, 0, 180, 130, 600);
  pulseTopRight = map(DegreeTopRight, 0, 180, 130, 600);
  pulseBottom = map(DegreeBottom, 0, 180, 130, 600);
  pulseBottomRight = map(DegreeBottomRight, 0, 180, 130, 600);

  myServos.setPWM(0, 0, pulseTopRight);
  myServos.setPWM(1, 0, pulseBottomRight);
  myServos.setPWM(12, 0, pulseTop);
  myServos.setPWM(13, 0, pulseBottom);
  delay(150);
  myServos.setPWM(2, 0, pulseTopRight);
  myServos.setPWM(3, 0, pulseBottomRight);
  myServos.setPWM(14, 0, pulseTop);
  myServos.setPWM(15, 0, pulseBottom);
  } */
