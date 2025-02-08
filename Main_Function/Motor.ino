void tuneMotor(int speed){
  tune_m1 = speed - 1;  // L top
  tune_m2 = speed - 0;  // R top
  tune_m3 = speed - 1;  // L bottom
  tune_m4 = speed - 0;  // R bottom
}

//------------------------------------------------------< normal forward & backward >
void forward(int speed){
  tuneMotor(speed);
  motor(1, tune_m1);
  motor(2, tune_m2);
  motor(3, tune_m3);
  motor(4, tune_m4);
}
void backward(int speed){
  tuneMotor(speed);
  motor(1, -tune_m1);
  motor(2, -tune_m2);
  motor(3, -tune_m3);
  motor(4, -tune_m4);
}


//------------------------------------------------------< forward with time>
void forward(int speed, int time){
  tuneMotor(speed);
  motor(1, tune_m1);
  motor(2, tune_m2);
  motor(3, tune_m3);
  motor(4, tune_m4);

  delay(time);

  stop();
}

//------------------------------------------------------< backward with time>
void backward(int speed, int time){
  tuneMotor(speed);
  motor(1, -tune_m1);
  motor(2, -tune_m2);
  motor(3, -tune_m3);
  motor(4, -tune_m4);

  delay(time);

  stop();
}

//------------------------------------------------------< stop >
void stop(){
  motor_stop(1);
  motor_stop(2);
  motor_stop(3);
  motor_stop(4);
}