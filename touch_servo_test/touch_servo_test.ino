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
  openHand();
}

void loop() {
  int f1 = analogRead(A0);
  int f2 = analogRead(A1);
  int f3 = analogRead(A2);
  int f4 = analogRead(A3);
  if (f1 > 200 && f2 > 300 && f3 > 300 && f4 > 200) {

  }
  if (f1 > 200 && f2 > 300) {
    finger12();
  }
  else if (f1 > 200 && f3 > 300) {
    finger13();
  }
  else if (f1 > 200 && f4 > 200) {
    finger14();
  }
  else if (f2 > 300 && f3 > 300) {
    finger23();
  }
  else if (f2 > 300 && f4 > 200) {
    finger24();
  }
  else if (f3 > 300 && f4 > 200) {
    finger34();
  }
  else if (f1 > 200) { //If the pressure detected at finger 0 was more than 300, perform the mentioned task
    Serial.println(f1);  //Print the value received on the Serial Monitor
    finger1();
    return;
  }
  else if (f2 > 300) {
    Serial.println(f2);
    finger2();
    return;
  }
  else if (f3 > 300) {
    Serial.print("Victory");
    Serial.println(f3);
    finger3();
    return;
  }
  else if (f4 > 200) {
    Serial.println(f4);
    finger4();
  }
  else if (f1 < 300 && f2 < 300 && f3 < 300 && f4 < 200) {
    openHand();
  }
}

void closeHand() {
  finger1();
  finger2();
  finger3();
  finger4();
}

void openHand() {
  pos = 0;
  myservo7.write(180 - pos);
  myservo8.write(pos);
  myservo9.write(pos);
  myservo10.write(pos);
  myservo11.write( 180 - pos); // tell servo to go to position in variable 'pos'
  delay(40);
}
void finger1() {
  Serial.println("Moved Finger 1");
  myservo11.write( 0);
  delay(40);
}

void finger2() {
  Serial.println("Moved Finger 2");
  myservo8.write(180);
  delay(40);
}

void finger3() {
  Serial.println("Moved Finger 3");
  myservo10.write( 180);
  delay(40);
}

void finger4() {
  Serial.println("Moved Finger 4");
  myservo7.write(0);
  delay(40);
  finger5(); // Hack for now since 4th finger isn't getting detected
}

void finger5() {
  myservo9.write(180);
}

void finger12() {
  Serial.println("Moved Finger 1 and 2");
  finger1();
  finger2();
}

void finger13() {
  Serial.println("Moved Finger 1 and 3");
  finger1();
  finger3();
}

void finger14() {
  Serial.println("Moved Finger 1 and 4");
  finger1();
  finger4();
}

void finger23() {
  Serial.println("Moved Finger 2 and 3");
  finger2();
  finger3();
}

void finger24() {
  Serial.println("Moved Finger 2 and 4");
  finger2();
  finger4();
}

void finger34() {
  Serial.println("Moved Finger 3 and 4");
  finger3();
  finger4();
}

