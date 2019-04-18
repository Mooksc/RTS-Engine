#include "startmenuState.hpp"

void stateManager() {
	
	if(startMenu == false) {

		startmenuText();
	}

	else {
		
		gameState();
	}
};