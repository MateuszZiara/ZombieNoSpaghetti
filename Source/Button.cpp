#include <unistd.h>
#include "../Header/Button.h"
using namespace std;
sf::RectangleShape Button::getButtonBorder() {
    return buttonBorder;
}
void draw_buttons(std::vector<Button> buttons,sf::RenderWindow &window)
{
    for(Button button : buttons)
        window.draw(button.getButtonBorder());
}

void check_if_button_pressed(const std::vector<Button>& vectorButton, sf::RenderWindow &window, int bitmapValue)
{

    for(Button button : vectorButton)
        if(button.getButtonBorder().getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && button.get_bitmap() == bitmapValue)
        {
            button.run_function();
            break;
        }


}
void Button::run_function() {
    function();
}
int Button::get_bitmap() {
    return bitmap;
}
void check_if_button_hovered(const std::vector<Button>& vectorButton, sf::RenderWindow &window, int bitmapValue)
{
    for(Button button : vectorButton)
        if(button.getButtonBorder().getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && button.get_bitmap() == bitmapValue)
        {
            button.run_function();
        }
}
