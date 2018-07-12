
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "Game.h"

int main() try {	

	//get textures
	sf::Texture textureSegment, textureFood;
	if (!textureSegment.loadFromFile("files/tile.png") || !textureFood.loadFromFile("files/food.png")) {
		std::string myException{ "failed to load texture" };
		throw(myException);
	}

	//get font
	sf::Font font;
	if (!font.loadFromFile("files/arial.ttf")) {
		std::string myException{ "failed to load font" };
		throw(myException);
	}

	//get music
	sf::Music music;
	if (!music.openFromFile("files/8bit.ogg")) {
		std::string myException{ "failed to load music" };
		throw(myException);
	}

	//get sounds
	sf::SoundBuffer bufferCollision, bufferEat;
	if (!bufferCollision.loadFromFile("files/collision.ogg") || !bufferEat.loadFromFile("files/eat.ogg")) {
		std::string myException{ "failed to load sound" };
		throw(myException);
	}

	//get highscore from file
	int highScore{ 0 };
	std::ifstream source;
	source.open("files/highscore.txt", std::ios::in);
	if (source) {
		source >> highScore;
	} else {
		std::string myException{ "failed to open file" };
		throw(myException);
	}
	source.close();

	//start gameloop
	Game::gameLoop(textureSegment, textureFood, font, highScore, &music, bufferCollision, bufferEat);

	//write highscore to file
	std::ofstream destination;
	destination.open("files/highscore.txt", std::ios::out);
	if (!destination) {
		std::string myException{ "failed to open file" };
		throw(myException);
	}
	destination.clear();
	destination << highScore;
	destination.close();

	return 0;
}
catch (std::string& s) {
	std::cerr << s;
	exit(-3);
}
catch (std::exception& e) {
	std::cerr << e.what();
	exit(-2);
}
catch (...) {
	std::cerr << "enexpected error";
	exit(-1);
}