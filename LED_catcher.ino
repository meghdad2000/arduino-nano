/* It is a 7 score LED catcher game with arduino nano,seven 220 ohm resistor ,6 red led and 1 green led
 *  code by : Mehrshad Nosrati
 * leds are connnected to D11-D4 with a 220 ohm resister before each one
 * user can connect D2 to 5v of arduino to give D2  5v input which is considered as button
 * every time user can push button on green LED he get a point
 * and LEDs will show his score
 */

int score = 0, wait=85,pushed=-1;;
void setup() {
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
    pushed = goDown();
    pushed = goUp();
  if(pushed != -1){//buttun is pressed
    Serial.println(score);
        if (pushed == 11){
          digitalWrite(2,LOW);
          digitalWrite(11,HIGH);
          delay(100);
          score++;
          digitalWrite(11,LOW);
          showScore(score);
          if(score==7)
          score=0;
        }
  }
}

  int goUp(){
  for(int i = 5; i<12 ;i = i+1){
      digitalWrite(i,HIGH);
      if(digitalRead(2)==HIGH){
        digitalWrite(i,LOW);
        return i;
        }
      delay(wait);
      digitalWrite(i,LOW);
      }
      return -1;
}

int goDown(){
  for(int i = 11 ;i>4; i = i-1){
      digitalWrite(i,HIGH);
      if(digitalRead(2)==HIGH){
        digitalWrite(i,LOW);
        return i;
        }
      delay(wait);
      digitalWrite(i,LOW);
  }
  return -1;
}

void showScore(int score){//and intital game
  for(int j=5; j<score+5;j++){
    digitalWrite(j,HIGH);
    delay(500);
  }
  if(score==7){
    wait=85;
    delay(1000);
  }
  else
  wait = wait-10;
  for(int j=5; j<score+5;j++)
    digitalWrite(j,LOW);
}
