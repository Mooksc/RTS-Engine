gameTime gameClock;
overworldLocations cityB;
overworldLocations cityA;
overworldLocations cityC;

void overworld_map() {

	cityC.overworldMap(3);
	cityC.drawMap();
	cityB.overworldCity({(float)windowSizeX/8, (float)windowSizeY/8}, "My Second City");
	cityA.overworldCity({(float)windowSizeX/2, (float)windowSizeY/2}, "My First City");
	cityA.levelcheck();
	cityB.levelcheck();
	
};
