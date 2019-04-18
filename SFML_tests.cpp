#include <SFML/System.hpp>
#include <SFML/WIndow.hpp>
#include <SFML/Graphics.hpp>
#include "include/globalVariables.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "include/eventPoll.hpp"
#include "include/font_loader.hpp"
#include "include/stateManager.hpp"

int main() {

font_loader();
    
while(true) {
		
	window.clear(black);
	
	stateManager();

	eventPoll();

	window.display();
	
	if(isClosed == true) {

		break;
	}
}

return 0;

}; 