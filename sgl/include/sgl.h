//
// Created by nte on 6/14/21.
//
#ifndef SGL_SGL_H
#define SGL_SGL_H
#include <cstdint>
#include <memory>
#include <font.h>
#include <cstring>
#include <iostream>

//  Funkcja konwertujaca kolor rgb 24(RGB888) BIT do 16(RGB565) bitowego hex
#define RGB565(r,g,b) ((((uint16_t)r & 0x00F8) << 8) | (((uint16_t)g & 0x00FC) << 3) | (((uint16_t)b & 0x00F8) >> 3))
#define BLACK RGB565(0, 0, 0)
#define WHITE RGB565(255, 255, 255)
#define PIXEL_ON 1
#define PIXEL_OFF 0

#define SWAP_INT16(a, b)\
{                       \
    int16_t temp = a;   \
    a = b;              \
    b = temp;           \
}
#define SWAP_INT8(a, b) \
{                       \
    int8_t temp = a;    \
    a = b;              \
    b = temp;           \
}

// function for async work
#include <future>
template<class T, class... Ts>
        inline
        auto
        doReallyAsyncWork(T&& t, Ts... params)
{
            return std::async(std::launch::async, std::forward<T>(t), std::forward<Ts>(params)...);
}

class SGL {
public:
    enum class Mode: uint8_t
    {
        px_copy = 0x0, // 00->0, 01->1, 10->0, 11->1
        px_or   = 0x1, // 00->0, 01->1, 10->1, 11->1
        px_xor  = 0x2, // 00->0, 01->1, 10->1, 11->0
        px_clr  = 0x3  // 00->0, 01->1, 10->0, 11->1
    };
    enum class Fill: uint8_t
    {
        solid = 0x0,
        hole = 0x1
    };
    // if you don't use Buffer everything you draw is immediately
    // draw to display in other case you must use drawScreen
    SGL(uint16_t width, uint16_t height);
    virtual ~SGL();
    virtual void drawPixel(uint16_t x0, uint16_t y0, uint16_t color = WHITE, Mode mode = Mode::px_copy) = 0;
    // wazne, dla linii dlugosc 0 oznacza brak linii
    virtual void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color = BLACK, Mode mode = Mode::px_copy);
    virtual void drawRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color = BLACK, Fill fill = Fill::hole, Mode mode = Mode::px_copy);
    virtual void drawTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                              uint16_t color = BLACK, Fill fill = Fill::hole, Mode mode = Mode::px_copy);
    virtual void drawCircle(int16_t x0, int16_t y0, int16_t radius, uint16_t color = BLACK, Fill fill = Fill::hole, Mode mode = Mode::px_copy);
    void setFont(SGLFont* font) { _font = font; }
    void drawChar(char c, uint16_t x, uint16_t y);
    void drawString(const char* c, uint16_t x, uint16_t y);
    void drawBitmap16(uint16_t* bitmap, uint16_t x, uint16_t y, uint16_t width, uint16_t height);
protected:
    // reverse byte order e.g 101011 - return from func 110101
    unsigned char reverseBytes(unsigned char b);
    // draw horizontal and vertical lines are procected, and don't need to check their arguments
    void drawHorizontalLine(uint16_t x, uint16_t y, int16_t len, uint16_t color = BLACK, Mode mode = Mode::px_copy);
    void drawVerticalLine(uint16_t x, uint16_t y, int16_t len, uint16_t color = BLACK, Mode mode = Mode::px_copy);
    void drawPixelCheckArg(uint16_t x0, uint16_t y0, uint16_t color = BLACK, Mode mode = Mode::px_copy);
    uint16_t _width;
    uint16_t _height;
    SGLFont* _font;
};


#endif //SGL_SGL_H
