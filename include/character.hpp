void character(float characterPosX, float characterPosY) {

	characterShape.setPosition(characterPosX, characterPosY);
	window.draw(characterShape);
};

void newCharacterPos() {

	characterShape.setPosition(newCharacterPosX, newCharacterPosY);
	window.draw(characterShape);

};

void setCharacterPos(float x, float y) {


	characterShape.setPosition(x, y);
	window.draw(characterShape);
	characterPosX = x;
	characterPosY = y;
}

float returnCharacterPosX() {

	return characterPosX;
}

float returnCharacterPosY() {

	return characterPosY;

}

