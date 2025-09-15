#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

int main() {
    // Inicializar stdio para printf
    stdio_init_all();
    
    // Configurar el LED integrado (GPIO 25 en Pico, GPIO 0 en Pico2)
    const uint LED_PIN = 0; // Pico2 tiene el LED en GPIO 0
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    printf("=== Blink Test ===\n");
    printf("LED en GPIO %d\n", LED_PIN);
    printf("Iniciando parpadeo...\n");
    
    while (true) {
        // Encender LED
        gpio_put(LED_PIN, 1);
        printf("LED ON\n");
        sleep_ms(500);
        
        // Apagar LED
        gpio_put(LED_PIN, 0);
        printf("LED OFF\n");
        sleep_ms(500);
    }
    
    return 0;
}
