
#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>
#include <random>

/**
 * @class Food
 *
 * @brief The food that can be eaten by the snake
 *
 * This class displays the food which can be eaten by
 * the players snake. The food is represented by a sf::RectangleShape.
 *
 */
class Food {
public:

	/** @brief Constructor which creates a piece of food.
	 * @param [in] winSize The size of the games window.
	 * @param [in] texture The foods texture.
	 *
	 * This method creates a piece of food. It sets the texture, size and origin
	 * of the food. It then calls the reset() method to spawn it at a random location.
	 */
	Food(const sf::Vector2u winSize, sf::Texture* texture);

	/** @brief Resets the foods position to a random position.
	 *
	 * This method calls the getRandom method to calculate random
	 * x and y coordinates and then sets the bodys position to them.
	 */
	void reset();

	/** @brief Draws the piece of food.
	 * @param [in] window The sf::RenderedWindow of the game.
	 *
	 * This method draws the body of the food to the games window.
	 */
	void draw(sf::RenderWindow& window);

	/** @brief Returns the foods position.
	 * @return A sf::Vector2f which represents the foods position.
	 *
	 * This method returns the x and y coordinates of the bodys position in
	 * a Vector.
	 */
	sf::Vector2f getPosition();

	/** @brief Destructor that destroys a piece of food.
	 *
	 * This method destroys a food object.
	 */
	~Food();

private:

	/**
	 * A sf::Vector2f that represents the size of the games window.
	 */
	sf::Vector2f windowSize;

	/**
	 * A sf::RectangleShape which is the foods body.
	 */
	sf::RectangleShape body;

	/**
	 * A std::random_device which is used to get random numbers.
	 */
	std::random_device randDevice;	

	/** @brief Calculates a random number.
	 * @param [in] max_v The random numbers max value.
	 * @param [in] min_v The random numbers min value.
	 * @param [in] stp The random numbers step value.
	 * @return A float which is a random number.
	 *
	 * This method returns a random float value between given max and min
	 * with the given steps.
	 */
	float getRandom(float max_v, float min_v, float stp);
};

#endif /* FOOD_H */