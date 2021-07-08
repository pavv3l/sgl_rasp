#include "sgl_ili9341.h"
#include <chrono>
#include <cstdint>
#include <iostream>
#include <utility>

SGLILI9341::SGLILI9341(PinName CE, PinName DC, PinName RST, PinName SPI_MOSI, PinName SPI_MISO, PinName SPI_SCK):
        SGL(LCD_WIDTH, LCD_HEIGHT), ce(CE), dc(DC), rst(RST), spiMosi(SPI_MOSI), spiMiso(SPI_MISO), spiCLK(SPI_SCK)
{
    gpioTerminate();
    if(gpioInitialise() < 0)
    {
        std::cout << "[SGLILI9341] gpio initialization failed\n";
        gpioTerminate();
        exit(-1);
    } else
    {
        std::cout << "[SGLILI9341] gpio initialization correct\n";
    }
    gpioSetMode(ce, PI_OUTPUT);
    gpioWrite(ce, PI_OFF);
    gpioSetMode(dc, PI_OUTPUT);
    gpioWrite(dc, PI_ON);
    gpioSetMode(rst, PI_OUTPUT);
    gpioWrite(rst, PI_ON);
    spiHandle = spiOpen(SPI_CHAN, SPI_BAUD, SPI_MODE);
    if(spiHandle >= 0)
    {
        std::cout << "[SGLILI9341] SPI initialize correct\n";
    }
    else
    {
        std::cout << "[SGLILI9341] SPI initialize incorrect\n";
        gpioTerminate();
        exit(-1);
    }
}

SGLILI9341::~SGLILI9341()
{
    //delete[] txbuff;
    //delete[] commandBuffer;
    spiClose(spiHandle);
    gpioTerminate();
}

void SGLILI9341::init()
{
    txbuffLen = 240 * 320 * 2;
    txbuff.resize(txbuffLen);
    //commandBuffer = new char[100];
    commandBuffer.resize(100);
    reset();
    //higherByte = (unsigned char)((command & 0xff00) >> 8);
    //lowerByte = (unsigned char)(command & 0x00ff);
    //SPI_transmit(higherByte);
    //SPI_transmit(lowerByte);

    // comm(16bit)
    //AVR_WRITESPI(w >> 8);
    //AVR_WRITESPI(w);
}

void SGLILI9341::sendCommand(uint8_t cmd)
{
    //spi.format(8,3);
    gpioWrite(ce, PI_OFF);
    gpioWrite(dc, PI_OFF);
    commandBuffer[0] = cmd;
    spiWrite(spiHandle, commandBuffer.data(), 1);
    //spi.write(cmd);
    gpioWrite(dc, PI_ON);
    //spi.format(16,3);
}

void SGLILI9341::sendCommandParameter(uint8_t cmd)
{
    //spi.format(8,3);
    gpioWrite(ce, PI_OFF);
    gpioWrite(dc, PI_ON);
    commandBuffer[0] = cmd;
    spiWrite(spiHandle, commandBuffer.data(), 1);
    //spi.write(cmd);
    //spi.format(16,3);
}

void SGLILI9341::sendCommandWithParameter(std::initializer_list<uint8_t> lst)
{/*
    uint8_t size = lst.size();
    if(size < 2) return;
    //spi.format(8,3);
    gpioWrite(ce, PI_OFF);
    gpioWrite(dc, PI_OFF);
    // std::pair<std::initializer_list<uint8_t>::iterator, uint16_t> cdat = std::make_pair(lst.begin(), 0);
    auto cdat = std::make_pair(lst.begin(), 0);
    for(; cdat.first < lst.end(); ++cdat.second)
    {
        commandBuffer[cdat.second] = *cdat.first;
        //spi.write(*i);
    }
    spiWrite(spiHandle, commandBuffer, 1);
    gpioWrite(dc, PI_ON);
    spiWrite(spiHandle, (commandBuffer + 1), cdat.second);
    gpioWrite(ce, PI_ON);
    */
}

void SGLILI9341::sendData(uint16_t data)
{
    gpioWrite(ce, PI_OFF);
    gpioWrite(dc, PI_ON);

    txbuff[0] = HIGHERBYTE(data);
    txbuff[1] = LOWERBYTE(data);
    spiWrite(spiHandle, txbuff.data(), 2);
    gpioWrite(ce, PI_ON);
}

