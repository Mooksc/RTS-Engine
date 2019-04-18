class text_function {

public:
	

sf::Text text;


text_function(std::string, sf::Font f, sf::Vector2f, sf::Color, int textSize);

};

text_function::text_function(std::string str, sf::Font font, sf::Vector2f textPos, sf::Color textColor, int textSize) {

	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(textSize);
	text.setFillColor(textColor);
	text.setPosition(textPos);
	window.draw(text);
};