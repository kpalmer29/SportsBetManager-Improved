# SportsBetManager-Improved
This program uses inheritance, templating and a linked list structure to store and manage bets of different types. The BetList class contains the linked list structure.
The SportsBetManager class implements multiple instances of BetList in order to manage bets of different types. UserInterface is a rudimentary interface used to test basic functionality - is not exception safe and does not support type checking.

## BetList
BetList.h & BetList.cpp

BetList is a template class which contains the structure for a linked list. It uses the LinkedListNode as a helper class for the linked list implementation.BetList

### Private Variables
* int numBets - the number of bets being held by the linked list
* LinkedListNode<T>* betHead - pointer object to the head of the list

### Functionality
* BetList - constructor
* BetList operator= - assignment operator
* ~BetList - destructor
* getNumBets - gets the number of bets held by BetList
* addBet - adds a bet to the linked list. Bets are added in order of of their date
* getBetsOnDate - returns a string containing all bets on a certain date
* getBetsFor - returns a string containing all bets placed for a certain player/team
* getBetsAgainst - returns a string containing all bets placed against a certain team
* getBetsOfSport - returns a string containing all bets placed of a certain sport
* getAllBets - returns a string containing all bets held by the BetList
* getEarliestDate - returns the date of the first bet object held by the linked list
* getLastDate - returns the date of the last bet object held by the linked list
* deleteAllBets- deletes all bets held by the BetList
* deleteBetsBefore - deletes all bets before a certain date
* deleteBet - deletes a certain bet from the linked list
* deleteBetsFor - deletes all bets placed for a certain player/team
* deleteBetsAgainst - deletes all bets placed against a certain player
* exists - checks if a given bet exists in the BetList
* isEmpty - checks if the BetList is is empty

## SportsBetManager
SportsBetManager.h & SportsBetManager.cpp

This class implements four instances of the BetList linked list class. One to hold Moneyline objects, one to hold Spread objects, one to
hold OverUnder objects, and one to hold Prop objects. The class manages the four linked lists and is accessed directly by the UserInterface.

### Private Variables
* BetList<SportsBet> moneylineArray - linked list to hold MoneyLine objects
* BetList<Spread> spreadArray - linked list to hold Spread objects
* BetList<OverUnder> overUnderArray - linked list to hold OverUnder objects
* BetList<Prop> propArray - linked list to hold Prop objects

### Functionality
* getEarliestDate - private function to get the date of the earliest bet in the four linked list objects
* getLatestDate - private function to get the date of the latest bet in the four linked list objects
* SportsBetManager - constructor
* addSpreadBet - adds a spread bet to spreadArray
* addMoneylineBet - adds a bet to moneylineArray
* addPropBet - adds a bet to propArray
* addOverUnderBet - adds a bet to overUnderArray
* getBetsOnDate - returns a string of all bets stored for a certain date
* getBetsFor - returns a string of all bets placed for a certain player/team
* getBetsAgainst - returns a string of all bets placed against a certain team
* getBetsOfSport - returns a string of all bets placed for a certain sport
* getAllBets - returns all bets held by the SportsBetManager
* getAllPropBets - returns a string of all Prop bets
* deleteAllBets - deletes all bets held by the manager
* deleteBetsBefore - deletes all bets before a certain date
* deleteMoneylineBet - deletes a bet from the moneylineArray
* deletePropBet - deletes a bet from the propArray
* deleteSpreadBet - deletes a bet from the spreadArray
* deleteOverUnderBet - deletes a bet from the overUnderArray
* deleteBetsFor - deletes all bets placed for a certain team/player
* deleteBetsAgainst - deletes all bets placed against a certain team
* isEmpty - returns whether the manager contains any bets

## LinkedListNode
LinkedListNode.h & LinkedListNode.cpp

Templated class which contains the implementation for a linked list node used by BetList class.

### Private Variables
* T bet - templated object to hold the bet
* LinkedListNode<T>* next - node pointer to next node in linked list, or to null if last node in list

### Functionality
* ~LinkedListNode - class destructor
* LinkedListNode - constructor


## SportsBet
Includes SportsBet.h & SportsBet.cpp.

This class describes a MoneyLine bet object.

### Private Variables
* int odds - Indicates the odds of the bet, 110, 300, etc.
* char oddsSymbol - '+' or '-' to denote the direction of the odds
* Date gameDate - Date object storing the date of the event for which the bet is placed about
* std::string sport - The sport of the bet: football, basketball, etc.
* std::string betFor - Who the bet is for: Liverpool, Raiders, etc.
* std::string betAgainst - Who is the opposing team

