#ifndef ZOMBIENOSPAGHETTI_CUSTOMBUTTONS_H
#define ZOMBIENOSPAGHETTI_CUSTOMBUTTONS_H
#include <vector>
#include "Button.h"
#include "BitMap.h"
#include "../Header/Player.h"
std::vector<Button> init_buttons(sf::RenderWindow &window, BitMap &bitMap,Player &player, Texture &archerTexture, Texture &berserkTexture);
std::vector<Button> init_buttonsHovered(sf::RenderWindow &window, BitMap &bitMap, Animation &berserkAnimation, Animation &lucznikAnimation);
#endif //ZOMBIENOSPAGHETTI_CUSTOMBUTTONS_H
