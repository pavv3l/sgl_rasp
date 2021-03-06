/*
Podczas wysyłania komendy pin DC musi być w stanie niskim a podczas wysyłania danych w stanie wysokim.
W obu przypadkach pin CS musi być w stanie niskim. Dodatkowo widzimy, że pomiędzy wysłaniem komendy/polecenia
a danymi pojawia się zwłoka realizowana na  pinie CS w postaci stanu wysokiego. Z praktyki jednak wiem,
że pin CS możemy na sztywno połączyć do masy. Zwłoka powstanie nam automatycznie w procesie realizacji komunikacji SPI.
*/



#ifndef __SGL_ILI9341_H__
#define __SGL_ILI9341_H__
#include <sgl.h>
#include <pigpio.h>
#include <cstdint>
#include <initializer_list>
#include <array>
#include <algorithm>
#include <unistd.h>

#define SPI_BAUD 5'000'000
//21 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
//b  b  b  b  b  b  R  T  n  n  n  n   W  A u2 u1 u0 p2 p1 p0  m  m
#define SPI_CHAN 0
#define SPI_MODE 3
#define LCD_WIDTH 240
#define LCD_HEIGHT 320

#define ILI9341_NOP 0x00     ///< No-op register
#define ILI9341_SWRESET 0x01 ///< Software reset register
#define ILI9341_RDDID 0x04   ///< Read display identification information
#define ILI9341_RDDST 0x09   ///< Read Display Status

#define ILI9341_SLPIN 0x10  ///< Enter Sleep Mode
#define ILI9341_SLPOUT 0x11 ///< Sleep Out
#define ILI9341_PTLON 0x12  ///< Partial Mode ON
#define ILI9341_NORON 0x13  ///< Normal Display Mode ON

#define ILI9341_RDMODE 0x0A     ///< Read Display Power Mode
#define ILI9341_RDMADCTL 0x0B   ///< Read Display MADCTL
#define ILI9341_RDPIXFMT 0x0C   ///< Read Display Pixel Format
#define ILI9341_RDIMGFMT 0x0D   ///< Read Display Image Format
#define ILI9341_RDSELFDIAG 0x0F ///< Read Display Self-Diagnostic Result

#define ILI9341_INVOFF 0x20   ///< Display Inversion OFF
#define ILI9341_INVON 0x21    ///< Display Inversion ON
#define ILI9341_GAMMASET 0x26 ///< Gamma Set
#define ILI9341_DISPOFF 0x28  ///< Display OFF
#define ILI9341_DISPON 0x29   ///< Display ON

#define ILI9341_CASET 0x2A ///< Column Address Set
#define ILI9341_PASET 0x2B ///< Page Address Set
#define ILI9341_RAMWR 0x2C ///< Memory Write
#define ILI9341_RAMRD 0x2E ///< Memory Read

#define ILI9341_PTLAR 0x30    ///< Partial Area
#define ILI9341_VSCRDEF 0x33  ///< Vertical Scrolling Definition
#define ILI9341_MADCTL 0x36   ///< Memory Access Control
#define ILI9341_VSCRSADD 0x37 ///< Vertical Scrolling Start Address
#define ILI9341_PIXFMT 0x3A   ///< COLMOD: Pixel Format Set

#define ILI9341_FRMCTR1 0xB1 ///< Frame Rate Control (In Normal Mode/Full Colors)
#define ILI9341_FRMCTR2 0xB2 ///< Frame Rate Control (In Idle Mode/8 colors)
#define ILI9341_FRMCTR3 0xB3 ///< Frame Rate control (In Partial Mode/Full Colors)
#define ILI9341_INVCTR 0xB4  ///< Display Inversion Control
#define ILI9341_DFUNCTR 0xB6 ///< Display Function Control

#define ILI9341_PWCTR1 0xC0 ///< Power Control 1
#define ILI9341_PWCTR2 0xC1 ///< Power Control 2
#define ILI9341_PWCTR3 0xC2 ///< Power Control 3
#define ILI9341_PWCTR4 0xC3 ///< Power Control 4
#define ILI9341_PWCTR5 0xC4 ///< Power Control 5
#define ILI9341_VMCTR1 0xC5 ///< VCOM Control 1
#define ILI9341_VMCTR2 0xC7 ///< VCOM Control 2

