
#include "Game.h"

Game::Game(){

}

void Game::gameLoop(sf::Texture textureSegment, sf::Texture textureFood, sf::Font font, int& highScore, sf::Music* music, sf::SoundBuffer bufferCollision, sf::SoundBuffer bufferEat) {

	//set up window
	sf::RenderWindow window(sf::VideoMode(510, 510), "Snake", sf::Style::Close);
	sf::Text textScore, textHighScore;

	//variables
	int score{ 0 };
	Snake snake(window.getSize(), 10.0f, &textureSegment);
	Food food(window.getSize(), &textureFood);

	//set max framerate
	window.setFramerateLimit(18);

	//set up text for score
	textScore.setFont(font);
	textScore.setPosition(sf::Vector2f(10.0f, 10.0f));
	textScore.setCharacterSize(12);
	textScore.setString("Score: " + std::to_string(score));

	//set up text for highscore
	textHighScore.setFont(font);
	textHighScore.setPosition(sf::Vector2f(window.getSize().x - 90.0f, 10.0f));
	textHighScore.setCharacterSize(12);
	textHighScore.setString("HighScore: " + std::to_string(highScore));

	//set up sounds
	sf::Sound soundCollision, soundEat;
	soundCollision.setBuffer(bufferCollision);
	soundEat.setBuffer(bufferEat);

	//play music
	music->setLoop(true);
	music->play();

	//actual gameloop
	while (window.isOpen())
	{
		//check for events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//check if snake eats food -> reset food/add score if true
		if (snake.eats(food.getPosition())) {
			soundEat.play();
			food.reset();
			snake.addSegments(5);		
			score += 10;
			textScore.setString("Score: " + std::to_string(score));
		}

		//move snake
		snake.changeDirection();
		snake.update();
		
		//check for colission -> reset snake/food/score if true
		if (snake.checkCollison()) {
			snake.reset();
			food.reset();
			score = 0;
			textScore.setString("Score: " + std::to_string(score));
			music->pause();
			soundCollision.play();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			music->play();
		}

		//check if new highscore
		if (score > highScore) {
			highScore = score;
			textHighScore.setString("HighScore: " + std::to_string(highScore));
		}

		//draw
		window.clear(sf::Color(205, 201, 201));
		window.draw(textScore);
		window.draw(textHighScore);
		food.draw(window);
		snake.draw(window);
		window.display();
	}
}

Game::~Game(){

}