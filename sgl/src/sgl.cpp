//
// Created by nte on 6/14/21.
//
#include <sgl.h>

SGL::SGL(uint16_t width, uint16_t height): _width(width), _height(height) {}
SGL::~SGL() {}
void SGL::drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, Mode mode)
{
    // sprawdz czy jest w zasiegu
    if (x0 >= _width)
        x0 = _width - 1;
    if (x1 >= _width)
        x1 = _width - 1;
    if (y0 >= _height)
        y0 = _height - 1;
    if (y1 >= _height)
        y1 = _height - 1;
    uint16_t dx = abs(x1 - x0);
    uint16_t dy = abs(y1 - y0);
    if( dx == 0 && dy == 0)
        drawPixel(x0, y0 ,color, mode);
    if(dy == 0)
        drawHorizontalLine(x0, y0, (y1 - y0), color , mode);
    if(dx == 0)
        drawVerticalLine(x0, y0, (x1 - x0) ,color, mode);
    // signs of x and y axes
    int8_t x_mult = (x0 > x1) ? -1 : 1;
    int8_t y_mult = (y0 < y1) ? -1 : 1;
    if(dy < dx)
    { // positive slope
        int16_t d = (2 * dy) - dx;
        uint16_t y = 0;
        for(uint16_t x = 0; x <= dx; ++x)
        {
            drawPixel(x0 + (x * x_mult), y0 + (y * y_mult), color, mode);
            if(d > 0)
            {
                ++y;
                d -= dx;
            }
            d += dy;
        }
    }
    else
    { // negative slope
        int16_t d = (2 * dx) - dy;
        uint16_t x = 0;
        for(uint16_t y = 0; y <= dy; ++y)
        {
            drawPixel(x0 + (x * x_mult), y0 + (y * y_mult), color, mode);
            if(d > 0)
            {
                ++x;
                d -= dy;
            }
            d += dx;
        }
    }
}
void SGL::drawHorizontalLine(uint16_t x, uint16_t y, int16_t len, uint16_t color, Mode mode)
{
    /* don't need, function if protected, arguments are checked earlier
    if(x >= _width)
        x = _width - 1;
    if(y >= _height)
        y = _height - 1;
    if(x + len >= _width)
        len = _width - x - 1;
    if(x + len < 0)
        len = -x;
    if(len == 0)
        return;
    */
    if(len > 0)
    {
        for(uint16_t i = 0; i < len; ++i)
            drawPixel(x + i, y, color, mode);
    }
    else
    {
        for(uint16_t i = 0; i > len; --i)
            drawPixel(x + i, y, color, mode);
    }
}
void SGL::drawVerticalLine(uint16_t x, uint16_t y, int16_t len, uint16_t color, Mode mode)
{
    /* don't need, function if protected, arguments are checked earlier
    if(y >= _height)
        y = _height - 1;
    if(x >= _width)
        x = _width - 1;
    if(y + len >= _height)
        len = _height - y - 1;
    if(y + len < 0)
        len = -y;
    if(len == 0)
        return;
    */
    if(len > 0)
    {
        for(uint16_t i = 0; i < len; ++i)
            drawPixel(x, y + i, color, mode);
    }
    else
    {
        for(uint16_t i = 0; i > len; --i)
            drawPixel(x, y + i, color, mode);
    }
}
void SGL::drawRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, Fill fill, Mode mode)
{
    if(x0 >= _width)
        x0 = _width - 1;
    if(x1 >= _width)
        x1 = _width -1;
    if(y0 >= _height)
        y0 = _height - 1;
    if(y1 >= _height)
        y1 = _height - 1;
    int16_t dx = x1 - x0;
    int16_t dy = y1 - y0;
    if(dx ==0 && dy == 0)
        drawPixel(x0, y0, color, mode);
    if(dx < 0)
        SWAP_INT16(x0, x1);
    if(dy < 0)
        SWAP_INT16(y0, y1);
    if(dx == 0)
        drawVerticalLine(x0, y0, (y1-y0));
    if(dy == 0)
        drawHorizontalLine(x0, y0, (x1 - x0), color, mode);
    if(fill == Fill::solid)
    {
        if(abs(dx) > abs(dy))
        {
            for(int i = y0; i <= y1; ++i)
                drawHorizontalLine(x0, i, (x1 - x0), color, mode);
        }
        else
        {
            for(int i = x0; i <= x1; ++i)
                drawVerticalLine(i, y0, (y1 - y0), color, mode);
        }
    }
    else
    {
        drawHorizontalLine(x0, y0, (x1 - x0), color, mode);
        drawHorizontalLine(x0, y1, (x1 - x0), color, mode);
        drawVerticalLine(x0, y0, (y1 - y0), color, mode);
        drawVerticalLine(x0, y1, (y1 - y0), color, mode);
    }
}
void SGL::drawTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                       uint16_t color, Fill fill, Mode mode)
{
    if(x0 >= _width)
        x0 = _width - 1;
    if(x1 >= _width)
        x1 = _width -1;
    if(x2 >= _width)
        x2 = _width -1;
    if(y0 >= _height)
        y0 = _height - 1;
    if(y1 >= _height)
        y1 = _height - 1;
    if(y2 >= _height)
        y2 = _height - 1;
    if(fill == Fill::hole)
    {
        drawLine(x0, y0, x1, y1, color, mode);
        drawLine(x1, y1, x2, y2, color, mode);
        drawLine(x2, y2, x0, y0, color, mode);
    }
    else
    {
        // not implemented yet
    }
}
void SGL::drawCircle(int16_t x0, int16_t y0, int16_t radius, uint16_t color, Fill fill, Mode mode)
{
    if(radius <= 0)
        return;
    // from http://en.wikipedia.org/wiki/Midpoint_circle_algorithm
    int16_t x = radius;
    int16_t y = 0;
    int16_t radiusError = 1 -x;

    while (x >= y)
    {

        // if transparent, just draw outline
        if (fill == Fill::hole)
        {
            drawPixel(x + x0, y + y0, color, mode);
            drawPixel(-x + x0, y + y0, color, mode);
            drawPixel(y + x0, x + y0, color, mode);
            drawPixel(-y + x0, x + y0, color, mode);
            drawPixel(-y + x0, -x + y0, color, mode);
            drawPixel(y + x0, -x + y0, color, mode);
            drawPixel(x + x0, -y + y0, color, mode);
            drawPixel(-x + x0, -y + y0, color, mode);
        }
        else
        { // drawing filled circle, so draw lines between points at same y value
            drawLine(x + x0, y + y0, -x + x0, y + y0, color, mode);
            drawLine(y + x0, x + y0, -y + x0, x + y0, color, mode);
            drawLine(y + x0, -x + y0, -y + x0, -x + y0, color, mode);
            drawLine(x + x0, -y + y0, -x + x0, -y + y0, color, mode);
        }

        y++;
        if (radiusError < 0)
        {
            radiusError += 2 * y + 1;
        }
        else
        {
            x--;
            radiusError += 2 * (y - x) + 1;
        }
    }
}

