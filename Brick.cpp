#include "Brick.h"

const float Brick::width{ 60.0f }, Brick::height{ 15.0f };

Brick::Brick(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(width,height));
	shape.setFillColor(color);
	shape.setOrigin(width / 2.0f, height / 2.0f);

}

void Brick::update() {

}

void Brick::draw(sf::RenderWindow& targetWindow) {
	targetWindow.draw(shape);
}
