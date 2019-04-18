class levelObjects {

public:

void genBuildings(int a);

};

void levelObjects::genBuildings(int a) {

	float x{100};
	float y{100};

	float bldgSizeX{100}, bldgSizeY{100};

	for(int i = 0; i < a; i++) {

		sf::RectangleShape buildingShape(sf::Vector2f(bldgSizeX, bldgSizeY));
		buildingShape.setPosition(sf::Vector2f(x,y));
		window.draw(buildingShape);	
		
		x += 125;
			
	}
			    
};