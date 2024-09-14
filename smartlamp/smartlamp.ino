// Defina os pinos de LED e LDR
// Defina uma variável com valor máximo do LDR (4000)
// Defina uma variável para guardar o valor atual do LED (10)
int ledPin = 23;
int ledValue = 255;
int ldrPin = 22;
int ldrMax = 255;
// Faça testes no sensor ldr para encontrar o valor maximo e atribua a variável ldrMax

int SET_LED(int Intensity)
{
    int output;
    if (0 < Intensity > 100)
    {
        digitalWrite(ledPin, Intensity);
        output=1;
    } else {
        output=-1;
        Serial.println('ERR Unknown command');
    }
    return output;
}

int GET_LED()
{
    return digitalRead(ledPin);
}

void GET_LDR()
{
    return digitalRead(ldrPin);
}

void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(ldrPin, INPUT);
    Serial.printf("SmartLamp Initialized.\n");
}

// Função loop será executada infinitamente pelo ESP32
void loop()
{
    digitalWrite(ledPin, LOW);
    Serial.begin(115200);
    delay(5000);
    digitalWrite(ledPin, HIGH);
    int ldr = digitalRead(ldrPin);
    Serial.println(String(ldr) + '\n');
}

void processCommand(String command)
{
    // compare o comando com os comandos possíveis e execute a ação correspondente
}

// Função para atualizar o valor do LED
void ledUpdate()
{
    // Valor deve convertar o valor recebido pelo comando SET_LED para 0 e 255
    // Normalize o valor do LED antes de enviar para a porta correspondente
}

// Função para ler o valor do LDR
int ldrGetValue()
{
    // Leia o sensor LDR e retorne o valor normalizado entre 0 e 100
    // faça testes para encontrar o valor maximo do ldr (exemplo: aponte a lanterna do celular para o sensor)
    // Atribua o valor para a variável ldrMax e utilize esse valor para a normalização
}