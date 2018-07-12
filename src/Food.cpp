
#include "Food.h"

Food::Food(const sf::Vector2u winSize, sf::Texture* texture) : windowSize{ static_cast<sf::Vector2f>(winSize) } {
	body.setSize(sf::Vector2f(10.0f, 10.0f));
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setTexture(texture);

	reset();
}

void Food::reset() {
	float x = getRandom(windowSize.x - (body.getSize().x / 2), body.getSize().x / 2, body.getSize().x);
	float y = getRandom(windowSize.y - (body.getSize().y / 2), body.getSize().y / 2, body.getSize().y);
	body.setPosition(x, y);
}

void Food::draw(sf::RenderWindow& window) {
	window.draw(body);
}

sf::Vector2f Food::getPosition() {
	return body.getPosition();
}

float Food::getRandom(float max_v, float min_v, float stp)
{
	int max_value = static_cast<int>(max_v);
	int min_value = static_cast<int>(min_v);
	int step = static_cast<int>(stp);
	int random_value = (randDevice() % ((++max_value - min_value) / step)) * step + min_value;
	return static_cast<float>(random_value);
}

Food::~Food() {

}