
#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Food.h"

/**
 * @class Snake
 *
 * @brief The snake which is controled by the player
 *
 * This class represents the snake that is controled by the player.
 * It starts a small rectangle and grows its tail whenever it eats a
 * piece of food. It's reset when it hits either the wall or its own tail.
 * The snake is represented by a std::vector of segments.
 *
 */
class Snake {
public:

	/** @brief Constructor which creates a snake.
	 * @param [in] winSize The size of the games window.
	 * @param [in] sp The snakes speed.
	 * @param [in] texture The texture of one segment of the snake.
	 *
	 * This method creates a snake. It sets the texture, size, origin and location
	 * of the snakes first segment and inserts it into the std::vector (tail).
	 */
	Snake(const sf::Vector2u winSize, float sp, sf::Texture* texture);

	/** @brief Changes the snakes direction.
	 *
	 * This method changes the direction in which the snakes head (tail[0]) moves depending
	 * on the key that is pressed by the player.
	 */
	void changeDirection();

	/** @brief Resets the snake.
	 *
	 * This method first clears the std::vector (tail). It then inserts only the
	 * starting segment which has its position at the middle of the window.
	 */
	void reset();

	/** @brief Checks if the snake collides with the wall or its tail.
	 * @return A boolean that states if the snake collides.
	 *
	 * This method calculates the distance of the snakes head (tail[0]) to every other segment in the 
	 * std::vector (tail). If the segments collide, the method returns true. Then it checks
	 * if the snake hits the border of the window. If it does, the method returns true.
	 */
	bool checkCollison();

	/** @brief Checks if the snake eats a piece of food.
	 * @param [in] foodPos The position of the food.
	 * @return A boolean that states if the snake eats the food.
	 *
	 * This method calculates the distance between the snakes head (tail[0]) and the given piece of food.
	 * If they collide, the method returns true;
	 */
	bool eats(sf::Vector2f foodPos);

	/** @brief Checks if the snake eats a piece of food.
	 * @param [in] number The number of segments to add.
	 *
	 * This method adds the amount of new segments to the std::vector (tail).
	 */
	void addSegments(int number);

	/** @brief Updates the position of the snake.
	 *
	 * This method reversely iterates through all the segments of the std::vector (tail)  except 
	 * the head (tail[0]) and sets its position to the position of the next segment. Then it moves
	 * the head (tail[0]) by the direction.
	 */
	void update();

	/** @brief Draws all the segments of the snake.
	 * @param [in] window The sf::RenderedWindow of the game.
	 *
	 * This method iterates through the std::vector (tail) and draws all its segments to the window.
	 */
	void draw(sf::RenderWindow& window);

	/** @brief Returns the size of one segment.
	 * @return A sf::Vector2f which represents the segment size.
	 *
	 * This method returns the size of one segment of the std::vector (tail).
	 */
	sf::Vector2f getSegmentSize();

	/** @brief Destructor that destroys a snake.
	 *
	 * This method destroys a snake object.
	 */
	~Snake();

private:

	/**
	 * A sf::Vector2f that represents the size of the games window.
	 */
	sf::Vector2f windowSize;

	/**
	 * A sf::Vector2f which is the direction of the snake.
	 */
	sf::Vector2f direction;

	/**
	 * A sf::RectangleShape which is one segment of the snakes tail.
	 */
	sf::RectangleShape segment;

	/**
	 * A std::vector<sf::RectangleShape> which represents the snakes tail.
	 */
	std::vector<sf::RectangleShape> tail;

	/**
	 * A float value which displays the snakes movement speed.
	 */
	float speed;
};

#endif /* SNAKE_H */
