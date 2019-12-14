//
// Created by hugo on 14/12/2019.
//

#include <random>
#include "Entity.hpp"

Entity::Entity(int maxMass, std::pair<float, float> maxPosition, std::pair<float, float> maxSpeed) :
                _mass(rand() % maxMass),
                _position(rand() % static_cast<int>(maxPosition.first), rand() % static_cast<int>(maxPosition.second)),
                _speed(rand() % static_cast<int>(maxSpeed.first), rand() % static_cast<int>(maxSpeed.second)) {

    static size_t i = 0;

    switch (i) {
        case 0:
            _color = sf::Color::Red;
            break;
        case 1:
            _color = sf::Color::Blue;
            break;
        case 2:
            _color = sf::Color::Green;
            break;
        default:
            _color = sf::Color::Green;
            break;
    }
    i++;
    if (i >= 3)
        i = 0;
    if (rand() % 2 == 0) {
        _speed.first *= -1;
    }
    if (rand() % 2 == 0) {
        _speed.second *= -1;
    }
}

const std::pair<float, float> &Entity::getPosition() const {
    return _position;
}

void Entity::setPosition(const std::pair<float, float> &position) {
    _position = position;
}

int Entity::getMass() const {
    return _mass;
}

void Entity::setMass(int mass) {
    _mass = mass;
}

const std::pair<float, float> &Entity::getSpeed() const {
    return _speed;
}

void Entity::setSpeed(const std::pair<float, float> &speed) {
    _speed = speed;
}

const sf::Color &Entity::getColor() const {
    return _color;
}

void Entity::setColor(const sf::Color &color) {
    _color = color;
}

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "_position: " << entity._position.first << " " << entity._position.second;
    return os;
}
