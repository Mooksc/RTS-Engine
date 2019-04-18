int windowSizeX{800}, windowSizeY{600};
int itercount;

std::vector<float> vecXFloats;
std::vector<float> vecYFloats;

bool isClosed;
bool startMenu;
bool inCity;
bool inLevel;
// character variables -> sort into class later
float mouseX;
float mouseY;
float exitLevelPosX;
float exitLevelPosY;
float characterSizeX{25};
float characterSizeY{25};
float charVelocity{2};
float newCharacterPosX;
float newCharacterPosY;
float OGCharPosX;
float OGCharPosY;
float characterPosX{(float)windowSizeX/2};
float characterPosY{(float)windowSizeY/2};
sf::RectangleShape characterShape(sf::Vector2f(characterSizeX, characterSizeY));
// end character variables
float savedPositionX;
float savedPositionY;