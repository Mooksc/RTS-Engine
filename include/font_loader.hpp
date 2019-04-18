void font_loader() {
	if (!cityFont.loadFromFile("impact.ttf")) {

		std::cout
			<< "error loading font";

		}

	if (!overworldFont.loadFromFile("impact.ttf")) {

		std::cout
			<< "error loading font";

		}

	if (!font.loadFromFile("impact.ttf")) {

		std::cout
			<< "error loading font";

		}

};