#ifndef BRICK_T
#define BRICK_T

#include "Entity.h"
#include "Rectangle.h"

class Brick : public Entity, public Rectangle
{
public:
	static const float width, height;
	sf::Color color = sf::Color::Red;
	bool destroyed = false;

	Brick(float x, float y);
	void update() override;
	void draw(sf::RenderWindow& targetWindow) override;
	//~Brick();
};

#endif