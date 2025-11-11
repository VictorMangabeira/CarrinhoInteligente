// Bibliotecas

#include <WiFi.h>
#include <WebServer.h>

// Definições de rede
const char* ssid = "IoY-Senac-Victor";
const char* password = "12345678";
// Configuração do servidor web na porta 80
WebServer server(80);

// Variaveis globais

// Pinos do motor 1, Roda Direita
int motorRodaDireita = 6;
int motorRodaDireira = 7;
const int HABILITA = 11;

// Pinos do motor 2, Roda Esquerda
int motorRodaEsquerda = 8;
int motorRodaEsquerda = 9;
const int HABILITA2 = 10;

// Pagina HTML


// Configurações do Servidor Web
void handleRoot()
{
    server.send(200, "text/html", html);
}

// Funções de controle dos motores

// Função para mover para frente
void handleBotaoFrente()
{
    // Liga os motores para mover para frente
    digitalWrite(HABILITA, HIGH);
    digitalWrite(HABILITA2, HIGH);
    // Roda Direita para frente
    digitalWrite(motorRodaDireita, HIGH);
    digitalWrite(motorRodaDireira, LOW);
    // Roda Esquerda para frente
    digitalWrite(motorRodaEsquerda, HIGH);
    digitalWrite(motorRodaEsquerda, LOW);
    // Envia resposta ao cliente/servidor
    server.send(200, "text/html", html);
}

// Função para mover para trás
void handleBotaoTras()
{
    // Liga os motores para mover para trás
    digitalWrite(HABILITA, HIGH);
    digitalWrite(HABILITA2, HIGH);
    // Roda Direita para trás
    digitalWrite(motorRodaDireita, LOW);
    digitalWrite(motorRodaDireira, HIGH);
    // Roda Esquerda para trás
    digitalWrite(motorRodaEsquerda, LOW);
    digitalWrite(motorRodaEsquerda, HIGH);
    // Envia resposta ao cliente/servidor
    server.send(200, "text/html", html);
}

// Função para virar à direita
void handleBotaoDireita()
{
    // Liga os motores para virar à direita
    digitalWrite(HABILITA, HIGH);
    digitalWrite(HABILITA2, HIGH);
    // Roda Direita para trás
    digitalWrite(motorRodaDireita, LOW);
    digitalWrite(motorRodaDireira, HIGH);
    // Roda Esquerda para frente
    digitalWrite(motorRodaEsquerda, HIGH);
    digitalWrite(motorRodaEsquerda, LOW);
    // Envia resposta ao cliente/servidor
    server.send(200, "text/html", html);
}

// Função para virar à esquerda
void handleBotaoEsquerda()
{
    // Liga os motores para virar à esquerda
    digitalWrite(HABILITA, HIGH);
    digitalWrite(HABILITA2, HIGH);
    // Roda Direita para frente
    digitalWrite(motorRodaDireita, HIGH);
    digitalWrite(motorRodaDireira, LOW);
    // Roda Esquerda para trás
    digitalWrite(motorRodaEsquerda, LOW);
    digitalWrite(motorRodaEsquerda, HIGH);
    // Envia resposta ao cliente/servidor
    server.send(200, "text/html", html);
}

// Função para parar os motores
void handleBotaoParar()
{
    // Desliga os motores para parar
    digitalWrite(HABILITA, LOW);
    digitalWrite(HABILITA2, LOW);
    // Envia resposta ao cliente/servidor
    server.send(200, "text/html", html);
}


// Configuração do Setup/Inicialização
void setup()
{
    // Inicializa os pinos dos motores como saída
    pinMode(motorRodaDireita, OUTPUT);
    pinMode(motorRodaDireira, OUTPUT);
    pinMode(HABILITA, OUTPUT);
    pinMode(motorRodaEsquerda, OUTPUT);
    pinMode(motorRodaEsquerda, OUTPUT);
    pinMode(HABILITA2, OUTPUT);

    // Inicia a comunicação serial
    Serial.begin(115200);

    // Conecta-se à rede Wi-Fi
    WiFi.softAP(ssid, password);
    Serial.print("Conectando-se à rede Wi-Fi");
   

    // Inicia o ponto de acesso do servidor web
    server.begin();
    Serial.println("Servidor web iniciado.");

    // Exibindo o IP do servidor
    Serial.ptint("IP do servidor");
    Serail.println(WiFi.softAPIP());

    // Definindo rotas do servidor
    server.on("/", handleRoot);

    // Rota dos botoes de controle dos motores
    server.on(/"frente", handleBotaoFrente);
    server.on(/"tras", handleBotaoTras);
    server.on(/"direita", handleBotaoDireita);
    server.on(/"esquerda", handleBotaoEsquerda);
    server.on(/"parar", handleBotaoParar);

    // Inicia o servidor web
    server.begin();
    Serial.println("Servidor web iniciado.");

}

// Loop principal
void loop()
{
    server.handleClient();
}