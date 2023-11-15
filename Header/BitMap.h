
#ifndef ZOMBIENOSPAGHETTI_BITMAP_H
#define ZOMBIENOSPAGHETTI_BITMAP_H
#include <SFML/Graphics.hpp>
#include "Animations.h"
#include "../Header/Player.h"
class BitMap
{
    int stage;
    Texture map;
    Texture menu;
    Texture intrukcja;
    Texture wybor;
public:
    void setStage(int stage);
    int getStage();
    void configureBitMap(sf::RenderWindow &window, View &view);
    BitMap()
    {
        map.loadFromFile("../Textures/mapkadocelowa.png");
        menu.loadFromFile("../Textures/menu.png");
        intrukcja.loadFromFile("../Textures/instrukcja_gotowa.png");
        wybor.loadFromFile("../Textures/wybor.png");
    }
};
#endif //ZOMBIENOSPAGHETTI_BITMAP_H