### Functionality
* getOddsSymbol - returns char '+' or '-' depending on the direction of the odds
* setOddsSymbol - sets oddsSymbol
* getOdds - returns the odds
* setOdds - sets the odds
* getDate - returns gameDate
* setDate - sets gameDate
* getSport - returns sport
* setSport - sets sport
* getFor - returns betFor
* setFor - sets betFor
* getAgainst - returns betAgainst
* setAgainst - sets betAgainst
* toString - method for displaying bet object to screen. Returns a string of how bet object is displayed.
```
Sample return string:
Moneyline - Football
Football Team +110 vs. Chargers
Date: 1/9/2022
```
* equals - checks if two SportsBet objects are equal
* operator== - equality overload

## Spread
Spread.h & Spread.cpp

This class inherits from the SportsBet class and contains all the same base functionality. Additional functionality includes:

### Private Variables
* bool favorite - true if betting over the spread, false if betting under
* double gameSpread - spread of the game

### Functionality
* setSpread - set the spread of the bet
* setFavorite - set direction of bet ()over/under spread)
* getSpread - returns gameSpread
* getFavorite - returns string denoting spread direction
* equals - checks if param Spread object is equal to this Spread object
* operator== - equality overload
* toString - overwrites the base-class toString method.
```
Sample return string:
Hockey- Spread: +1.50
Preds: -200 vs. Rangers
Date:2/14/2022
```

## Prop
Prop.h & Prop.cpp

This class inherits from the SportsBet Class and contains all the same base functionality. Additional functionality includes:

### Private Variables
* String propType - String Holding Prop Category (Points, Goals, Assits, etc.)
* double propLine - line for prop bet
* bool over - betting over or under prop line

### Functionality
* setOver - sets over equal to true or false
* isOver - returns over
* setPropType - set prop category
* getPropType - return prop category
* setPropLine - set line for prop bet object
* getPropLine - return the prop line
* equals - overwrites base-class, determines if param Prop object equals this Prop object
* operator== - equality overload
* toString - overwrites base-class
```
Sample return string:
Basketball- Prop
Lillard Over 12.000000 Points
Odds: -200
Playing Against: Magic
Date: 2/28/2022
```

## OverUnder
OverUnder.h & OverUnder.cpp

This class inherits from the SportsBet Class and contains all the same base functionality. Additional functionality includes:

### Private Variables
* double points - point line for over/under bet
* bool over - true if betting over the bet, false if betting under

### Functionality
* setOver - sets whether betting over or under point line
* setPoints - sets point line for over/under object
* getPoints - returns the points for the over/under bet
* isOver - returns whether better over or under point line
* equals - overwrites base-class. Determines if param OverUnder object is equal to this OverUnder object
* operator== - equality overload
* toString - overwrites base-class
```
Sample return string:
Basketball- Over/Under: Over 98.500000
Bucs: -200 vs. Knicks
Date:2/24/2022
```

## Date
Includes Date.h & Date.cpp. An object to hold and compare dates

### Private Variables
int month, day, year - variables to hold the date

### Functionality
* Date - default constructor
* Date - overload constructor
* toString - outputs the date to a string
* getYear - returns year of date object
* getMonth - returns month of date object
* getDay - returns day of date object
* increment - used for looping. This function increments the date of the object by one day.
* setDate - set the date (day, month, and year)
* equals - check if two dates are the same
* operator overloads: >, <, ==, <=, >=, !=

## UserInterface
UserInterface.cpp

Rudimentary interface containing a main menu and options to access the functionality described by the SportsBetManager class.
This interface does not check or sanitize user input - it assumes correct input.

### Functionality
* printMainMenu - prints the main menu
````
Main Menu Demo:

    SPORTSBET MANAGER

Options:
1. View All Bets
2. Add Bet(s)
3. Delete Bet(s)
4. Update Current Date (Removed all bets from before today's date)
5. View all bets of a certain sport
6. View all bets placed for a certain team/player
7. View all bets placed against a certain team/player
8. Quit
````
* printAddMenu - prints menu displayed when adding a bet
````
Add Menu Demo:

What Type of Bet do you want to add?

1. MoneyLine
2. Spread
3. Prop
4. Over/Under
5. Main Menu
````
* createMoneylineObject - interface for creating a new Moneyline object
* createSpreadObject - interface for creating a new Spread object
* createPropObject - interface for creating a new Prop object
* createOverUnderObject - interface for creating a new OverUnder object
* add - function which calls the appropriate helper methods to create a new bet object and add it to the SportsBetManager
* printDeleteMenu - prints menu displayed when deleting a bet
````
Delete Menu Demo:

Delete Bets
1. Delete MoneyLine Bet
2. Delete Prop Bet
3. Delete Spread Bet
4. Delete Over/Under Bet
5. Delete all bets for a team/player
6. Delete all bets against a team/player7. Delete all bets
8. Main Menu
````
* updateDate - prompts the user to enter today's date, and then calls the deleteBetsBefore function in the SportsBetManager
* main - main function for UserInterface




