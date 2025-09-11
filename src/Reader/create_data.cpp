#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0

class DataSaver {
public:
    void read() {
        printf("Saving data...\n");
    }
};