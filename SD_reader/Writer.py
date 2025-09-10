from machine import Pin, SPI 
import vfs
from MicroSD import SDCard as sdcard
from typing import Optional,Protocol, Any, List, Dict, Callable, Literal
import micropython



#Esta clase es la base de las funciones que se van a utilizar#
class Writer(Protocol):
    def check_format(self) -> bool:
        ...
    def close(self) -> None:
        ...

    #Esta funcion va a ayudar a cargar los datos de la memoria para evitar repetir el abrirla para subir los datos#
    def check_errors(self,message:Literal["Error al cargar la memoria sd"]) -> Callable[[Callable[...,Any]],Callable[...,Any]]:
        ...

class SD_writer(Writer):
    """
    Atributes
    ---------
    `sd:object`: Instance of the MicroSD class for SD card operations.

    Parameters
    ----------
    `cs_pin:int`: Chip select pin for the SD card (default is 17).
    `sck:int`: Serial clock pin (default is 18).
    `mosi:int`: Master Out Slave In pin (default is 19).
    `miso:int`: Master In Slave Out pin (default is 16).
    `spi_pin:int`: SPI bus number (default is 0).

    """

    def __init__(self, cs_pin:int= 17,sck:int = 18, mosi:int = 15, miso:int = 16,spi_pin:int = 0) -> None:
        #-- Defined Pined Connection by initializing the class w/variables --#
        self.cs_pin:object|Pin = Pin(cs_pin, Pin.OUT)
        self.sck_pin:object|Pin = Pin(sck)
        self.mosi_pin:object|Pin = Pin(mosi)
        self.miso_pin:object|Pin = Pin(miso)
        self.spi_pin:int = spi_pin

        #-- Defining spi connections --#
        self.spi:object|SPI = SPI(self.spi_pin, baudrate=1000000, polarity=0, phase=0, sck=self.sck_pin, mosi=self.mosi_pin, miso=self.miso_pin)

        #-- Setting up the sdcard connection#
        self.sd:object|sdcard = sdcard(self.spi, self.cs_pin) #-- Los pines estan definidos por default --#

    def check_errors(self, message:Literal["Error al cargar la memoria sd"]) -> Callable[[Callable[...,Any]],Callable[...,Any]]:
        def decorator_func(func:Callable[...,Any]) -> Callable[...,Any]:
            def wrapper(self,*args, **kwargs):
                try:
                    #Aqui agregar el try de la memoria sd, para hacer rolbacks#

                    return func(self,*args, **kwargs)
                except Exception as e:
                    print(f"An error occurred: {e}")
                    raise
            return wrapper
        return decorator_func


    
    def check_format(self) -> bool:
        """
        Checks if the SD card is properly formatted and accessible.

        Atributes 
        ---------
        `self`:object: Instance of the SD_writer class.
        """
        #Revisar esto con calma#
        VfsFat = vfs.
        vfs32 = vfs.VfsFat(self.sd)

        return True
import os
