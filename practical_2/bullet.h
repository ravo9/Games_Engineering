#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
	void Update(const float &dt);
	Bullet(const sf::Vector2f &pos, 
}