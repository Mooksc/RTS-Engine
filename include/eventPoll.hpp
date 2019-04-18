#include "sfmlObjects.hpp"
#include "texture_loader.hpp"
#include "text_function.hpp"
#include "levelObjects.hpp"
#include "gameTime.hpp"
#include "overworldLocations.hpp"
#include "levels_to_update.hpp"
#include "overworld_map.hpp"
#include "character.hpp"
#include "gameState.hpp"
#include "saveGame.hpp"
#include "loadGame.hpp"

void eventPoll() {

	if(window.pollEvent(event)) {

		// if(event.type == sf::Event::TextEntered) {

		// 	if(event.text.unicode < 128)

		// 		std::cout 
		// 			// << "ASCII character typed: " 
		// 			// << static_cast<char>(event.text.unicode) 
		// 			// << std::endl;
		// }

		if(event.type == sf::Event::Closed) {
			
			window.close();
			isClosed = true;
		
		}

		if(event.type == sf::Event::Resized) {

			std::cout 
				<< "new width: "
				<< event.size.width
				<< std::endl;
			std::cout
				<< "new height: "
				<< event.size.height
				<< std::endl;
		}	

		if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F5)) {
				
			saveGame();
		}

		if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F7)) {
				
			loadGame();
		}

		if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
			if(startMenu == false) {
				startMenu = true;
			}
		}

		if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			if(inLevel == true) {
				characterPosX = OGCharPosX;
				characterPosY = OGCharPosY;
				inLevel = false;
			}
		}

		if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
			startMenu = false;
		}

		if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {

			if(gameTime::timePaused == true) {
				gameTime::timePaused = false;
			}

			else {
				gameTime::timePaused = true;
			}
		
		}

		if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add)) {

			if(gameTime::timeMultiplier < 5) {
				gameTime::timeMultiplier ++;
			}
			
		}

		if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract)) {

			if(gameTime::timeMultiplier <= 5) {
				if(gameTime::timeMultiplier > 1) {
					gameTime::timeMultiplier --;
				}
			}
			
		}

		
		
		if(event.type == sf::Event::KeyPressed) {

			charVelocity = 7 * gameTime::timeMultiplier;
			if(gameTime::timePaused == true) {
				charVelocity == 0;
			}

			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
				characterPosY -= charVelocity;
			}

			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
				characterPosY += charVelocity;	
			}

			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				characterPosX += charVelocity;	
			}

			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
				characterPosX -= charVelocity;
			}
		}
		
		if(event.type == sf::Event::MouseButtonPressed) {

			if (event.mouseButton.button == sf::Mouse::Left) {

				// std::cout
				// 	<< "left mouse pressed"
				// 	<< std::endl;
				// std::cout
				// 	<< "press x: "
				// 	<< event.mouseButton.x
				// 	<< std::endl;
				// std::cout
				// 	<< "press y: "
				// 	<< event.mouseButton.y
				// 	<< std:: endl;
			}

		}
	}

		if(!gameTime::timePaused) { 

			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

					mouseX = event.mouseButton.x;
					mouseY = event.mouseButton.y;

					if(characterPosX >= mouseX && characterPosY <= mouseY) {

						characterPosX -= charVelocity;
						characterPosY += charVelocity;
					}
					
					if(characterPosX <= mouseX) {

						characterPosX += charVelocity;
					}

					if(characterPosY >= mouseY) {

						characterPosY -= charVelocity;
					}

			}
		}
		// if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
						
		// 	texture_loader("textures/tomboy_sprite.jpg");
		// 	window.draw(sprite);

		// 	window.display();
		// }
		if(event.type == sf::Event::JoystickButtonPressed) {

			std::cout
				<< "button pressed?"
				<< std::endl;
			std::cout
				<< "controller id"
				<< event.joystickButton.joystickId
				<< std::endl;
			std::cout
				<< "button: "
				<< event.joystickButton.button
				<< std::endl;
		}

		if(event.type == sf::Event::JoystickMoved) {

			if(event.joystickMove.axis == sf::Joystick::X) {

				std::cout
					<< "X xis moved"
					<< std::endl;
				std::cout
					<< "new position: "
					<< event.joystickMove.position
					<< std::endl;
			}
		}

		if(event.type == sf::Event::JoystickConnected) {

			std::cout
				<< "joystick connected: "
				<< event.joystickConnect.joystickId
				<< std::endl;
		}

		if(event.type == sf::Event::JoystickDisconnected) {

			std::cout
				<< "joystick disconnected: "
				<< event.joystickConnect.joystickId
				<< std::endl;
		}
};