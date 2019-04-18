int saveGame() {

	std::ofstream saveFile;

	saveFile.open("Sample.sav");


	if(saveFile.is_open()) {

	saveFile << "currentDay: ";
	saveFile << gameTime::currentDay << std::endl;

	saveFile << "currentWeek: ";
	saveFile << gameTime::currentWeek << std::endl;

	saveFile << "currentMonth: ";
	saveFile << gameTime::currentMonth << std::endl;

	saveFile << "currentYear: ";
	saveFile << gameTime::currentYear << std::endl;
	
	saveFile.close();

	}

	return 0;

	
};