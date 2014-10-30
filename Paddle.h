#ifndef PADDLE_T
#define PADDLE_T

#include "Entity.h"
#include "Rectangle.h"

class Paddle : public Entity, public Rectangle
{
private:
	void HandleInput();
public:
	sf::Color color = sf::Color::White;
	static const float width, height;
	const float speed{ 10.0f };
	sf::Vector2f velocity;

	Paddle(float x, float y);
	void update() override;
	void draw(sf::RenderWindow& targetWindow) override;
	//~Paddle();
};

#endif