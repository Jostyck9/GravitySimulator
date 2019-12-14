
#include "RenderSystem.hpp"

int main()
{
    RenderSystem display;

    display.createWindow(1000, 800, "Hello");

    while (display.isOpen()) {
        display.handleEvent();
        display.draw();
    }
    return  0;
}