void Switch();
const int bPin = 5;
const int gPin = 6;
const int rPin = 7;
const int yPin = 8;
const int x_Pin = A0;
const int y_Pin = A1;
const int switchPin = 2;
int xValue;
int yValue;
int newSwitchValue;
int oldSwitchValue = 1;
int ledState = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  pinMode(yPin, OUTPUT);
  pinMode(x_Pin, INPUT);
  pinMode(y_Pin, INPUT);
  pinMode(switchPin, INPUT);
  //write HIGH to switchPin in void setup loop for joystick then use like a push button
  digitalWrite(switchPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Switch();
  xValue = analogRead(x_Pin);
  yValue = analogRead(y_Pin);
  
  if(xValue < 100){
    digitalWrite(gPin, HIGH);
    digitalWrite(bPin, LOW);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, LOW); 
  }
  
  else if(xValue > 850){
    digitalWrite(gPin, LOW);
    digitalWrite(bPin, LOW);
    digitalWrite(yPin, HIGH);
    digitalWrite(rPin, LOW); 
  }

  else if (yValue < 100){
    digitalWrite(gPin, LOW);
    digitalWrite(bPin, HIGH);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, LOW); 
  }


  else if (yValue >850  ){
    digitalWrite(gPin, LOW);
    digitalWrite(bPin, LOW);
    digitalWrite(yPin, LOW);
    digitalWrite(rPin, HIGH); 
  }
  Serial.println(newSwitchValue);


}

void Switch (){
  newSwitchValue = digitalRead(switchPin);
  if(oldSwitchValue == 0 && newSwitchValue == 1){
     if (ledState == 1){
      digitalWrite(yPin, HIGH);
      digitalWrite(bPin, HIGH);
      digitalWrite(gPin, HIGH);
      digitalWrite(rPin, HIGH);
      ledState = 0;
     }
     else if (ledState == 0) {
      ledState = 1;
      digitalWrite(yPin, LOW);
      digitalWrite(bPin, LOW);
      digitalWrite(gPin, LOW);
      digitalWrite(rPin, LOW);
     }
    
  }
  oldSwitchValue = newSwitchValue;

  
}


