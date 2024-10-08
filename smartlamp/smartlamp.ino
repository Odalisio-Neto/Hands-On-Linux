#include "DHT.h" // Inclui a biblioteca DHT para leitura de temperatura e umidade

#define DHT_PIN 0 // Define o pino utilizado para o sensor DHT
#define DHT_TYPE DHT11 // Define o tipo do sensor DHT utilizado (DHT11)

int ledPin = 18; // Pino conectado ao LED
int ledValue = 10; // Valor atual do LED (inicialmente 10%)
int tempValue = -1; // Valor da temperatura (inicialmente -1)
int humValue = -1; // Valor da umidade (inicialmente -1)
int ldrPin = 4; // Pino do sensor LDR
int ldrMax = 4000; // Valor máximo do LDR para normalização
int dhtMax = 2000;
DHT dht(DHT_PIN, DHT_TYPE); // Cria uma instância do sensor DHT

void setup() {
    Serial.begin(9600);
    
    pinMode(ledPin, OUTPUT);
    pinMode(ldrPin, INPUT); 
    
    Serial.println("SmartLamp Initialized."); 
 
    dht.begin();
}

void loop() {\
    // Loop para processar os comandos
    if (Serial.available() > 0) {
        String str = Serial.readString(); 
        str.trim(); 
        processCommand(str); 
    }
}

void processCommand(String command) {
    // Compara o comando com os comandos possíveis e executa a ação correspondente
    // Responde com o valor do LDR
    if (command.equals(String("GET_LDR"))){
        Serial.printf("RES GET_LDR %d\n", ldrGetValue());
    }
    // Responde com o valor atual do LED
    else if (command.equals(String("GET_LED"))){
        Serial.printf("RES GET_LED %d\n", ledValue);
    }
    // Responde com o valor da temperatura
    else if (command.equals(String("GET_TEMP"))){
        Serial.printf("RES GET_TEMP %d\n", dhtGetValue());
    }
    // Aqui responde com o valor da umidade
    else if (command.equals(String("GET_HUM"))){
        Serial.printf("RES GET_HUM %d\n", dhtGetValue());
    }
    // Definir o valor do LED
    else if (command.substring(0, 7).equals(String("SET_LED"))){
        int valor_led = command.substring(7).toInt(); // Obtém o valor após "SET_LED"
        // Verifica se o valor está dentro do intervalo permitido
        if (valor_led >= 0 && valor_led <= 100){
            ledUpdate(valor_led); // Atualiza o LED com o novo valor
            Serial.printf("RES SET_LED 1\n"); // Confirma a atualização
        }
        else{
            Serial.printf("RES SET_LED -1\n"); // Responde com erro
        }
    }
}

// Função para atualizar o valor do LED
void ledUpdate(int valor) {
    // Converte o valor recebido pelo comando SET_LED de 0-100 para 0-255
    int valor_led_norm = map(valor, 0, 100, 0, 255); // normaliza o valor
    ledValue = valor; // att o valor do LED
    analogWrite(ledPin, valor_led_norm); // escreve o valor no pino do LED
}   

// Função para ler o valor do LDR
int ldrGetValue() {
    return map(analogRead(ldrPin), 0, ldrMax, 0, 100); // normaliza o valor lido
}


int dhtGetValue(){
  return map(analogRead(DHT_PIN), 0, dhtMax, 0, 100);
}
