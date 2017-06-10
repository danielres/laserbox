#include <SoftTimer.h>
#include <DelayRun.h>
#include <Servo.h>
Servo myservo;

// servo
float pos;
int minDeg = 30;
int maxDeg = 150;
float servoDir = 1;

// lasers
#define LA1 1
#define LA2 2
#define LA3 3
#define LA4 4
#define LA5 5
#define LA6 6
#define LA7 7

// tasks: lasers
boolean turnOn1  (Task* task) { digitalWrite(LA1, HIGH); return true; }
boolean turnOff1 (Task* task) { digitalWrite(LA1,  LOW); return true; }
DelayRun onTask1 (1000, turnOn1);
DelayRun offTask1(2000, turnOff1, &onTask1);

boolean turnOn2  (Task* task) { digitalWrite(LA2, HIGH); return true; }
boolean turnOff2 (Task* task) { digitalWrite(LA2,  LOW); return true; }
DelayRun onTask2 (1200, turnOn2);
DelayRun offTask2(2000, turnOff2, &onTask2);


// tasks: servo
boolean servoMove (Task* task) {
  servoDir =  myservo.read() < 30 ? 1 : myservo.read() > 150 ? -1 : servoDir;
  pos = myservo.read() + servoDir;
  Serial.println((int) pos, DEC);
  myservo.write((int) pos);
  return true;
}
DelayRun servoMoveTask(500, servoMove, &servoMoveTask);

void setup() {
  Serial.begin(9600);

  myservo.attach(9);

  pinMode(LA1, OUTPUT);
  pinMode(LA2, OUTPUT);

  onTask1.followedBy = &offTask1;
  onTask2.followedBy = &offTask2;

  onTask1.startDelayed();
  onTask2.startDelayed();

  servoMoveTask.followedBy = &servoMoveTask;
  servoMoveTask.startDelayed();
}


// #include <SoftTimer.h>
// #include <DelayRun.h>

// // //// lasers
// int la1 = 2;
// int la2 = 3;
// int la3 = 4;
// int la4 = 5;
// int la5 = 6;
// int la6 = 7;
// int la7 = 8;

// void  on1(Task* me) { digitalWrite(la1, HIGH); }
// void off1(Task* me) { digitalWrite(la1,  LOW); }
// void  on2(Task* me) { digitalWrite(la2, HIGH); }
// void off2(Task* me) { digitalWrite(la2,  LOW); }

// Task  ton1(2000,  on1);
// Task toff1(1111, off1);
// DelayRun Task  ton2(2000,  on2);
// DelayRun Task toff2(1111, off2);

// void laAnim1() {
//   SoftTimer.add(&ton1);
//   SoftTimer.add(&toff1);
//   SoftTimer.add(&ton2);
//   SoftTimer.add(&toff2);
// }
// void setup() {
//   pinMode(la1, OUTPUT);
//   pinMode(la2, OUTPUT);
//   laAnim1();
// }


// ----

// #include <Servo.h>
// #include <SoftTimer.h>
// #include <BlinkTask.h>

// Servo myservo;

// // servo
// int pos = 0;
// int minDeg = 90;
// int maxDeg = 100;

// // -- On for 200ms off for 100ms, repeat it 2 times, sleep for 2000 ms and than start again.

// //BlinkTask hartbeat(la1, 800, 800, 2, 20);
// //BlinkTask hartbeat2(la1, 100, 20, 8, 800);
// //
// //BlinkTask hartbeat3(la2, 800, 800, 4, 40);
// //BlinkTask hartbeat4(la2, 100, 20, 8, 800);

// void laAnim1() {
//   digitalWrite(la1, HIGH);
//   digitalWrite(la2, HIGH);
//   digitalWrite(la3, HIGH);
//   digitalWrite(la4, HIGH);
//   digitalWrite(la5, HIGH);
//   digitalWrite(la6, HIGH);
//   digitalWrite(la7, HIGH);
// }

// Task t1(10, laAnim1);

// void setup() {
//   SoftTimer.add(&t1);

// //  hartbeat.start();
// //  hartbeat2.start();
// //  hartbeat3.start();
// //  hartbeat4.start();
// }




// ------------------------

//#include <Servo.h>
//
//Servo myservo;
//
//// servo & lasers
//int pos = 0;
//int minDeg = 90;
//int maxDeg = 100;
//int delayBase = 30;
//
//
//void setup() {
//  Serial.begin(9600);
//  myservo.attach(9);
//  pinMode(la1, OUTPUT);
//  pinMode(la2, OUTPUT);
//  pinMode(la3, OUTPUT);
//  pinMode(la4, OUTPUT);
//  pinMode(la5, OUTPUT);
//  pinMode(la6, OUTPUT);
//  pinMode(la7, OUTPUT);
//}
//
//void fadeIn(int ledPinNum) {
//  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 1) {
//    analogWrite(ledPinNum, fadeValue);
//  }
//}
//
//void fadeOut(int ledPinNum) {
//  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 1) {
//    analogWrite(ledPinNum, fadeValue);
//  }
//}
//
//void laAnim() {
//    digitalWrite(la1, HIGH);
//    digitalWrite(la2, HIGH);
//    digitalWrite(la3, HIGH);
//    digitalWrite(la4, HIGH);
//    digitalWrite(la5, HIGH);
//    digitalWrite(la6, HIGH);
//    digitalWrite(la7, HIGH);
//}
//
//void sweepAnim() {
//
//    for (pos = minDeg; pos <= maxDeg; pos += 1) {
//      myservo.write(pos);
//      delay(delayBase * 2);
//    }
//
//    for (pos = maxDeg; pos >= minDeg; pos -= 1) {
////      Serial.println(pos, DEC);
//      myservo.write(pos);
//      delay(delayBase * 2);
//    }
//}
//
//
//void loop() {
//  laAnim();
//  sweepAnim();
//}
//
//
//

