
#include <random>
#include <ctime>
#include <iostream>
#include <list>
#include "RenderSystem.hpp"
#include "Entity.hpp"

int main(int argc, char **argv)
{
    size_t max = 20;
    std::list<Entity> entities;
    RenderSystem display;

    std::srand(std::time(nullptr));
    if (argc != 1) {
        try {
            max = std::stoi(argv[1]);
        } catch (const std::exception &e) {
            std::cerr << "Invalid argument, need to be a number" << std::endl;
            return (84);
        }
    }
    for (size_t i = 0; i < max; i++) {
        entities.push_back(Entity());
    }
    display.createWindow(1000, 800, "Hello");
    while (display.isOpen()) {
        display.handleEvent();
        display.draw();
    }
    return  0;
}