#ifndef PADDLE_T
#define PADDLE_T

#include "Entity.h"
#include "Rectangle.h"

class Paddle : public Entity, public Rectangle
{
private:
	void HandleInput(); // Keyboard handler
public:
	sf::Color color = sf::Color::White; // Color
	static const float width, height; // Dimensions
	const float speed{ 10.0f }; // Player speed
	sf::Vector2f velocity; // Velocity vector

	Paddle(float x, float y);
	void update() override;
	void draw(sf::RenderWindow& targetWindow) override;
};

#endif