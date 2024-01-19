#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    const int wWidth = 1100;
    const int wHeight = 800;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "My window");

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(300.0f, 300.0f);
    float shapeMoveSpeed = 0.01f;

    sf::Font myfont;
    if (!myfont.loadFromFile("fonts/0xProtoNerdFont-Regular.ttf"))
    {
        std::cerr << "could not load font!\n";
        return -1;
    }

    sf::Text text("font test", myfont, 24);
    text.setPosition(0, wHeight - static_cast<float>(text.getCharacterSize()));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        shape.setPosition(shape.getPosition().x + shapeMoveSpeed, shape.getPosition().y + shapeMoveSpeed);

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(text);
        window.display();
    }

    return 0;
}
