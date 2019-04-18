
class overworldLocations : public gameTime {

    private:

    public:

int cityFood, cityIndustry, cityPopulation;
int numcount;
float randnumX2;
float randnumX3;



void overworldCity(sf::Vector2f v, std::string s);
void overworldMap(int i);
void drawMap();
void levelcheck();

};

void overworldLocations::levelcheck() {

   if(inLevel == true) {

        characterPosX = (float)windowSizeX/2;
        characterPosY = (float)windowSizeX/2;
        
    }
};

void overworldLocations::overworldMap(int numcount) {

    srand(time(NULL));
    float randnumX, randnumX2, randnumXbufferXUP, randnumXbufferXDOWN, vecXback;

    while(itercount < numcount) {


        randnumX = {rand() % 700 + 0};
        vecXFloats.push_back(randnumX);
        randnumXbufferXDOWN = vecXFloats.back() - 100;
        randnumXbufferXUP = vecXFloats.back() + 100;



           itercount ++; 
        

        

        
    }    

     
};

void overworldLocations::drawMap() {

    sf::RectangleShape shape(sf::Vector2f(100, 100));
    shape.setPosition(sf::Vector2f(vecXFloats[0], 0));
    shape.setFillColor(sf::Color::Green);
    window.draw(shape);
    sf::RectangleShape shape2(sf::Vector2f(100, 100));
    shape2.setPosition(sf::Vector2f(vecXFloats[1], 0));
    shape2.setFillColor(sf::Color::Blue);
    window.draw(shape2);
    sf::RectangleShape shape3(sf::Vector2f(100, 100));
    shape3.setPosition(sf::Vector2f(vecXFloats[2], 0));
    shape3.setFillColor(sf::Color::Red);
    window.draw(shape3);

};


void overworldLocations::overworldCity(sf::Vector2f cityPos, std::string cityName) {
    
    float citySizeX{100}, citySizeY{100};
    float exitLevelPosX;
    float exitLevelPosY;
    
    sf::RectangleShape cityShape(sf::Vector2f(citySizeX, citySizeY));
    cityShape.setPosition(cityPos);
    window.draw(cityShape);
    
    sf::Vector2f cityPosition{cityShape.getPosition()};
    
    sf::Vector2f cityTextVector{cityPosition.x + 25, cityPosition.y + 80};

    std::string foodString = std::to_string(cityFood), industryString = std::to_string(cityIndustry), populationString = std::to_string(cityPopulation);

    text_function textObject(cityName, cityFont, cityTextVector, sf::Color::Black, 10);

    text_function cityTextObject1("F", cityFont, {cityPosition.x, cityPosition.y - 15}, sf::Color::Green, 12);
    text_function cityResourceText1(foodString, cityFont, {cityPosition.x + 7, cityPosition.y - 15}, sf::Color::Green, 12);

    text_function cityTextObject2("I", cityFont, {cityPosition.x + 40, cityPosition.y - 15}, sf::Color::Red, 12);
    text_function cityResourceText2(industryString, cityFont, {cityPosition.x + 47, cityPosition.y - 15}, sf::Color::Red, 12);

    text_function cityTextObject3("P", cityFont, {cityPosition.x + 80, cityPosition.y - 15}, sf::Color::Yellow, 12);
    text_function cityResourceText3(populationString, cityFont, {cityPosition.x + 87, cityPosition.y - 15}, sf::Color::Yellow, 12);

       if(characterPosX >= cityPosition.x - 25 && characterPosX <= cityPosition.x + 100) {

        if(characterPosY >= cityPosition.y - 25 && characterPosY <= cityPosition.y + 100) {
            
            inCity = true;
            OGCharPosX = characterPosX;
            OGCharPosY = characterPosY;
        }
    }
    else {

        inCity = false;
    }

    if(inCity == true) {


        if((event.type == sf::Event::KeyPressed) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {

            
             inLevel = true;
        }
    }

    if(gameTime::foodcheck() == true) {

        cityFood += 1;
    }
}; 