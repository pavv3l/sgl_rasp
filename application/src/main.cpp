#include <iostream>
#include <sgl_ili9341.h>
#include <chrono>
#include <unistd.h>
#include <utility>

int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;
    SGLILI9341 lcd(8, 23, 24, 10, 9, 11);
    lcd.init();
    auto t1 = std::chrono::high_resolution_clock::now();
    lcd.fillScreen(RGB565(255,0 ,0));
    usleep(5000000);
    lcd.fillScreen(RGB565(0,255 ,0));
    usleep(5000000);
    lcd.fillScreen(RGB565(0,0 ,255));
    //lcd.fillScreen(RGB565(255,255,255));
    //lcd.fillScreen(RGB565(0,150,0));
    //lcd.drawPixel(1,1, ILI9341_GREEN, SGL::Mode::px_copy);
    //lcd.drawRectangle(10,10, 100, 100, ILI9341_RED);
    //lcd.drawCircle(150, 150, 40, ILI9341_RED);
    //lcd.drawLine(200, 200, 100, 100, ILI9341_RED);
    //lcd.drawLine(2, 2, 99, 99, ILI9341_GREEN);

    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Pomiar czasu 1000* send fillscreen: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 -t1).count() << std::endl;
    return 0;
}
