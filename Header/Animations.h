#ifndef ZOMBIENOSPAGHETTI_ANIMATIONS_H
#define ZOMBIENOSPAGHETTI_ANIMATIONS_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class Animation
{
private:
    int timer;
public:
    Animation()
    {
        timer = 0;
        current_animation = 0;
    }

    void run_animation(RectangleShape &rectangleShape, int animationNumber, int x, int y,int width, int height, Texture &texture, int delay, sf::RenderWindow &window);
    int current_animation;
};



#endif //ZOMBIENOSPAGHETTI_ANIMATIONS_H
