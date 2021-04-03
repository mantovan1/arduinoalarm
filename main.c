const int pingPin = 5;
const int buzzer = 3;
const int pinR = 11;
const int pinG = 10;
const int pinB = 9;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
  long duration, inches, cm;
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  
  duration = pulseIn(pingPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  if(inches<30){
    setColors(255, 0, 0);
    tone(buzzer, 1500);
    delay(50);
    tone(buzzer, 200);
    delay(50);
  } else if(inches<50) {
    setColors(255, 140, 0);
  } else if(inches<60) {
    setColors(255, 255, 0);
  } else {
    setColors(50, 205, 50);
    noTone(buzzer);  
  }
}

void setColors(int r, int g, int b) {
    analogWrite(pinR, r);
    analogWrite(pinG, g);
    analogWrite(pinB, b);
}  

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
