#include <POP32.h>

int mainSpeed = 15;     // Speed สำหรับวิ่งไปชนขอบดำ
int Speed_for_cm = 55;  // Speed สำหรับวิ่งตามระยะทางที่กำหนด

int tune_m1;
int tune_m2;
int tune_m3;
int tune_m4;

int s1;
int s2;
int s3;
int s4;

int s7;
int s8;



//-----------------------------------------------< setup >
void setup() {
  Serial.begin(9600);
  pinSetup();

  waitSW_OK();
  beep();
  delay(1500);

  // forward_cm(Speed_for_cm, 60.0);
  // turnR_90();

  // *** ตัวอย่างคำสั่งที่ใช้ได้
    // turnL_90();
    // turnR_90();
    // forward_cm(Speed_for_cm, 5.8);
    // backward_cm(Speed_for_cm, 5.8);
    // foundWall(mainSpeed, "R");
    // pushBlock();

  // *** ตัวอย่าง ตามภาพที่ส่งให้
  // ---- ลูกศรสีแดง (ขาไป)
  forward_cm(Speed_for_cm, 90.0);
  foundWall(mainSpeed, "R");
  forward_cm(Speed_for_cm, 60.0);
  foundWall(mainSpeed, "R");
  forward_cm(Speed_for_cm, 30.0);
  foundWall(mainSpeed, "R");
  forward_cm(Speed_for_cm, 30.0);
  foundWall(mainSpeed, "L");
  forward_cm(Speed_for_cm, 60.0);
  pushBlock();
  backward_cm(Speed_for_cm, 30.0);
  turnL_90();
  // foundWall(mainSpeed, "R");          // 🔴 start -> 1
  // foundWall(mainSpeed, "R");          // 1 -> 2
  // foundWall(mainSpeed, "R");          // 2 -> 3
  // foundWall(mainSpeed, "L");          // 3 -> 4
  // forward_cm(Speed_for_cm, 60.0);     // 4 -> 5
  // pushBlock();                        // *** 🟢 ปล่อยกล่อง 1
  // backward_cm(Speed_for_cm, 30.0);    // 5 -> 6
  // turnL_90();                         // (ลืมเขียนเลขในภาพ)
  // forward_cm(Speed_for_cm, 60.0);     // 6 -> 7
  // turnR_90();                         // 8    
  // backward_cm(Speed_for_cm, 60.0);    // 8 -> 9
  // forward_cm(Speed_for_cm, 90.0);     // 9 -> 10  ในภาพคือวิ่งให้ชนขอบ แต่ลืมไปว่าถ้าหมุนแล้ว จะไม่มีขอบข้างหลังใช้เช็ค เลยเป็นวิ่งแบบระยะแทน
  // turnR_90();                         // (ลืมเขียนเลขในภาพ)
  // forward_cm(Speed_for_cm, 60.0);     // 10 -> 11
  // pushBlock();                        // *** 🟢 ปล่อยกล่อง 2
  // turnL_90();                         // 12
  // turnL_90();                         // 12 หมุนอีกรอบ เพราะอยากกลับรถ
  // foundWall(mainSpeed, "L");          // 12 -> 13
  // forward_cm(Speed_for_cm, 60.0);     // 13 -> 14
  // turnR_90();                         // 15
  // foundWall(mainSpeed, "R");          // 15 -> 16 -> 17 
  //                                     // * วิ่งไปเรืื่อยๆเพื่อชนขอบ (ถ้าวิ่งแบบระยะ กลัววิ่งบนตะเกียบแล้วระยะจะคลาดเคลื่อน)
  //                                     // * ชนขอบแล้วหมุนขวา เมื่อหมุนแล้ว จาก Code เราจะให้ถอย ซึ่งหุ่นจะถอยไป จุดที่ 17 เอง
  // turnR_90();                         // (ลืมเขียนเลขในภาพ)
  // forward_cm(Speed_for_cm, 30.0);     // 17 -> 18
  // pushBlock();                        // *** 🟢 ปล่อยกล่อง 3
  // backward_cm(Speed_for_cm, 30.0);    // 19 -> 20
  // turnL_90();                         // 20
  // forward_cm(Speed_for_cm, 90.0);     // 20 -> 21
  // pushBlock();                        // *** 🟢 ปล่อยกล่อง 4
  // backward_cm(Speed_for_cm, 30.0);    // 21 -> 22
  // turnR_90();                         // 23
  // forward_cm(Speed_for_cm, 30.0);     // 23 -> 24
  // backward_cm(Speed_for_cm, 30.0);    // 24 -> 25
  // turnR_90();                         // 26
  // forward_cm(Speed_for_cm, 30.0);     // 26 -> 27
  // turnL_90();                         // 28

  // // ---- ลูกศรสีม่วง (ขากลับ)
  // foundWall(mainSpeed, "L");          // 28 -> 29 -> 30 
  //                                     // * วิ่งไปเรืื่อยๆเพื่อชนขอบ (ถ้าวิ่งแบบระยะ กลัววิ่งบนตะเกียบแล้วระยะจะคลาดเคลื่อน)
  //                                     // * ชนขอบแล้วหมุนซ้าย เมื่อหมุนแล้ว จาก Code เราจะให้ถอย ซึ่งหุ่นจะถอยไป จุดที่ 30 เอง
  // turnR_90();                         // (ลืมเขียนเลขในภาพ)
  // foundWall(mainSpeed, "L");          // 30 -> 31
  // forward_cm(Speed_for_cm, 60.0);     // 31 -> 32
  // turnR_90();                         // (ลืมเขียนเลขในภาพ)
  // forward_cm(Speed_for_cm, 60.0);     // 32 -> 33 (ในภาพคือวิ่งเช็คกำแพง แต่กลัวว่าถ้าชนกำแพง > หมุน > ถอย จะถอยไปโดนพื้นสีเขียว แล้วบัค)
  // turnR_90();                         // (ลืมเขียนเลขในภาพ)
  // foundWall(mainSpeed, "R");          // 33 -> 34
  // foundWall(mainSpeed, "L");          // 34 -> 35
  // foundWall(mainSpeed, "L");          // 35 -> 36
  // foundWall(mainSpeed, "L");          // 36 -> 37
  // forward_cm(Speed_for_cm, 90.0);     // 37 -> 38
  //                                     // 🏆🎉 End 🎊🏅
} 

//-----------------------------------------------< loop >
void loop() {
  // readSensor();
}
