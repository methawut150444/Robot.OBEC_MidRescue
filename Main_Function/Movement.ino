
//------------------------------------------------------< Rotation >
/*
  turn = หมุนรอบตัว
  drift = เลี้ยว ตีโค้ง
*/

void turnL_90() {
  int s = 50;
  motor(1, -s);  // L
  motor(2, s);   // R
  motor(3, -s);  // L
  motor(4, s);   // R

  delay(500);   // ************************************ ปรับให้หมุน 90 องศา
  stop();
  delay(300);
}

void turnR_90() {
  int s = 50;
  motor(1, s);   // L
  motor(2, -s);  // R
  motor(3, s);   // L
  motor(4, -s);  // R

  delay(500);    // ************************************ ปรับให้หมุน 90 องศา
  stop();
  delay(300);
}

void DriftL() {
  int s = 50;
  motor(1, 0);  // L
  motor(2, s);  // R
  motor(3, 0);  // L
  motor(4, s);  // R
}
void DriftR() {
  int s = 50;
  motor(1, s);  // L
  motor(2, 0);  // R
  motor(3, s);  // L
  motor(4, 0);  // R
}

void back_DriftL() {
  int s = 50;
  motor(1, 0);  // L
  motor(2, -s);  // R
  motor(3, 0);  // L
  motor(4, -s);  // R
}
void back_DriftR() {
  int s = 50;
  motor(1, -s);  // L
  motor(2, 0);  // R
  motor(3, -s);  // L
  motor(4, 0);  // R
}
//------------------------------------------------------< move with distance >
void forward_cm(int Speed, float distance) {
  // Speed: % -> RPM -> cm/s
  float tune_distance = 5.7;
  float sum_distance = distance + tune_distance;
  float wheelRadius = 3.3 / 2;       //3.3 รัสมีล้อของหุ่นยนต์
  float C = 2 * 3.14 * wheelRadius;  //เส้นรอบวงล้อ

  int RPM = (1000 * Speed) / 100;               //จาก % เป็น RPM (เทียบบัญญัติไตรยางค์)
  float V = (RPM * C / 60);                     //จาก % เป็น V //หาเวลา
  int time = round((sum_distance / V) * 1000);  // t = s/v, t * 1000 -> s to ms

  // Serial.println("time: " + String(time));

  forward(Speed, time);
}

void backward_cm(int Speed, float distance) {
  // Speed: % -> RPM -> cm/s
  float tune_distance = 5.7;
  float sum_distance = distance + tune_distance;
  float wheelRadius = 3.3 / 2;       //3.3 รัสมีล้อของหุ่นยนต์
  float C = 2 * 3.14 * wheelRadius;  //เส้นรอบวงล้อ

  int RPM = (1000 * Speed) / 100;               //จาก % เป็น RPM (เทียบบัญญัติไตรยางค์)
  float V = (RPM * C / 60);                     //จาก % เป็น V //หาเวลา
  int time = round((sum_distance / V) * 1000);  // t = s/v, t * 1000 -> s to ms

  // Serial.println("time: " + String(time));

  backward(Speed, time);
}

//------------------------------------------------------< foundWall >
void foundWall(int Speed, String Rotation) {
  int backward_distance = 6.4;    // ************************************ ปรับระยะ ให้เวลาชนขอบแล้ว *ถอย* ให้กลางหุ่นตรงกับกลางสนาม
  int forward_distance = 6.5;     // ************************************ ปรับระยะ ให้เวลาชนขอบแล้ว *ขึ้นหน้า* ให้กลางหุ่นตรงกับกลางสนาม
  int tuneDelay = 30;             // ************************************ ปรับเวลาตอนที่หุ่นมันชนขอบแล้วเลี้ยวล้อให้ตรง 

  // ✅ step -------> 1 move
  readSensor();
  while (s1 == 1 && s2 == 1) {
    forward(Speed);
    readSensor();
  }
  stop();
  delay(300);

  // ✅ step -------> 2 tune
  readSensor();
  if(s1 == 0 && s2 == 1){
    readSensor();
    while(s2 == 1){
      DriftL();
      readSensor();
    }
  }
  else if(s1 == 1 && s2 == 0){
    readSensor();
    while(s1 == 1){
      DriftR();
      readSensor();
    }
  }
  delay(tuneDelay);
  stop();
  delay(100);
  backward_cm(Speed_for_cm, backward_distance);

  // ✅ step -------> 3 turn
  if (Rotation == "R") {
    turnR_90();
  } 
  else if (Rotation == "L") {
    turnL_90();
  }

  // ✅ step -------> 4 move
  readSensor();
  while (s3 == 1 && s4 == 1) {
    backward(Speed);
    readSensor();
  }
  stop();
  delay(300);


  // ✅ step -------> 5 tune
  readSensor();
  if(s3 == 0 && s4 == 1){
    readSensor();
    while(s4 == 1){
      back_DriftL();
      readSensor();
    }
  }
  else if(s3 == 1 && s4 == 0){
    readSensor();
    while(s3 == 1){
      back_DriftR();
      readSensor();
    }
  }
  delay(tuneDelay);
  stop();
  delay(100);
  forward_cm(Speed_for_cm, forward_distance);
}