void SGLILI9341::setActiveWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    sendCommand(0x2A); // column address set
    sendData(x0);
    sendData(x1);

    sendCommand(0x2B);
    sendData(y0);
    sendData(y1);

    sendCommand(0x2C);
}

void SGLILI9341::drawPixel(uint16_t x, uint16_t y, uint16_t color, SGL::Mode mode)
{
    if (x >= LCD_WIDTH || y >= LCD_HEIGHT)
    {
        return;
    }
    setActiveWindow(x, y, x, y);

    sendCommand(0x2C);
    sendData(color);
}
unsigned char reverse(unsigned char b) {
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
}

void SGLILI9341::fillScreen(uint16_t color) {
    for (int i = 0; i < txbuff.size(); i = i + 2) {
        txbuff[i] = HIGHERBYTE(color);
        txbuff[i + 1] = LOWERBYTE(color);
    }
    setActiveWindow(0, 0, 240, 320);
    {
        gpioWrite(ce, PI_OFF);
        gpioWrite(dc, PI_ON);
        //spiXfer(spiHandle, txbuff.data(), NULL, txbuff.size());
        spiWrite(spiHandle, txbuff.data(), txbuff.size());
        gpioWrite(ce, PI_ON);
    }
}

void SGLILI9341::drawBitmap(uint16_t* bitmap, uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
    if(x >= _width)
        x = _width - 1;
    if(y >= _height)
        y = _height - 1;
    if((x + width) >= _width)
        width = _width - x - 1;
    if((y + _height) >= _height)
        _height = _height - y - 1;

    //spi.write16(bitmap, width*height);
    // OR better
    //spi.write((char*)bitmap, sizeof(*bitmap)* width * height, NULL, NULL);
}

void SGLILI9341::reset()
{
    gpioWrite(ce, PI_ON);
    gpioWrite(dc, PI_ON);
    gpioWrite(rst, PI_OFF);

    usleep(50);
    gpioWrite(rst, PI_ON);
    //wait_ms(5);
    usleep(5000);
    gpioWrite(ce, PI_OFF);
    sendCommand(0x01); // SW reset
    gpioWrite(ce, PI_ON);
    usleep(5000);
    gpioWrite(ce, PI_OFF);
    sendCommand(0x28); // display off
    gpioWrite(ce, PI_ON);

    /* Start Initial Sequen//ce ----------------------------------------------------*/
    gpioWrite(ce, PI_OFF);
    sendCommand(0xCF);
    sendCommandParameter(0x00); // musza buc wyslane 8bit
    sendCommandParameter(0x83);
    sendCommandParameter(0x30);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xED);
    sendCommandParameter(0x64);
    sendCommandParameter(0x03);
    sendCommandParameter(0x12);
    sendCommandParameter(0x81);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xE8);
    sendCommandParameter(0x85);
    sendCommandParameter(0x01);
    sendCommandParameter(0x79);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xCB);
    sendCommandParameter(0x39);
    sendCommandParameter(0x2C);
    sendCommandParameter(0x00);
    sendCommandParameter(0x34);
    sendCommandParameter(0x02);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xF7);
    sendCommandParameter(0x20);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xEA);
    sendCommandParameter(0x00);
    sendCommandParameter(0x00);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xC0); // POWER_CONTROL_1
    sendCommandParameter(0x26);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xC1); // POWER_CONTROL_2
    sendCommandParameter(0x11);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xC5); // VCOM_CONTROL_1
    sendCommandParameter(0x35);
    sendCommandParameter(0x3E);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xC7); // VCOM_CONTROL_2
    sendCommandParameter(0xBE);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0x36); // MEMORY_AC//ceSS_CONTROL
    sendCommandParameter(0x48);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0x3A); // COLMOD_PIXEL_FORMAT_SET
    sendCommandParameter(0x55);    // 16 bit pixel
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xB1); // Frame Rate
    sendCommandParameter(0x00);
    sendCommandParameter(0x1B);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xF2); // Gamma Function Disable
    sendCommandParameter(0x08);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0x26);
    sendCommandParameter(0x01); // gamma set for curve 01/2/04/08
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xE0); // positive gamma correction
    sendCommandParameter(0x1F);
    sendCommandParameter(0x1A);
    sendCommandParameter(0x18);
    sendCommandParameter(0x0A);
    sendCommandParameter(0x0F);
    sendCommandParameter(0x06);
    sendCommandParameter(0x45);
    sendCommandParameter(0x87);
    sendCommandParameter(0x32);
    sendCommandParameter(0x0A);
    sendCommandParameter(0x07);
    sendCommandParameter(0x02);
    sendCommandParameter(0x07);
    sendCommandParameter(0x05);
    sendCommandParameter(0x00);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xE1); // negativ gamma correction
    sendCommandParameter(0x00);
    sendCommandParameter(0x25);
    sendCommandParameter(0x27);
    sendCommandParameter(0x05);
    sendCommandParameter(0x10);
    sendCommandParameter(0x09);
    sendCommandParameter(0x3A);
    sendCommandParameter(0x78);
    sendCommandParameter(0x4D);
    sendCommandParameter(0x05);
    sendCommandParameter(0x18);
    sendCommandParameter(0x0D);
    sendCommandParameter(0x38);
    sendCommandParameter(0x3A);
    sendCommandParameter(0x1F);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    setActiveWindow(0, 0, _width, _height);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xB7); // entry mode
    sendCommandParameter(0x07);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0xB6); // display function control
    sendCommandParameter(0x0A);
    sendCommandParameter(0x82);
    sendCommandParameter(0x27);
    sendCommandParameter(0x00);
    gpioWrite(ce, PI_ON);

    gpioWrite(ce, PI_OFF);
    sendCommand(0x11); // sleep out
    gpioWrite(ce, PI_ON);

    usleep(100*1000);

    gpioWrite(ce, PI_OFF);
    sendCommand(0x29); // display on
    gpioWrite(ce, PI_ON);

    usleep(100*1000);
}

