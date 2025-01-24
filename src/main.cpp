#include <Arduino.h>
#include <ESP32Servo.h> 

static const int servoPin1 = 15;
static const int servoPin2 = 5;
static const int potpin1 = 34;

Servo servo1;   // creates an instance of a servo object (library defines the class, but this code creates an instance of the class)
Servo servo2;   // creates an instance of a servo object (library defines the class, but this code creates an instance of the class)


void setup() {
  Serial.begin(921600); // Initialzes baude rate for monitor 
  servo1.attach(servoPin1);//connects servo to the output pin we are targeting (15 in this case)
  servo2.attach(servoPin2);//connects servo to the output pin we are targeting (5 in this case)
  Serial.println("Enter angle (0-180)");
}

void loop() {
    int potvalue =analogRead(potpin1); //reads the value from the potentiometer

    int angle = map(potvalue,0,4095,0,180); //maps the value from the potentiometer to a value between 0 and 180

    servo1.write(angle);
    servo2.write(angle);
}




// #include <Arduino.h>
// #include <ESP32Servo.h> //

// static const int servoPin1 = 15;
// static const int servoPin2 = 5;

// Servo servo1; // creates an instance of a servo object (library defines the class, but this code creates an instance of the class)
// Servo servo2; // creates an instance of a servo object (library defines the class, but this code creates an instance of the class)

// void setup() {
//   Serial.begin(921600); // Initialzes baude rate for monitor 
// servo1.attach(servoPin1);//connects servo to the output pin we are targeting (15 in this case)
// servo2.attach(servoPin2);//connects servo to the output pin we are targeting (5 in this case)
//   Serial.println("Enter angle (0-180)");
// }


// void loop() {
// if (Serial.available() >0){ 
//   String input1 = Serial.readStringUntil('\n');
//   delay(100);
//   String input2 = Serial.readStringUntil('\n');
//   delay(50);
//   int angle1 = input1.toInt(); // Converts the string to an interger
//   int angle2 = input2.toInt();
//   if (angle1 >=0 && angle1 <=180){
//     servo1.write(angle1);

//     Serial.print("moving servo1 to ");

//     Serial.print(angle1);

//     Serial.println(" degrees");
//   } else {
//     Serial.println("Please enter an angle between 0 and 180");
//   }
//   if (angle2 >=0 && angle2 <180){
//     servo2.write(angle2);

//     Serial.print("moving servo2 to ");

//     Serial.print(angle2);

//     Serial.println(" degrees");
//   } else {
//     Serial.println("Please enter an angle between 0 and 180");
//   }
// }






//   /* Works with Input from Serial Monitor
//   if (Serial.available() >0) { //Check if data is available to read; ie. if monitor is up and running
//   int angle = Serial.parseInt(); //Reads the data from the monitor and stores it in the variable angle
//   Serial.println(angle); //Prints the angle to the monitor
//   servo1.write(angle); //Writes the angle to the servo
// }
//   */


// /* Hardcoded version
//  for(int posDegrees = 0; posDegrees <= 180; posDegrees++){
//   // increments of 1 from 0 to 180, then delay , then back down to 0 in increments of 1 from 180, then delay
//   servo1.write(posDegrees);
//   Serial.println(posDegrees);
//   delay(50);
//  }

//  for(int posDegrees = 180; posDegrees >=0; posDegrees--){//Decrements of 1 from 180 to 0, in delays of 20 ms
//   servo1.write(posDegrees);
//   Serial.println(posDegrees);
//   delay(20);
//  }
// */

//   // put your main code here, to run repeatedly:
// }