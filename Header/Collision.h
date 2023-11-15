#include <SFML/Graphics.hpp>
#include <iostream>
template<typename T> bool collisionWithBorderRect(T obj, sf::RenderWindow &window) {
    sf::FloatRect objectBounds = obj.getGlobalBounds();


    if (objectBounds.left < 0 || objectBounds.top < 0 ||
        objectBounds.left + objectBounds.width > window.getSize().x ||
        objectBounds.top + objectBounds.height > window.getSize().y) {
        return true;
    } else {
        return false;
    }
}
bool isRectangleTouchingField(const sf::RectangleShape& rect, std::vector<sf::Vector2f> points, sf::RenderWindow& window);


#ifndef ZOMBIENOSPAGHETTI_MOVE_H
#define ZOMBIENOSPAGHETTI_MOVE_H

#endif //ZOMBIENOSPAGHETTI_MOVE_H