void SGLILI9341::reset2()
{
    gpioWrite(ce, PI_ON);
    gpioWrite(dc, PI_ON);
    gpioWrite(rst, PI_OFF); // display reset
    usleep(50);
    usleep(1000);
    gpioWrite(rst, PI_ON); // end hardware reset
    usleep(5000);
    sendCommand(0x01); // SW reset
    usleep(5000);
    sendCommand(0x28); // display off
    /* Start Initial Sequen//ce ----------------------------------------------------*/
    sendCommandWithParameter({0xCF, 0x00, 0x83, 0x30});
    sendCommandWithParameter({0xED, 0x64, 0x03, 0x12, 0x81});
    sendCommandWithParameter({0xE8, 0x85, 0x01, 0x79});
    sendCommandWithParameter({0xCB, 0x39, 0x2C, 0x00, 0x34, 0x02});
    sendCommandWithParameter({0xF7, 0x20});
    sendCommandWithParameter({0xEA, 0x00, 0x00});
    sendCommandWithParameter({0xC0, 0x26});
    sendCommandWithParameter({0xC1, 0x11});
    sendCommandWithParameter({0xC5, 0x35, 0x3E});
    sendCommandWithParameter({0xC7, 0xBE, 0xBE});
    sendCommandWithParameter({0x36, 0x48});
    sendCommandWithParameter({0x3A, 0x55});
    sendCommandWithParameter({0xB1, 0x00, 0x1B});
    sendCommandWithParameter({0xF2, 0x08});
    sendCommandWithParameter({0x26, 0x01});
    sendCommandWithParameter({0xE0, 0x1F, 0x1A, 0x18, 0x0A, 0x0F, 0x06, 0x45, 0x87, 0x32, 0x0A, 0x07, 0x02, 0x07, 0x05, 0x00});
    sendCommandWithParameter({0xE1, 0x00, 0x25, 0x27, 0x05, 0x10, 0x09, 0x3A, 0x78, 0x4D, 0x05, 0x18, 0x0D, 0x38, 0x3A, 0x1F});
    sendCommandWithParameter({0xB7, 0x07});
    sendCommandWithParameter({0xB6, 0x0A, 0x82, 0x27, 0x00});
    sendCommand(0x11); // sleep out
    usleep(100*1000);
    sendCommand(0x29); // display on
    usleep(100*1000);
}

void SGLILI9341::set_rotation(uint8_t rot)
{
    ;
}

void SGLILI9341::invert_display(bool invert)
{
    sendCommand(invert ? ILI9341_INVON : ILI9341_INVOFF);
}

void SGLILI9341::scroll_to(uint16_t h)
{
    sendCommand(ILI9341_VSCRSADD);
    sendData(h >> 8);
    sendData(h & 255);
}

void SGLILI9341::set_scroll_margins(uint16_t top, uint16_t bottom)
{
    ;
}