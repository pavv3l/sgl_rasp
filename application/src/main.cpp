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
    lcd.fillScreen(0xF800);
    for(auto i = std::make_pair<int,int>(0,240); i.first < 320; ++i.first)
        lcd.drawLine(0,i.first,240,i.first);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Pomiar czasu 1000* send fillscreen: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 -t1).count() << std::endl;
    return 0;
}
