/*스위치 바운싱 현상 해결 방법 */
const int BUTTON = 2; // 버튼은 2번핀에
const int LED = 13; // LED는 13번에

boolean lastButton = LOW; // 이전 버튼 눌림 상태
boolean currentButton = LOW; // 현재 버튼 눌림 상태
boolean ledOn = true; // 현재 LED 점멸 상태

int buttonstate = 0; // 플로팅 상태 확인

// 디바운싱 알고리즘
boolean debounce(boolean last) // last 상태가 입력되고 함수호출
{
  boolean current = digitalRead(BUTTON); // 버튼상태 측정
  if(last!= current) // last와 current가 다르다면
  {
    delay(5); // 디바운싱 고려하여 5ms후에
    current = digitalRead(BUTTON); // 버튼상태 다시 측정
  }
  return current; // current 상태 반환
}

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH)
  {
    ledOn =!ledOn; // LED 점멸 상태 전환
  }
  lastButton = currentButton;
  
  digitalWrite(LED, ledOn);

  buttonstate = digitalRead(2);
  Serial.print("Buttonstate =");
  Serial.println(buttonstate);
}
