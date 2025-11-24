🧱 Projeto IoT – Mão na Massa

Protótipo IoT desenvolvido como parte da Global Solution FIAP 2025.

Este projeto implementa um protótipo IoT utilizando ESP32 + Node-RED para monitorar, em tempo real, o número de alunos estudando dentro da plataforma Mão na Massa, focada na capacitação de profissionais de ofícios manuais.

📌 1. Objetivo do Projeto

Simular check-in e check-out de alunos usando um ESP32.
Enviar eventos via HTTP (JSON) para o Node-RED.
Processar a lógica de presença no Function Node.
Exibir o número de pessoas estudando em um dashboard em tempo real.
Demonstrar como IoT pode apoiar a formação contínua e o Futuro do Trabalho.

🧰 2. Tecnologias Utilizadas

ESP32 DevKit (simulado via Wokwi)
Botão (GPIO 13)
LED interno (GPIO 2)
Node-RED
node-red-dashboard
Protocolo HTTP
JSON

📡 3. Funcionamento da Solução
3.1 ESP32 (Wokwi)

O ESP32 envia eventos conforme o botão é pressionado:

check-in

{ "deviceId": "esp32-mnm", "tipo": "checkin" }


check-out

{ "deviceId": "esp32-mnm", "tipo": "checkout" }


O LED indica visualmente se o aluno está estudando.

🔧 4. Fluxo Node-RED

Fluxo completo:

POST /iot/checkin → JSON → Function → Gauge
                                    ↘ Chart
                                    ↘ HTTP Response

4.1 Código do Function Node
let count = flow.get('count') || 0;
let evento = msg.payload;

if (evento.tipo === "checkin") {
    count++;
}

if (evento.tipo === "checkout" && count > 0) {
    count--;
}

flow.set('count', count);
msg.payload = count;

return msg;

📊 5. Dashboard

O dashboard exibe:

Gauge → Pessoas estudando agora

Chart → Histórico em tempo real

Acessível via:

👉 http://localhost:1880/ui

🧪 6. Como Executar
6.1 Node-RED
node-red


Acesse:
http://localhost:1880

6.2 ESP32 no Wokwi

Abrir o projeto

Clicar Play

Pressionar o botão

Acompanhar atualizações no dashboard

📁 7. Estrutura do Repositório
📦 mao-na-massa-iot
 ├── sketch.ino
 ├── diagram.json
 ├── flow-node-red.json
 ├── README.md
 └── imagens/

🎥 8. Vídeo da Apresentação

Link do vídeo: (adicionar após subir)

👤 9. Autores

Gabriel Santos
Thomas Baute
Bruno Matheus
FIAP – Global Solution 2025
