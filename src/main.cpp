
#include <random>
#include <ctime>
#include <iostream>
#include <list>
#include "Timer.hpp"
#include "RenderSystem.hpp"
#include "Entity.hpp"

void update(std::vector<Entity> &entities)
{
    static Timer myTimer;

    for (auto &item : entities) {
        auto position = item.getPosition();
        auto speed = item.getSpeed();

        position.first += speed.first * myTimer.getElapsedSeconds();
        position.second += speed.second * myTimer.getElapsedSeconds();

        item.setPosition(position);
    }
    myTimer.restart();
}

int main(int argc, char **argv)
{
    size_t max = 100;
    if (argc != 1) {
        try {
            max = std::stoi(argv[1]);
        } catch (const std::exception &e) {
            std::cerr << "Invalid argument, need to be a number" << std::endl;
            return (84);
        }
    }

    std::vector<Entity> entities;
    RenderSystem display(max);

    std::srand(std::time(nullptr));
    for (size_t i = 0; i < max; i++) {
        entities.push_back(Entity());
    }
    display.createWindow(1000, 800, "Hello");
    while (display.isOpen()) {
        //std::cout << entities[0] << std::endl;
        display.handleEvent();
        update(entities);
        display.draw(entities);
    }
    return  0;
}