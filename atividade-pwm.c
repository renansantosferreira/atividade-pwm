#include <stdio.h>          // Para funções de entrada/saída (printf)
#include "pico/stdlib.h"    // Biblioteca padrão do Pico SDK (GPIO, delays, etc.)
#include "hardware/pwm.h"   // Biblioteca para controle de PWM


// Definição da GPIO do servo
#define SERVO_PIN 22
//#define SERVO_PIN 12  //Definição caso seja utilizado a Placa BitDogLab.

#define PWM_FREQ 50        // Frequência de 50Hz (período de 20ms)
#define PWM_WRAP 20000     // Contagem total para 20ms (em microssegundos)

// Função para configurar o PWM na GPIO do servo
void setup_pwm(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);  // Define a função PWM na GPIO
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_wrap(slice_num, PWM_WRAP);       // Define o contador do PWM
    pwm_set_clkdiv(slice_num, 125.0f);       // Ajusta o clock para microssegundos (125MHz / 125 = 1MHz)
    pwm_set_enabled(slice_num, true);        // Habilita o PWM
}

// Função para definir o ciclo ativo do PWM em microssegundos
void set_servo_pulse(uint gpio, uint pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_gpio_level(gpio, pulse_width_us); // Ajusta o ciclo ativo diretamente
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    setup_pwm(SERVO_PIN); // Configura o PWM na GPIO 22

    while (true) {
        // Move para 180 graus (2.400 µs)
        set_servo_pulse(SERVO_PIN, 2400);
        printf("Servo em 180 graus\n");
        sleep_ms(5000);

        // Move para 90 graus (1.470 µs)
        set_servo_pulse(SERVO_PIN, 1470);
        printf("Servo em 90 graus\n");
        sleep_ms(5000);

        // Move para 0 graus (500 µs)
        set_servo_pulse(SERVO_PIN, 500);
        printf("Servo em 0 graus\n");
        sleep_ms(5000);

        // Movimentação suave entre 0° e 180°
        printf("Movimentação suave de 0 a 180 graus...\n");
        for (uint i = 500; i <= 2400; i += 5) {
            set_servo_pulse(SERVO_PIN, i);
            sleep_ms(10);
        }

        printf("Movimentação suave de 180 a 0 graus...\n");
        for (uint i = 2400; i >= 500; i -= 5) {
            set_servo_pulse(SERVO_PIN, i);
            sleep_ms(10);
        }
    }
}
