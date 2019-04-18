void gameState() {

	gameClock.overworldTime();

	character(characterPosX, characterPosY);

	if(inLevel == true) {

		levels_to_update();
	
        }

	else {

		overworld_map();
	}
};
