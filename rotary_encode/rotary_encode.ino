//600pなので600で1回転

char encoder_a = 2; //エンコーダのA相
char encoder_b = 3; //エンコーダのB相
int encoder_cnt = 0; //カウントアップ用変数
int before_cnt = 0; //以前のカウンタ

void setup() {
  pinMode(encoder_a, INPUT_PULLUP); //A相用入力、プルアップに設定
  pinMode(encoder_b, INPUT_PULLUP); //B相用入力、プルアップに設定
  attachInterrupt(digitalPinToInterrupt(encoder_a), encoder_pulse, RISING); //割り込みを設定
  Serial.begin(19200);
}

void loop() {
  Serial.println(enocer_judge(encoder_cnt)); //カウントをシリアルで送る
  encoder_cnt %= 600; //600pのため600で切り捨て
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

//増加か減少かを測る関数
int enocer_judge(int now_cnt) {
  if (before_cnt < now_cnt) {
    return 1;
  }
  else {
    return -1;
  }
  before_cnt = now_cnt;
}
