#include "../Header/BitMap.h"
void BitMap::setStage(int stage) {
    this->stage = stage;
}
int BitMap::getStage() {
    return stage;
}
void BitMap::configureBitMap(sf::RenderWindow &window, View &view){

    if(stage == 0)
    {
        sf::Sprite sprite;
        sprite.setTexture(menu);
        window.draw(sprite);
    }
    else if(stage == 1)
    {
        sf::Sprite sprite;
        sprite.setTexture(intrukcja);
        window.draw(sprite);

    }
    else if(stage == 2)
    {
        sf::Sprite sprite;
        sprite.setTexture(wybor);
        window.draw(sprite);

    }
    else if(stage == 3)
    {
       sf::Sprite sprite;
        sprite.setTexture(map);
        window.setView(view);
        window.draw(sprite);

    }
}