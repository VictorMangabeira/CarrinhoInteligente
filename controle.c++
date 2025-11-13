/* Carrinho 2.0*/

// Bibliotecas
#include <WiFi.h>
#include <WebServer.h>

// Nome e senha do servidor
const char* AC_SSID = "MCQueen Senna";
const char* AC_PWD = "12345678";

// Portas para controlar o motor A/ Primeiro  motor         
const int in1 = 26;
const int in2 = 27;

// Portas para controlar o motor B; segundo motor
const int in3 = 32;
const int in4 = 33;

// Porta do servidor
WebServer server(80);


// Pagina HTML



//Executa o HTMl, o que mostra ao acessar
void handleRoot()
{
  server.send(200, "text/html", PAGINA);
}

// Controlando pelo celular

// Ir para frente
void motorFrente()
{
  // Primeiro motor
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Segundo motor
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  // Direcionando para a página
  server.send(200, "text/html", PAGINA);
}

// Ir para trás/ré
void motorTras()
{
  // Primeiro motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

   // Segundo motor
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  server.send(200, "text/html", PAGINA);
}


// Controle para esquerda
void motorEsquerda()
{
  // Roda esquerda
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);

  // Roda direita
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// Controle para direita
void motorDireita()
{
    // Roda esquerda
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // Roda direita
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
}

// Parar o motor
void motorParar()
{
  // Primeiro motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

   // Segundo motor
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  server.send(200, "text/html", PAGINA);
}


void setup() 
{
  // Configurando as portas do motor A/ Porta de saida
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Configurando o modo do wifi, ele esta criando sua propria rede
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AC_SSID, AC_PWD);

  // Ativando o serial. o numero e a taxa de atualização
  Serial.begin(115200);
  Serial.println("Criando rede WiFi");
  Serial.print("IP: ");
  // Mostrar a rota/Ip do WIFi
  Serial.println(WiFi.softAPIP());

  // 
  server.on("/", handleRoot);
  server.on("/frente",motorFrente);
  server.on("/tras", motorTras);
  server.on("/parar", motorParar);

  
  // Faz o servidor ficar online
  server.begin();
}

void loop() 
{
  // Mantem o servidor ligado
 server.handleClient();
}