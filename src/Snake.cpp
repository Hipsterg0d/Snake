
#include "Snake.h"

Snake::Snake(const sf::Vector2u winSize, float sp, sf::Texture* texture) : windowSize{ static_cast<sf::Vector2f>(winSize) }, direction{ sp, 0.0f }, speed{ sp } {

	segment.setSize(sf::Vector2f(10.0f, 10.0f));
	segment.setOrigin(segment.getSize().x / 2, segment.getSize().y / 2);
	segment.setTexture(texture);

	segment.setPosition(windowSize.x / 2, windowSize.y / 2);
	tail.push_back(segment);
}

void Snake::changeDirection() {
	if (tail.size() == 1) {
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))) {
			direction.x = 0.0f;
			direction.y = -speed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			direction.x = 0.0f;
			direction.y = speed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			direction.x = -speed;
			direction.y = 0.0f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			direction.x = speed;
			direction.y = 0.0f;
		}
	}
	else {
		if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))) && direction.y == 0) {
			direction.x = 0.0f;
			direction.y = -speed;
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && direction.y == 0) {
			direction.x = 0.0f;
			direction.y = speed;
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && direction.x == 0) {
			direction.x = -speed;
			direction.y = 0.0f;
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && direction.x == 0) {
			direction.x = speed;
			direction.y = 0.0f;
		}
	}
}

void Snake::reset() {
	tail.clear();
	tail.push_back(segment);
}

bool Snake::checkCollison() {
	bool collision{ true };

	if ((tail[0].getPosition().y - tail[0].getSize().y / 2 >= 0) && (tail[0].getPosition().y + tail[0].getSize().y / 2 <= windowSize.y) &&
		(tail[0].getPosition().x - tail[0].getSize().x / 2 >= 0) && (tail[0].getPosition().x + tail[0].getSize().x / 2 <= windowSize.x)) {

		collision = false;
	}

	if (tail.size() > 1) {
		for (unsigned int i = 2; i < tail.size(); i++) {
			sf::Vector2f distance(std::abs(tail[0].getPosition().x - tail[i].getPosition().x), std::abs(tail[0].getPosition().y - tail[i].getPosition().y));
			if (distance.x < segment.getSize().x && distance.y < segment.getSize().y) {
				collision = true;
			}
		}
	}

	return collision;
}

bool Snake::eats(sf::Vector2f foodPos) {
	sf::Vector2f distance(std::abs(tail[0].getPosition().x - foodPos.x), std::abs(tail[0].getPosition().y - foodPos.y));
	if (distance.x < segment.getSize().x && distance.y < segment.getSize().y) {
		return true;
	}
	return false;
}

void Snake::addSegments(int number) {
	for (int i = 0; i < number; i++) {
		tail.push_back(segment);
	}

	for (unsigned int i = tail.size() - number; i < tail.size(); i++) {
		tail[i].setPosition(600, 600);
	}
}

void Snake::update() {
	for (int i = tail.size() - 1; i > 0; i--) {
		tail[i].setPosition(tail[i - 1].getPosition());
	}
	tail[0].move(direction);
}

void Snake::draw(sf::RenderWindow& window) {
	for (std::vector<sf::RectangleShape>::iterator it = tail.begin(); it != tail.end(); ++it) {
		window.draw(*it);
	}
}

sf::Vector2f Snake::getSegmentSize() {
	return segment.getSize();
}

Snake::~Snake() {

}