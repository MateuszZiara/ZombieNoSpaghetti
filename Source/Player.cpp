#include "../Header/Player.h"
#include "../Header/Animations.h"
#include <iostream>

void Player::setKlasa(bool choose) {
    klasa = choose;
}

sf::RectangleShape Player::getPlayerModel() {
    return playerModel;
}
void Player::move(sf::RenderWindow &window, Animation &Animation, bool hold) {
    if(!hold)
        Animation.current_animation = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerModel.move(0.f,-3.0f);
        //if(klasa)
            Animation.run_animation(playerModel, 9, 69,480,69,96,texture,5,window);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerModel.move(0.f,3.0f);
       // if(klasa)
            Animation.run_animation(playerModel, 9, 69,96,69,96,texture,5,window);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerModel.move(3.f,0.f);
       // if(klasa)
        Animation.run_animation(playerModel,9,69,192,69,96,texture,5,window);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerModel.move(-3.f,0.f);
        //if(klasa)
        Animation.run_animation(playerModel, 9, 69,672,69,96,texture,5,window);
    }
    sf::FloatRect globalBounds = playerModel.getGlobalBounds();
    sf::RectangleShape boundsRect(sf::Vector2f(globalBounds.width, globalBounds.height));
    boundsRect.setPosition(sf::Vector2f(globalBounds.left, globalBounds.top));
    boundsRect.setFillColor(sf::Color(0, 0, 0, 0)); // Transparent fill
    boundsRect.setOutlineColor(sf::Color::Red);
    boundsRect.setOutlineThickness(1.0f);
    window.draw(boundsRect);
}

void Player::initModel(sf::Texture &texture) {
        if(klasa)
             this -> texture.loadFromFile("../Textures/lucznik.png");
        else
            this -> texture.loadFromFile("../Textures/berserker.png");
        playerModel.setTexture(&texture);
        playerModel.setPosition(sf::Vector2f(250,600));
        playerModel.setSize(sf::Vector2f(46,76));
        playerModel.setTextureRect(sf::IntRect(0, 0, 66, 96));

}
bool Player::getKlasa() {
    return klasa;
}
void Player::attack(Animation &shoot, bool &attackKey, int &key, sf::RenderWindow &window, vector<Arrow> &arrowVector, int &delaycount, Texture &textureArrow) {
    delaycount++;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        key = 1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        key = 2;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        key = 3;
    else
        key = 0;

    if(shoot.current_animation == 5 && delaycount >= 6 && getKlasa())
    {
        Arrow arrow(key,sf::Vector2f(playerModel.getPosition().x,playerModel.getPosition().y+playerModel.getSize().y/2-12), textureArrow);
        arrowVector.push_back(arrow);
        delaycount = 0;
    }
    if(shoot.current_animation == 9) {
        attackKey = false;
        shoot.current_animation = 0;
    }
    if(key == 0) {
        shoot.run_animation(playerModel, 9, 69, 288, 69, 96, texture, 5, window);
    }
    else if(key == 1){
        shoot.run_animation(playerModel,9,69,768,69,96,texture,5,window);
    }
    else  if(key == 3){
        shoot.run_animation(playerModel,9,69,864,69,96,texture,5,window);
    }
    else{
        shoot.run_animation(playerModel,9,69,576,69,96,texture,5,window);
    }


}
