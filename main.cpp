#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Shape {
protected:
    float speedX, speedY;
    sf::Color color;
    sf::Vector2f position;
    std::string name;
    sf::Text text;

public:
    virtual void draw(sf::RenderWindow& window, sf::Font& font) = 0;

    void loadFromFile(std::ifstream& file, sf::Font& font) {
        int r, g, b;
        file >> position.x >> position.y >> speedX >> speedY >> r >> g >> b;
        color = sf::Color(r, g, b);

        text.setFont(font);
        text.setString(name);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
    }

    void checkBounds(sf::RenderWindow& window) {
        if (position.x < 0 || position.x > window.getSize().x) {
            speedX = -speedX;
        }
        if (position.y < 0 || position.y > window.getSize().y) {
            speedY = -speedY;
        }
    }
};

class CircleShape : public Shape {
    sf::CircleShape shape;

public:
    CircleShape(float radius) : shape(radius) {
        name = "Circle";
    }

    void draw(sf::RenderWindow& window, sf::Font& font) override {
        checkBounds(window);
        position.x += speedX;
        position.y += speedY;
        shape.setFillColor(color);
        shape.setPosition(position);
        window.draw(shape);

        text.setPosition(position.x, position.y - 30);
        window.draw(text);
    }
};

class RectangleShape : public Shape {
    sf::RectangleShape shape;

public:
    RectangleShape(float width, float height) : shape(sf::Vector2f(width, height)) {
        name = "Rectangle";
    }

    void draw(sf::RenderWindow& window, sf::Font& font) override {
        checkBounds(window);
        position.x += speedX;
        position.y += speedY;
        shape.setFillColor(color);
        shape.setPosition(position);
        window.draw(shape);

        text.setPosition(position.x, position.y - 30);
        window.draw(text);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");

    sf::Font font;
    if (!font.loadFromFile("fonts/0xProtoNerdFont-Regular.ttf")) {
        std::cerr << "Could not load font: arial.ttf\n";
        return 1;
    }

    std::vector<Shape*> shapes;

    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Could not open file: shapes.txt\n";
        return 1;
    }

    std::string shapeType;
    while (file >> shapeType) {
        if (shapeType == "Circle") {
            float radius;
            file >> radius;
            CircleShape* circle = new CircleShape(radius);
            circle->loadFromFile(file, font);
            shapes.push_back(circle);
        } else if (shapeType == "Rectangle") {
            float width, height;
            file >> width >> height;
            RectangleShape* rectangle = new RectangleShape(width, height);
            rectangle->loadFromFile(file, font);
            shapes.push_back(rectangle);
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        for (Shape* shape : shapes) {
            shape->draw(window, font);
        }
        window.display();
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}