//
// Created by coons on 03.11.2023.
//

#include "../Header/Animations.h"

void Animation::run_animation(sf::RectangleShape &rectangleShape, int animationNumber, int x, int y, int width,
                              int height, sf::Texture &texture, int delay, sf::RenderWindow &window) {
    rectangleShape.setTexture(&texture);
    rectangleShape.setTextureRect(IntRect(current_animation*x,y,width,height));
    if(timer >= delay)
    {

        current_animation++;
        if(current_animation > animationNumber)
            current_animation = 0;

        rectangleShape.setTextureRect(IntRect(current_animation*x,y,width,height));
        timer = 0;
    }
    else
        timer++;

    window.draw(rectangleShape);
}