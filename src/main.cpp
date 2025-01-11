#include <Arduino.h>
#include <ESP32Servo.h> //

static const int servoPin = 15;

Servo servo1; // creates an instance of a servo object (library defines the
              // class, but this code creates an instance of the class)

void setup() {
  Serial.begin(921600);    // Initialzes baude rate for monitor
  servo1.attach(servoPin); // connects servo to the output pin we are targeting
                           // (15 in this case)
  Serial.println("Enter angle (0-180)");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int angle = input.toInt();

    if (angle >= 0 && angle < 180) {
      servo1.write(angle);

      Serial.print("moving servo to ");

      Serial.print(angle);

      Serial.println(" degrees");
    } else {
      Serial.println("Please enter an angle between 0 and 180");
    }
  }

  /* Works with Input from Serial Monitor
  if (Serial.available() >0) { //Check if data is available to read; ie. if
monitor is up and running int angle = Serial.parseInt(); //Reads the data from
the monitor and stores it in the variable angle Serial.println(angle); //Prints
the angle to the monitor servo1.write(angle); //Writes the angle to the servo
}
  */

  /* Hardcoded version
   for(int posDegrees = 0; posDegrees <= 180; posDegrees++){
    // increments of 1 from 0 to 180, then delay , then back down to 0 in
   increments of 1 from 180, then delay servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(50);
   }

   for(int posDegrees = 180; posDegrees >=0; posDegrees--){//Decrements of 1
   from 180 to 0, in delays of 20 ms servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(20);
   }
  */

  // put your main code here, to run repeatedly:
}