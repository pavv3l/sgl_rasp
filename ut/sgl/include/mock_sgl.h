//
// Created by nte on 6/20/21.
//
#ifndef SGL_MOCK_SGL_H
#define SGL_MOCK_SGL_H
#include <gmock/gmock.h>
#include <sgl.h>

class TestSGL : public SGL
{
public:
    uint16_t get_width() {return _width;}
    uint16_t get_height() {return _height;}
    TestSGL(uint16_t x, uint16_t y): SGL(x, y) {}
    virtual void drawPixel(uint16_t x0, uint16_t y0, uint16_t color = BLACK, Mode mode = Mode::px_copy) override {}
};

class MockSGL : public TestSGL
{
public:
    MockSGL(uint16_t x, uint16_t y): TestSGL(x, y) {}
    MOCK_METHOD(void, drawPixel, (uint16_t x0, uint16_t y0, uint16_t color, Mode mode), (override));
    MOCK_METHOD(void, drawLine, (uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, Mode mode), (override));
    MOCK_METHOD(void, drawRectangle, (uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, Fill fill, Mode mode), (override));
    MOCK_METHOD(void, drawTriangle, (uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                                        uint16_t color, Fill fill, Mode mode), (override));
    MOCK_METHOD(void, drawCircle, (int16_t x0, int16_t y0, int16_t radius, uint16_t color, Fill fill, Mode mode), (override));
};

#endif //SGL_MOCK_SGL_H
