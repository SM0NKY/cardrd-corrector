#pragma once

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "diskio.h"
#include "ff.h"
#include "ffconf.h"

#define SPI_PORT spi0

//Se usa uint para defininir valores enteros positivos.
namespace data {


    class DataSaver {
    public:
        /**
         * @class DataSaver
         * @brief Guarda y gestiona la configuración SPI.
         *
         * @param spi Instancia SPI.
         * @param cs_pin Pin de chip select.
         * @param mosi Pin MOSI.
         * @param miso Pin MISO.
         * @param sck Pin SCK.
         * @param baud Velocidad de baudios.
        */
        DataSaver(spi_inst_t* _spi = spi0, uint _cs_pin = 17, uint _mosi = 15, uint _miso = 16, uint _sck = 18, uint32_t _baud = 1000 * 1000);
        bool check_connection();

        void default_values(); 

        void change_data(spi_inst_t* n_spi, uint n_cs_pin, uint n_mosi, uint n_miso, uint n_sck, uint32_t n_baud);
        

    private:
            //Se definen los atributos sin ninguna variable para que pueda ser inicializado con variable default en caso dado.
        spi_inst_t* spi;
        uint cs_pin;
        uint mosi;
        uint miso;
        uint sck;
        uint32_t baud;

    };
}