void SGL::drawPixelCheckArg(uint16_t x0, uint16_t y0, uint16_t color, Mode mode)
{
    if(x0 >= _width)
        x0 = _width - 1;
    if(y0 >= _height)
        y0 >= _height - 1;
    drawPixel(x0, y0, color, mode);
}

void SGL::drawChar(char c, uint16_t x, uint16_t y) // for the new font
// bedzie problem z pusta linia po lewej znaku - w szerokosci fontu sie tego nie uwzglednia, a nie wszystkie znaki to maja
// podsumowujac czasem jest, czasem nie ma pustej linii z lewej - nie ma informacji kiedy jest
// trzeba by sprobowac rysowac je ze stala szerokoscia fontu, nie chara
// lub cos usunac ta linie z char gdzie wystepuje i ja szcztucznie dorysowywac
// w creatorze fontow mozna je wszystkie przysnapowac do lewej, nastepnie na podstawie szerokosci narysowac i dododac space z prawej
// lub dodawac tylko w draw sring, chociaz chyba w draw char bedzie prosciej
// moze stworzyc klase, strukture, statyczna strukture, jedna tabela zawiera tylko szerokosci znakow, druga zawiera bitmapy
// od razu dodac wysokosc i ile bajtow wychodzi na kolumne
{
    if( c < 32 || c > 127)
        return;
    uint16_t x_cursor = x;
    uint16_t y_cursor = y;
    c = c - _font->first_char;
    uint8_t char_width = _font->get_char_width(c); // first number in row means char width
    for(uint8_t i = 1 ; i < char_width * _font->byte_mult; i += _font->byte_mult)
    {
        for(int j = 0; j < _font->byte_mult; j++)
        {
            uint8_t off = 0;
            if (j == _font->byte_mult - 1)
            {
                off = _font->byte_mult * 8 - _font->font_height;
            }
            uint8_t ch = _font->font_array[c*(_font->font_width*_font->byte_mult+1) + i + j];
            for(int8_t b = 0; b < 8 - off; ++b) //
            {
                if(((ch >> b) % 2) == !_font->invert) // == 0 or != 1 means text inverted
                    drawPixel(x_cursor, y_cursor, _font->color);
                y_cursor++;
            }
        }
        x_cursor++;
        y_cursor = y;
    }
}

void SGL::drawString(const char* c, uint16_t x, uint16_t y)
{
    uint8_t xx = x;
    uint8_t yy = y;
    for(; *c != '\0'; c++) {
        if(x > _width - _font->get_char_width(*c-32) && _font->wrap == false)
        {
            return;
        }
        if(x > _width - _font->get_char_width(*c-32))
        {
            x = xx;
            y += _font->font_height;
        }
        if(*c > 126)
        {
            drawChar((char)127, x, y);
        }
        else
        {
            drawChar(*c, x, y);
        }
        x += _font->get_char_width(*c-32);
    }
}

void SGL::drawBitmap16(uint16_t* bitmap, uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
    // TO DO CHECK IF THIS IS CORRECT
    if(x >= _width)
        x = _width - 1;
    if(y >= _height)
        y = _height - 1;
    if((x + width) >= _width)
        width = _width - x - 1;
    if((y + _height) >= _height)
        _height = _height - y - 1;
    for(uint16_t i = 0; i <= width; i++)
    {
        for(uint16_t j = 0; j <= height; j++)
        {
            drawPixel(i + x, j + x, *(bitmap + i + j * width));
        }
    }
}