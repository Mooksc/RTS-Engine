
class gameTime {

	private:

sf::Text overworldText, overworldCurrentDay;

float overworldTextObjectPosX{(float)windowSizeX/windowSizeX}, overworldTextObjectPosY{(float)windowSizeY - 30};

	public:

static int currentDay, currentWeek, currentMonth, currentYear;
static bool timePaused;
static int timeMultiplier;
sf::Time wholeDay;
sf::Time timePassed;

void overworldTime();
bool foodcheck();

};

void gameTime::overworldTime() {
  
    sf::Time wholeDay = sf::seconds(5 / timeMultiplier);
    sf::Time timePassed = overworldClock.getElapsedTime();
    
    if(timePassed > wholeDay) {

        overworldClock.restart();
        
        if(!timePaused) {

            if(currentDay >= 7) {
	            currentDay = 0;
                currentWeek ++;               

                if(currentWeek >= 4) {
                    currentWeek = 1;
                    currentMonth ++;

                    if(currentMonth >= 12) {
                        currentMonth = 1;
                        currentYear ++;
                    }
                }
            }

            currentDay ++;
             
        }

    }
        
        std::string currentDayString = std::to_string(currentDay), currentWeekString = std::to_string(currentWeek), currentMonthString = std::to_string(currentMonth),
                    currentYearString = std::to_string(currentYear), timeMultiplierString= std::to_string(timeMultiplier);

        text_function overworldTextObject("Day:", overworldFont, {overworldTextObjectPosX, overworldTextObjectPosY}, sf::Color::Red, 24);
        text_function overworldTextCurrentDay(currentDayString, overworldFont, {overworldTextObjectPosX + 50, overworldTextObjectPosY}, sf::Color::Red, 24);

        text_function overworldTextObject2("Week:", overworldFont, {overworldTextObjectPosX + 75, overworldTextObjectPosY}, sf::Color::Red, 24);
        text_function overworldTextCurrentWeek(currentWeekString, overworldFont, {overworldTextObjectPosX + 150, overworldTextObjectPosY}, sf::Color::Red, 24);

        text_function overworldTextObject3("Month:", overworldFont, {overworldTextObjectPosX + 175, overworldTextObjectPosY}, sf::Color::Red, 24);
        text_function overworldTextCurrentMonth(currentMonthString, overworldFont, {overworldTextObjectPosX + 250, overworldTextObjectPosY}, sf::Color::Red, 24);

        text_function overworldTextObject4("Year:", overworldFont, {overworldTextObjectPosX + 275, overworldTextObjectPosY}, sf::Color::Red, 24);
        text_function overworldTextCurrentYear(currentYearString, overworldFont, {overworldTextObjectPosX + 325, overworldTextObjectPosY}, sf::Color::Red, 24);

        text_function overworldTextObject5("x", overworldFont, {overworldTextObjectPosX + 750, overworldTextObjectPosY}, sf::Color::Red, 24);
        text_function overworldTextTimeMultiplier(timeMultiplierString, overworldFont, {overworldTextObjectPosX + 775, overworldTextObjectPosY}, sf::Color::Red, 24);

};

bool gameTime::foodcheck() {

    sf::Time wholeDay = sf::seconds(5 / timeMultiplier);
    sf::Time timePassed = overworldClock.getElapsedTime();

    if(timePassed > wholeDay) {

        if(!timePaused){

           if(currentDay >= 7){

              return true;

            }
        }
    }
};

int getcurrentDay() {

    return gameTime::currentDay;
};

bool gameTime::timePaused = true;
int gameTime::timeMultiplier{1};
int gameTime::currentDay{1};
int gameTime::currentWeek{1};
int gameTime::currentMonth{1};
int gameTime::currentYear{1}; 