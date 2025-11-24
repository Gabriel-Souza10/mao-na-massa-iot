# 🧱 Projeto IoT – Mão na Massa  
Protótipo IoT desenvolvido como parte da Global Solution FIAP 2025.

Este projeto implementa um protótipo IoT simples utilizando **ESP32 + Node-RED** para monitorar, em tempo real, o número de alunos estudando dentro da plataforma *Mão na Massa*, que tem como foco a capacitação de profissionais de ofícios manuais.

---

## 📌 1. Objetivo do Projeto
Criar uma solução IoT capaz de:

- Simular **check-in** e **check-out** de alunos;
- Enviar eventos via **HTTP** usando JSON;
- Processar os dados no **Node-RED**;
- Exibir em um dashboard o número de pessoas estudando em tempo real;
- Registrar o histórico desses dados em um gráfico;
- Demonstrar como IoT pode apoiar o aprendizado contínuo e o Futuro do Trabalho.

---

## 🧰 2. Tecnologias Utilizadas

### **Simulação e Dispositivo**
- ESP32 DevKit (Wokwi)
- Botão (GPIO 13)
- LED interno (GPIO 2)

### **Gateway e Dashboard**
- Node-RED
- node-red-dashboard
- Protocolo HTTP
- JSON

---

## 📡 3. Funcionamento da Solução

### **3.1 ESP32 (Wokwi)**
O ESP32 utiliza um botão para simular o início/término de estudo:
- Botão pressionado → **check-in**
- Botão solto → **check-out**
- LED indica se o aluno está estudando

Eventos enviados:

```json
{ "deviceId": "esp32-mnm", "tipo": "checkin" }
