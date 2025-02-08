void readSensor(){
  s1 = analogRead(A1);
  s2 = analogRead(A2);
  s3 = analogRead(A3);
  s4 = analogRead(A4);

  s7 = analogRead(A7);
  s8 = analogRead(A8);

  // Serial.println(String(s1) + " " + String(s2) + " " + String(s3) + " " + String(s4));

  // ดำ = 0, ขาว = 1
  if(s1 < 2000) s1 = 0; else s1 = 1;
  if(s2 < 2000) s2 = 0; else s2 = 1;
  if(s3 < 2000) s3 = 0; else s3 = 1;
  if(s4 < 2000) s4 = 0; else s4 = 1;
  
  if(s7 < 2000) s7 = 0; else s7 = 1;
  if(s8 < 2000) s8 = 0; else s8 = 1;

  Serial.println(String(s1) + " " + String(s2) + " " + String(s3) + " " + String(s4));

}