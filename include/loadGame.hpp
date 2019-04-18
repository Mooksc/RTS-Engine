#include <sstream>

void loadGame() {
	int var, n;
	int s[4];	
	std::string line, line2;
	std::ifstream loadFile("Sample.sav");

	for(int i = 0; i < 4; ++i){
		
		loadFile >> line >> var;

		s[i] = var;

	}
	
	std::cout
		<< s[0]
		<< std::endl
		<< s[1]
		<< std::endl
		<< s[2]
		<< std::endl
		<< s[3]
		<< std::endl;

gameTime::currentDay = s[0];  
gameTime::currentWeek = s[1];
gameTime::currentMonth = s[2];
gameTime::currentYear = s[3];

};
