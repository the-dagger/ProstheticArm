#include <Servo.h>

Servo myservo7, myservo8, myservo9, myservo10, myservo11; // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo7.attach(5);  //Attach the servos to digital pins
  myservo8.attach(6);
  myservo9.attach(9);
  myservo10.attach(10);
  myservo11.attach(11);
  myservo7.write(180 - pos);  //Move the servos to normal rest position 
  myservo8.write(pos);
  myservo9.write(pos);
  myservo10.write(180 - pos);
  myservo11.write(pos);
}

void loop() {
  int f0 = analogRead(A0);
  int f1 = analogRead(A1);
  if (f0 > 300) { //If the pressure detected at finger 0 was more than 300, perform the mentioned task
    Serial.print("Closed Hand"); 
    Serial.println(f0);  //Print the value received on the Serial Monitor
    //Close the fist
    pos = 180;
    //  for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees in steps of 1 degree
    //Don't run the loop for now since we want to close the hand only once
    myservo7.write(180 - pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
    myservo11.write(180 - pos); // tell servo to go to position in variable 'pos'
    delay(40);                       // waits 15ms for the servo to reach the position
    //  }
  }
  else if (f1 > 300) {
    //Open the fist
    Serial.print("Opened Hand");
    Serial.println(f1);
    pos = 0;
    //  for (pos = 180; pos >= 0 ; pos -= 10) {
    myservo7.write(180 - pos);
    myservo8.write(pos);
    myservo9.write(pos);
    myservo10.write(pos);
    myservo11.write( 180 - pos); // tell servo to go to position in variable 'pos'
    delay(40);
    //  }
  }
}
