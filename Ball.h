#ifndef BALL_T
#define BALL_T

#include "Entity.h"
#include "Circle.h"

class Ball : public Entity, public Circle
{
private:
	void CheckWallCollisions();
public:
	sf::Color color = sf::Color::White;
	static const float radius; 
	const float speed{ 8.0f };
	sf::Vector2f velocity{ speed, speed };
	int lives;
	bool Loss{ false };
	float StartX, StartY; // Initial starting co-ordinates, for resetting the ball

	Ball(float x, float y, int l);
	void Reinitialize();
	void update() override;
	void draw(sf::RenderWindow& targetWindow) override;
	//~Ball();
};

#endif