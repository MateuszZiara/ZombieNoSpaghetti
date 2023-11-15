#include "../Header/CustomButtons.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

std::vector<Button> init_buttons(sf::RenderWindow &window, BitMap &bitMap, Player &player, Texture &archerTexture, Texture &berserkTexture)
{
    Button startGame(483,882,389,488, [&bitMap](){
        bitMap.setStage(2);

        },0);
    Button instruction(483,882,490,589,[&bitMap](){
        bitMap.setStage(1);

        },0);
    Button exitButton(483, 882, 631, 730, [&window]() {
        window.close();
    },0);
    Button exitInstruction(480, 891, 616, 711, [&bitMap]() {
        bitMap.setStage(0);
    },1);
    Button berserkerChoose(204,478,647,715,[&bitMap, &player, &berserkTexture] () {
       bitMap.setStage(3);
       player.setKlasa(false);
       player.initModel(berserkTexture);
    },2);
    Button archerChoose(887,1159,647,715,[&bitMap, &player, &archerTexture] () {
       bitMap.setStage(3);
       player.setKlasa(true);
       player.initModel(archerTexture);


    },2);

    std::vector<Button> buttonVector;
    buttonVector.push_back(startGame);
    buttonVector.push_back(instruction);
    buttonVector.push_back(exitButton);
    buttonVector.push_back(exitInstruction);
    buttonVector.push_back(berserkerChoose);
    buttonVector.push_back(archerChoose);
    return buttonVector;
}
std::vector<Button> init_buttonsHovered(sf::RenderWindow &window, BitMap &bitMap, Animation &berserkAnimation, Animation &lucznikAnimation)
{
    Button HalfLeftMenu(0,window.getSize().x/2,0,window.getSize().y,[&berserkAnimation, &window]()
    {
        sf::RectangleShape berserk;
        berserk.setPosition(256,136);
        berserk.setSize(sf::Vector2f(275,343));
        Texture texture;
        texture.loadFromFile("../Textures/menuanima.png");
        berserkAnimation.run_animation(berserk,9,274,343,274,343,texture,5,window);
    },2);
    Button HalfRightMenu(window.getSize().x/2,window.getSize().x,0,window.getSize().y,[&lucznikAnimation, &window]()
    {
        sf::RectangleShape lucznik;
        Texture texture;
        texture.loadFromFile("../Textures/menuanima.png");
        lucznik.setPosition(sf::Vector2f(939,136));
        lucznik.setSize(sf::Vector2f(275,343));
        lucznikAnimation.run_animation(lucznik,9,274,0,274,343,texture,5,window);
    },2);
    std::vector<Button> buttonVector;
    buttonVector.push_back(HalfLeftMenu);
    buttonVector.push_back(HalfRightMenu);
    return buttonVector;
}