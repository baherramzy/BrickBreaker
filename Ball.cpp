#include "Ball.h"

const float Ball::radius{ 8.0f };

Ball::Ball(float x, float y, int l) : StartX(x), StartY(y), lives(l) {
	shape.setPosition(x, y);
	shape.setRadius(radius);
	shape.setOrigin(radius, radius); // Center of the object
	shape.setFillColor(color);
}

void Ball::Reinitialize() {
	shape.setPosition(StartX, StartY);
	velocity.x = velocity.y = speed;
}

void Ball::CheckWallCollisions() {
	if (getLeft() < 0)
		velocity.x = speed; // Send ball flying right
	else if (getRight() > windowWidth)
		velocity.x = -speed; // Send ball flying left

	if (getTop() < 0)
		velocity.y = speed; // Send ball flying downwards
	else if (getTop() > windowHeight) {
		// Lose condition, reduce lives
		--lives;

		// Check for Game Over
		lives == 0 ? Loss = true : Reinitialize();
	}
}

void Ball::update() {
	shape.move(velocity);
	CheckWallCollisions();
}

void Ball::draw(sf::RenderWindow& targetWindow) {
	targetWindow.draw(shape);
}

//Ball::~Ball()
//{
//}
