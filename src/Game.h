
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <chrono>
#include <thread>

#include "Snake.h"
#include "Food.h"

/**
 * @class Game
 *
 * @brief Contains the gameloop.
 *
 * This class is called by the main.cpp and is the actual game. It contains
 * the gameloop which loops until the game ends.
 *
 */
class Game
{
public:

	/** @brief Constructor which creates a game.
	 *
	 * This method creates a game.
	 */
	Game();

	/** @brief The actual gameloop.
	 * @param [in] textureSegment The texture of one segment of a snake.
	 * @param [in] textureFood The texture of a food.
	 * @param [in] font The font for the text.
	 * @param [in] highScore The current highscore.
	 * @param [in] music The games background music.
	 * @param [in] bufferCollision The sound for a collision.
	 * @param [in] bufferEat The sound for eating food.
	 *
	 * At first this method sets up the required objects, variables and the window.
	 * It contains a loop that loops until the x-button is clicked. In the loop it calls methods, checks 
	 * conditions and draws everything to the window.
	 */
	static void gameLoop(sf::Texture textureSegment, sf::Texture textureFood, sf::Font font, int& highScore, sf::Music* music, sf::SoundBuffer bufferCollision, sf::SoundBuffer bufferEat);

	/** @brief Destructor which destroys a game.
	 *
	 * This method destroys a game.
	 */
	~Game();
};

#endif /* GAME_H */