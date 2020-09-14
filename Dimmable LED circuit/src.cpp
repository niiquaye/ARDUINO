void BUTTON_ONE();
void BUTTON_TWO();
const int buttonPin1 = 9;
const int buttonPin2 = 8;
const int LED = 5;
int newButton1;
int oldButton1 = 1;
int newButton2;
int oldButton2 = 1;
int i =0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  newButton1 = digitalRead(buttonPin1);
  newButton2 = digitalRead(buttonPin2);
  Serial.println(newButton1);
  Serial.print(newButton2);
  BUTTON_ONE();
  BUTTON_TWO();
  
}


void BUTTON_ONE (){
  
if(newButton1 == 1 && oldButton1 == 0){
    
    if ( i< 255){
      analogWrite(LED,i+=10);
    }
    else{
      digitalWrite(LED, HIGH);
    }
      
  }
  oldButton1 = newButton1;

  
}

void BUTTON_TWO (){

 if(newButton2 == 1 && oldButton2 == 0){

    if(i > 0){
      analogWrite(LED, i-=10);
    }
    else{
      digitalWrite(LED, LOW);
    }
    
  }
  oldButton2 = newButton2;
 
}


