//
// Created by hugo on 14/12/2019.
//

#ifndef GRAVITYSIMULATOR_RENDERSYSTEM_HPP
#define GRAVITYSIMULATOR_RENDERSYSTEM_HPP

#include <SFML/Graphics.hpp>
#include <string>

class RenderSystem {
private:
    sf::RenderWindow _window;
public:
    RenderSystem();
    ~RenderSystem();

    void createWindow(int width, int length, const std::string &title);
    void createWindowFullScreen(const std::string &title);
    void closeWindow();
    bool isOpen() const;
    void handleEvent();
    void draw();

};


#endif //GRAVITYSIMULATOR_RENDERSYSTEM_HPP
