//
// Created by coons on 31.10.2023.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>

class Button
{
public:
    Button(int minX, int maxX, int minY, int maxY, std::function<void()> function, int bitmap = -1)
    {
        this->minX = minX;
        this->maxX = maxX;
        this->minY = minY;
        this->maxY = maxY;
        buttonBorder.setSize(sf::Vector2f(maxX - minX, maxY - minY));
        buttonBorder.setPosition(minX,minY);
        buttonBorder.setFillColor(sf::Color(0,0,0,0));
        this->function = function;
        this->bitmap = bitmap;
    }
    sf::RectangleShape getButtonBorder();
    void run_function();
    int get_bitmap();
private:
    int minX;
    int maxX;
    int minY;
    int maxY;
    int bitmap;
    sf::RectangleShape buttonBorder;
public:
    std::function<void()> function;
};
void check_if_button_pressed(const std::vector<Button>& vectorButton, sf::RenderWindow &window, int bitmapValue = -1);
void draw_buttons(std::vector<Button> , sf::RenderWindow &window);
void check_if_button_hovered(const std::vector<Button>& vectorButton, sf::RenderWindow &window, int bitmapValue = -1);
#ifndef ZOMBIENOSPAGHETTI_BUTTON_H
#define ZOMBIENOSPAGHETTI_BUTTON_H

#endif //ZOMBIENOSPAGHETTI_BUTTON_H
