//
// Created by coons on 14.11.2023.
//
#include <SFML/Graphics.hpp>
#ifndef ZOMBIENOSPAGHETTI_ARROW_H
#define ZOMBIENOSPAGHETTI_ARROW_H
class Arrow {
public:
    Arrow(int direction, sf::Vector2f position, sf::Texture &texture)
    {
        arrowShape.setTexture(&texture);
        arrowShape.setPosition(position.x,position.y);
        if(direction == 0) {
            arrowShape.setTextureRect(sf::IntRect(0, 1056, 46, 9));
            arrowShape.setSize(sf::Vector2f(35, 7));
        }
        else if (direction == 1) {
            arrowShape.setTextureRect(sf::IntRect(46, 1056, 46, 9));
            arrowShape.setSize(sf::Vector2f(35, 7));
        }
        else if (direction == 2) {
            arrowShape.setTextureRect(sf::IntRect(11, 1066, 8, 46));
            arrowShape.setSize(sf::Vector2f (7,35));
        }
        else {
            arrowShape.setTextureRect(sf::IntRect(0, 1066, 8, 46));
            arrowShape.setSize(sf::Vector2f (7,35));
        }
        this -> direction = direction;

    }
    sf::RectangleShape arrowShape;
    sf::Texture texture;
    int direction;
    void move();
};


#endif //ZOMBIENOSPAGHETTI_ARROW_H
