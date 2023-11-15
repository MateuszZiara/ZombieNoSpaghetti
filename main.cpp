#include <SFML/Graphics.hpp>
#include "Header/WindowConfig.h"
#include "Header/Collision.h"
#include "Header/BitMap.h"
#include "Header/CustomButtons.h"
#include "Header/Player.h"
#include "Header/Arrow.h"
#include <unistd.h>
using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Zombiaki no spagetti!");
    WindowConfig::setDefault(window);
    //Zmienne
    bool wasMouseButtonPressed = false;
    bool wasWalkKeysPressed = false;
    bool wasShootKeyPressed = false;
    Player player;
    BitMap bitMap;
    bitMap.setStage(0);
    int key = -1;
    int delayCount = 0;
    View view(sf::Vector2f(0.f,0.f), sf::Vector2f (window.getSize()));
    float halfWindowWidth = window.getSize().x / 4;
    float halfWindowHeight = window.getSize().y / 4;

    //Vectos
    vector<Arrow> arrowVector;
    std::vector<sf::Vector2f> points = {
            sf::Vector2f(0, 511),
            sf::Vector2f(354, 452),
            sf::Vector2f(458, 0),
            sf::Vector2f(300, 100),
            sf::Vector2f(500, 300),

    };
    //Animations
    Animation LucznikMenu;
    Animation BerserkMenu;
    Animation walk;
    Animation idle;
    Animation shoot;
    //Tekstury
    Texture archerTexture;
    archerTexture.loadFromFile("../Textures/lucznik.png");
    Texture berserkTexture;
    berserkTexture.loadFromFile("../Textures/berserker.png");
    Texture arrowTexture;
    arrowTexture.loadFromFile("../Textures/lucznik.png");
    //Buttons
    std::vector<Button> buttonVector = init_buttons(window, bitMap, player, archerTexture, berserkTexture);
    std::vector<Button> buttonVectorHovered = init_buttonsHovered(window, bitMap, BerserkMenu, LucznikMenu);
    draw_buttons(buttonVector,window);
    while (window.isOpen())
    {
       sf::Vector2f viewCenter(player.getPlayerModel().getPosition().x, player.getPlayerModel().getPosition().y);
        viewCenter.x = std::min(std::max(viewCenter.x, halfWindowWidth), window.getSize().x - halfWindowWidth);
        viewCenter.y = std::min(std::max(viewCenter.y, halfWindowHeight), window.getSize().y - halfWindowHeight);
        view.setCenter(viewCenter);
        view.setSize(window.getSize().x / 2, window.getSize().y / 2);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

            window.clear();
        if(!wasShootKeyPressed)
            player.move(window,walk,wasWalkKeysPressed);
        if(!wasMouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            check_if_button_pressed(buttonVector, window, bitMap.getStage());
        }
        wasMouseButtonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            wasWalkKeysPressed = true;
        else
            wasWalkKeysPressed = false;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            wasShootKeyPressed = true;

        if(!wasWalkKeysPressed && !wasShootKeyPressed)
        {
            idle.run_animation(player.playerModel,9,69,0,69,96,player.texture,5,window);
        }
        if(wasShootKeyPressed)
                player.attack(shoot, wasShootKeyPressed, key, window, arrowVector, delayCount, arrowTexture);

        bitMap.configureBitMap(window,view);

        for(int i = 0; i < arrowVector.size(); ++i)
        {
            arrowVector[i].move();
            if(collisionWithBorderRect(arrowVector[i].arrowShape,window)) {
                arrowVector.erase(arrowVector.begin() + i);
                break;
            }
            window.draw(arrowVector[i].arrowShape);
        }
        for (std::size_t i = 0; i < points.size(); ++i) {
            sf::Vertex line[] = {
                    sf::Vertex(points[i]),
                    sf::Vertex(points[(i + 1) % points.size()])
            };
            window.draw(line, 2, sf::Lines);
        }
        cout<<isRectangleTouchingField(player.playerModel, points, window);
        check_if_button_hovered(buttonVectorHovered,window,bitMap.getStage());
        window.draw(player.getPlayerModel());
        window.display();


    }

    return 0;
}