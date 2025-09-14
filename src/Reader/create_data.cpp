#include "create_data.hpp"
using namespace data;


DataSaver::DataSaver(spi_inst_t* _spi, uint _cs_pin, uint _mosi, uint _miso, uint _sck, uint32_t _baud){
// Constructor implementation (if needed)
spi = _spi;
cs_pin = _cs_pin;
mosi = _mosi;
miso = _miso;
sck = _sck;
baud = _baud;
};

void DataSaver::default_values(){
    spi = spi0, 
    cs_pin = 17,
    mosi = 15,
    miso = 16,
    sck = 18,
    baud = 1000 * 1000;
};
// Agregar un metodo para que inicialice los pines con el SPI para los pines determinados.

//Agregar un metodo para que en caso de no tener un formato la memoria le de uno.

//Agregar un metodo a la clase para cambiar los valores de los pines y el baudrate.

void DataSaver::change_data(spi_inst_t* n_spi, uint n_cs_pin, uint n_mosi, uint n_miso, uint n_sck, uint32_t n_baud){
    spi = n_spi;
    cs_pin = n_cs_pin;
    mosi = n_mosi;
    miso = n_miso;
    sck = n_sck;
    baud = n_baud;
};
    
bool DataSaver::check_connection(){
    FATFS fs;
    FRESULT res = f_mount(&fs, "", 1); // Montar la tarjeta SD en la raíz
    if (res == FR_OK) {
        f_unmount("");
        printf("SD card mounted successfully.\n");
        return false;
    }else {
        printf("Error mounting SD card: %d\n", res);
    }

    return true; // Placeholder
}
