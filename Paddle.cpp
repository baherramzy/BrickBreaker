#include "Paddle.h"

const float Paddle::width{ 75.0f }, Paddle::height{ 20.0f };

Paddle::Paddle(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setOrigin(width / 2.0f, height / 2.0f);
}

void Paddle::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeft() > 0)
		velocity.x = -speed;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRight() < windowWidth)
		velocity.x = speed;
	else
		velocity.x = 0;
}

void Paddle::update() {
	HandleInput();
	shape.move(velocity);
}

void Paddle::draw(sf::RenderWindow& targetWindow) {
	targetWindow.draw(shape);
}
