//600pなので600で1回転

char encoder_a = 2; //エンコーダのA相
char encoder_b = 3; //エンコーダのB相
bool encoder_cnt = false; //カウントアップ用変数

void setup() {
  pinMode(encoder_a, INPUT_PULLUP); //A相用入力、プルアップに設定
  pinMode(encoder_b, INPUT_PULLUP); //B相用入力、プルアップに設定
  attachInterrupt(digitalPinToInterrupt(encoder_a), encoder_pulse, RISING); //割り込みを設定
  Serial.begin(19200);
}

void loop() {
  delay(10);
}

void encoder_pulse() {
  //立ち上がり時にlowだったら逆転
  if (digitalRead(encoder_b) == 0) { 
    Serial.println(-1); //カウントをシリアルで送る
    delayMicroseconds(10000);
  }
  //highだったら正転
  else if (digitalRead(encoder_b) == 1) {
    Serial.println(1); //カウントをシリアルで送る
    delayMicroseconds(10000);
  }
}
