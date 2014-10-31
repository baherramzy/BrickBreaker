#ifndef RECTANGLE_T
#define RECTANGLE_T

#include <SFML\Graphics.hpp>

struct Rectangle // Declared as a struct to make methods public by default
{
	sf::RectangleShape shape;

	float getX() const			{ return shape.getPosition().x; }
	float getY() const			{ return shape.getPosition().y; }
	float getWidth() const		{ return shape.getSize().x; }
	float getHeight() const		{ return shape.getSize().y; }
	float getLeft() const		{ return getX() - getWidth() / 2.0f; }
	float getRight() const		{ return getX() + getWidth() / 2.0f; }
	float getTop() const		{ return getY() - getHeight() / 2.0f; }
	float getBottom() const		{ return getY() + getHeight() / 2.0f; }
};

#endif