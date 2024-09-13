

// Defina os pinos de LED e LDR
// Defina uma variável com valor máximo do LDR (4000)
// Defina uma variável para guardar o valor atual do LED (10)
const int ledPin = 23;
int ledValue = 255;
int ldrPin = 22;
int ldrMax = 255;

void SET_LED(int X){
  if ( X > 0 & X < 255){
    digitalWrite(ledPin, X);
    } 
  }

int GET_LED(){
  return ledValue;
  }

void GET_LDR(){
  }
  
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  
  
}

  
void loop() {
    digitalWrite(ledPin,LOW);
    Serial.begin(115200);
    delay(5000);
    digitalWrite(ledPin,HIGH);
    int ldr = digitalRead(ldrPin);
    Serial.println(String(ldr) + '\n');
    
    
}
