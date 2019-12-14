//
// Created by hugo on 14/12/2019.
//

#include <random>
#include "Entity.hpp"

Entity::Entity(int maxMass, std::pair<float, float> maxPosition, std::pair<float, float> maxSpeed) :
                _mass(rand() % maxMass),
                _position(rand() % static_cast<int>(maxPosition.first), rand() % static_cast<int>(maxPosition.second)),
                _speed(rand() % static_cast<int>(maxSpeed.first), rand() % static_cast<int>(maxSpeed.second)) {

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