#define ILI9341_RDID1 0xDA ///< Read ID 1
#define ILI9341_RDID2 0xDB ///< Read ID 2
#define ILI9341_RDID3 0xDC ///< Read ID 3
#define ILI9341_RDID4 0xDD ///< Read ID 4

#define ILI9341_GMCTRP1 0xE0 ///< Positive Gamma Correction
#define ILI9341_GMCTRN1 0xE1 ///< Negative Gamma Correction

// Color definitions
#define ILI9341_BLACK 0x0000       ///<   0,   0,   0
#define ILI9341_NAVY 0x000F        ///<   0,   0, 123
#define ILI9341_DARKGREEN 0x03E0   ///<   0, 125,   0
#define ILI9341_DARKCYAN 0x03EF    ///<   0, 125, 123
#define ILI9341_MAROON 0x7800      ///< 123,   0,   0
#define ILI9341_PURPLE 0x780F      ///< 123,   0, 123
#define ILI9341_OLIVE 0x7BE0       ///< 123, 125,   0
#define ILI9341_LIGHTGREY 0xC618   ///< 198, 195, 198
#define ILI9341_DARKGREY 0x7BEF    ///< 123, 125, 123
#define ILI9341_BLUE 0x001F        ///<   0,   0, 255
#define ILI9341_GREEN 0x07E0       ///<   0, 255,   0
#define ILI9341_CYAN 0x07FF        ///<   0, 255, 255
#define ILI9341_RED 0xF800         ///< 255,   0,   0
#define ILI9341_MAGENTA 0xF81F     ///< 255,   0, 255
#define ILI9341_YELLOW 0xFFE0      ///< 255, 255,   0
#define ILI9341_WHITE 0xFFFF       ///< 255, 255, 255
#define ILI9341_ORANGE 0xFD20      ///< 255, 165,   0
#define ILI9341_GREENYELLOW 0xAFE5 ///< 173, 255,  41
#define ILI9341_PINK 0xFC18        ///< 255, 130, 198
//#define HIGHERBYTE(h) static_cast<int8_t>((h & 0xff00) >> 8)
//#define LOWERBYTE(l) static_cast<int8_t>(l & 0x00ff)
#define HIGHERBYTE(h) static_cast<int8_t>((h & 0xff00) >> 8)
#define LOWERBYTE(l) static_cast<int8_t>(l & 0x00ff)

#define ILI9341_END_WRITE ;
using PinName = unsigned;
using MySPI = int;

class SGLILI9341: public SGL
{public:
    SGLILI9341(PinName CE, PinName DC, PinName RST, PinName SPI_MOSI, PinName SPI_MISO, PinName SPI_SCK);
    ~SGLILI9341();
    void init();
    void drawPixel(uint16_t x, uint16_t y, uint16_t color = ILI9341_WHITE, SGL::Mode mode = SGL::Mode::px_copy) override;
    void fillScreen(uint16_t color);
    void set_rotation(uint8_t rot);
    void invert_display(bool invert);
    void scroll_to(uint16_t h);
    void set_scroll_margins(uint16_t top, uint16_t bottom);
    void reset();
protected:
    void sendCommand(uint8_t cmd);
    void sendCommandParameter(uint8_t cmd);
    void sendCommandWithParameter(std::initializer_list<char> lst);
    void sendData(uint16_t data);
    void setActiveWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
    struct DataChahne
    void clearBuffer();
    void drawrScreen();
    void reset2();

    bool wrapText = true;

    PinName ce;
    PinName dc;
    PinName rst;
    PinName spiMosi;
    PinName spiMiso;
    PinName spiCLK;
    MySPI spiHandle;

    std::array<char, LCD_WIDTH * LCD_HEIGHT * 2> txbuff;
    std::array<char,100> commandBuffer;

    uint8_t contrast;
    uint8_t bias;
    struct RangeSrcreen
};


#endif //   __SGL_ILI9341_H__
