#ifndef CIRCLE_T
#define CIRCLE_T

#include <SFML\Graphics.hpp>

struct Circle // Declared as a struct to make methods public by default
{
	sf::CircleShape shape;

	float getX() const			{ return shape.getPosition().x; }
	float getY() const			{ return shape.getPosition().y; }
	float getRadius() const		{ return shape.getRadius(); }
	float getLeft() const		{ return getX() - getRadius(); }
	float getRight() const		{ return getX() + getRadius(); }
	float getTop() const		{ return getY() - getRadius(); }
	float getBottom() const		{ return getY() + getRadius(); }
};

#endif