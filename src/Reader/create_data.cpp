#pragma once
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0

//Se usa uint para defininir valores enteros positivos.
class DataSaver {
public:
    bool check_connection(){
        //Aqui va el codigo para revisar si el lector_sd esta conectado, y tiene un formato valido.
        
        return true;
    }; // Declaracion del metodo para revisar si funciona el lector_sd
    // ...otros miembros...

    void default_values(){
        m_spi = spi0, 
        m_cs_pin = 17,
        m_mosi = 15,
        m_miso = 16,
        m_sck = 18,
        m_baud = 1000 * 1000; // 1 MHz
    };
    

private:
        //Se definen los atributos sin ninguna variable para que pueda ser inicializado con variable default en caso dado.
    spi_inst_t* m_spi = {};
    uint m_cs_pin ={};
    uint m_mosi = {};
    uint m_miso = {};
    uint m_sck ={};
    uint32_t m_baud = {};

};


