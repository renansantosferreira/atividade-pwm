# Controle de Servo Motor com Raspberry Pi Pico W 

## Descrição
Este projeto implementa o controle de um **servo motor** utilizando **PWM** no **Raspberry Pi Pico W**. O código é escrito em **C** e usa o **Pico SDK** para configurar o PWM na **GPIO 22**.

Caso não tenha o motor e queira testar usando o Led na Placa Bit Do Lab

Este projeto implementa o controle de um **servo motor** utilizando **PWM** no **Raspberry Pi Pico W**. O código é escrito em **C** e usa o **Pico SDK** para configurar o PWM na LED **GPIO 12**.

## Funcionalidades
- Configura a **frequência do PWM** para **50Hz** (período de 20ms).
- Move o servo motor para as posições **0°, 90° e 180°**, aguardando **5 segundos** em cada.
- Implementa uma **movimentação suave** entre **0° e 180°**, incrementando o ciclo ativo do PWM em **5µs** a cada **10ms**.

## Requisitos
- **Raspberry Pi Pico W**
- **Servo motor** (ex: SG90 ou similar)
- **Ambiente de desenvolvimento com Pico SDK**

## Como Compilar e Executar
1. **Configurar o ambiente do Pico SDK** (caso ainda não tenha feito):  
   - Siga o guia oficial: [Pico SDK](https://github.com/raspberrypi/pico-sdk)
2. **Criar um diretório para o projeto** e copiar os arquivos necessários.
3. **Compilar o código:**

4. **Carregar o arquivo `.uf2`** gerado no Raspberry Pi Pico W.

## Código Fonte
[Clique aqui para acessar o código completo](./atividade-pwm.c)

## Esquemático de Ligação
| Componente | Raspberry Pi Pico W |
|------------|---------------------|
| Servo (VCC) | 3.3V |
| Servo (GND) | GND |
| Servo (Sinal) | GPIO 22 |

caso seja utilizado o led pra testar, pode alterar a porta 22 por porta 12.

[Clique aqui ⬆️ e assista o vídeo](https://youtu.be/xxxxx)


## Autor
Desenvolvido por [Renan Ferreira].

