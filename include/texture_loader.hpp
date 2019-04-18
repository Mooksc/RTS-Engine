void texture_loader(std::string file_to_load) {

	if(!texture.loadFromFile(file_to_load)) {

		std::cout
			<< "error?"
			<< std::endl;
	}

	texture.loadFromFile(file_to_load);
	
	sprite.setTexture(texture);

	sf::Vector2u s = texture.getSize();
	
	sprite.setPosition(400, 300);
	sprite.setTextureRect(sf::IntRect(32, 0, 128, 128));
};