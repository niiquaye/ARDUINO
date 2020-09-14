const int photoPin = A0;
const int blueLED = 9; 
const int greenLED = 10;
const int redLED = 11;
float rgbValue = 0;
int value = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);
pinMode(blueLED, OUTPUT);
pinMode(photoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(photoPin);
  rgbValue = (255.0/1023.0)*value;
  Serial.println(value);

    if (value <= 341){
      digitalWrite(blueLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
    }
    else if (value <= 682){
      digitalWrite(greenLED, HIGH);
      digitalWrite(blueLED, LOW);
      digitalWrite(redLED, LOW);
    }
    else if (value <= 1023){
       digitalWrite(redLED, HIGH);
       digitalWrite(blueLED,LOW);
       digitalWrite(greenLED, LOW);
    }
  
  //analogWrite(redLED, rgbValue);


}


