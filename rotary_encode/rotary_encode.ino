//600pなので600で1回転

char encoder_a = 2; //エンコーダのA相
char encoder_b = 3; //エンコーダのB相
int encoder_cnt = 0; //カウントアップ用変数

void setup() {
  pinMode(encoder_a, INPUT_PULLUP); //A相用入力、プルアップに設定
  pinMode(encoder_b, INPUT_PULLUP); //B相用入力、プルアップに設定
  attachInterrupt(digitalPinToInterrupt(encoder_a), encoder_pulse, RISING); //割り込みを設定
  Serial.begin(19200);
}

void loop() {
  Serial.println(encoder_cnt); //カウントをシリアルで送る
  delay(10);
}

void encoder_pulse() {
  //立ち上がり時にlowだったら逆転
  if (digitalRead(encoder_b) == 0) { 
    encoder_cnt--;
  }
  //highだったら正転
  else if (digitalRead(encoder_b) == 1) {
    encoder_cnt++;
  }
}
