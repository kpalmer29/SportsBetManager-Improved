//
// Created by Kavi Palmer on 1/11/22.
//

#include "SportsBetManager.h"
#include <iostream>
#include <sstream>


void printMainMenu() {
    std::cout << "    SPORTSBET MANAGER\n"
              << "\n"
              << "Options:\n"
              << "1. View All Bets\n"
              << "2. Add Bet(s)\n"
              << "3. Delete Bet(s)\n"
              << "4. Update Current Date (Removed all bets from before today's date)\n"
              << "5. View all bets of a certain sport\n"
              << "6. View all bets placed for a certain team/player\n"
              << "7. View all bets placed against a certain team/player\n"
              << "8. Quit\n";
}

void printAddMenu() {
    std::cout << "What Type of Bet do you want to add?\n\n"
              << "1. MoneyLine\n"
              << "2. Spread\n"
              << "3. Prop\n"
              <<"4. Over/Under\n"
              <<"5. Main Menu\n";
}

SportsBet createMoneylineObject() {
    SportsBet newBet;

    std::cout << "\nSport: ";
    std::string spt;
    std::cin >> spt;
    newBet.setSport(spt);

    std::cout << "\nTeam Betting For: ";
    std::string betFor;
    std::cin >> betFor;
    newBet.setBetFor(betFor);

    std::cout << "\nTeam Betting Against: ";
    std::string betAgainst;
    std::cin >> betAgainst;
    newBet.setBetAgainst(betAgainst);

    std::cout << "\nOdds (first character + or -, followed by number): ";
    std::string odds;
    std::cin >> odds;
    char symbol = odds[0];
    int length = odds.length();
    std::string newOdds = odds.substr(1, length-1);
    std::stringstream oddsStream(newOdds);
    int finalOdd;
    oddsStream >> finalOdd;
    newBet.setOddsSymbol(symbol);
    newBet.setOdds(finalOdd);

    int month, day, year;
    std::cout <<"\nGame Date:\n"
              << "Month (number 1-12): ";
    std::cin >> month;
    std::cout << "\nDay: ";
    std::cin >> day;
    std::cout << "\nYear: ";
    std::cin >> year;
    newBet.setDate(day, month, year);
    std::cout << "Done";

    return newBet;
}

Spread createSpreadObject() {
    Spread newBet;

    std::cout << "\nSport: ";
    std::string spt;
    std::cin >> spt;
    newBet.setSport(spt);

    std::cout << "\nTeam Betting For: ";
    std::string betFor;
    std::cin >> betFor;
    newBet.setBetFor(betFor);

    std::cout << "\nTeam Betting Against: ";
    std::string betAgainst;
    std::cin >> betAgainst;
    newBet.setBetAgainst(betAgainst);

    std::cout << "\nOdds (first character + or -, followed by number): ";
    std::string odds;
    std::cin >> odds;
    char symbol = odds[0];
    int length = odds.length();
    std::string newOdds = odds.substr(1, length-1);
    std::stringstream oddsStream(newOdds);
    int finalOdd;
    oddsStream >> finalOdd;
    newBet.setOddsSymbol(symbol);
    newBet.setOdds(finalOdd);

    std::cout << "\nSpread (omit + or -): ";
    double spread;
    std::cin >> spread;
    newBet.setSpread(spread);
    std::cout << "\nSpread Direciton (+ or -): ";
    char direction;
    std::cin >> direction;
    newBet.setFavorite(direction == '-');

    int month, day, year;
    std::cout <<"\nGame Date:\n"
              << "Month (number 1-12): ";
    std::cin >> month;
    std::cout << "\nDay: ";
    std::cin >> day;
    std::cout << "\nYear: ";
    std::cin >> year;
    newBet.setDate(day, month, year);
    std::cout << "Done";

    return newBet;
}

Prop createPropObject() {
    Prop newBet;

    std::cout << "\nSport: ";
    std::string spt;
    std::cin >> spt;
    newBet.setSport(spt);

    std::cout << "\nPlayer Betting For (last name only): ";
    std::string betFor;
    std::cin >> betFor;
    newBet.setBetFor(betFor);

    std::cout << "\nTeam Playing Against: ";
    std::string teamAgainst;
    std::cin >> teamAgainst;
    newBet.setBetAgainst(teamAgainst);

    std::cout << "\nOdds (first character + or -, followed by number): ";
    std::string odds;
    std::cin >> odds;
    char symbol = odds[0];
    int length = odds.length();
    std::string newOdds = odds.substr(1, length-1);
    std::stringstream oddsStream(newOdds);
    int finalOdd;
    oddsStream >> finalOdd;
    newBet.setOddsSymbol(symbol);
    newBet.setOdds(finalOdd);

    std::cout << "\nProp Category (receptions, rebounds, etc.): ";
    std::string category;
    std::cin >> category;
    newBet.setPropType(category);
    std::cout << "\nProp Line (i.e. if bet is over 8.5 rebounds, enter 8.5): ";
    double line;
    std::cin >> line;
    newBet.setPropLine(line);
    std::cout << "\nBet over of under the prop line? ('o' for over, anything else for under): ";
    char propOver;
    std::cin >> propOver;
    if (propOver == 'o')
        newBet.setOver(true);
    else
        newBet.setOver(false);

    int month, day, year;
    std::cout <<"\nGame Date:\n"
              << "Month (number 1-12): ";
    std::cin >> month;
    std::cout << "\nDay: ";
    std::cin >> day;
    std::cout << "\nYear: ";
    std::cin >> year;
    newBet.setDate(day, month, year);
    std::cout << "Done";

    return newBet;
}

OverUnder createOverUnderObject() {
    OverUnder newBet;

    std::cout << "\nSport: ";
    std::string spt;
    std::cin >> spt;
    newBet.setSport(spt);

    std::cout << "\nTeam Betting For: ";
    std::string betFor;
    std::cin >> betFor;
    newBet.setBetFor(betFor);

    std::cout << "\nTeam Betting Against: ";
    std::string betAgainst;
    std::cin >> betAgainst;
    newBet.setBetAgainst(betAgainst);

    std::cout << "\nOdds (first character + or -, followed by number): ";
    std::string odds;
    std::cin >> odds;
    char symbol = odds[0];
    int length = odds.length();
    std::string newOdds = odds.substr(1, length-1);
    std::stringstream oddsStream(newOdds);
    int finalOdd;
    oddsStream >> finalOdd;
    newBet.setOddsSymbol(symbol);
    newBet.setOdds(finalOdd);

    std::cout << "\nIf better over enter 'o' (lower case). Otherwise under will be selected. ";
    char over;
    std::cin >> over;
    if (over == 'o')
        newBet.setOver(true);
    else
        newBet.setOver(false);

    std::cout << "Enter the line (i.e. if better over 45.5 points, enter: 45.5): ";
    double line;
    std::cin >> line;
    newBet.setPoints(line);

    int month, day, year;
    std::cout <<"\nGame Date:\n"
              << "Month (number 1-12): ";
    std::cin >> month;
    std::cout << "\nDay: ";
    std::cin >> day;
    std::cout << "\nYear: ";
    std::cin >> year;
    newBet.setDate(day, month, year);
    std::cout << "Done";
    return newBet;
}

void add(SportsBetManager &Manager) {
    char add = 'y';
    while (add == 'y') {
        printAddMenu();
        int addOption;
        std::cin >> addOption;
        if (addOption == 1) {
            SportsBet newBet = createMoneylineObject();
            Manager.addMoneylineBet(newBet);
        }
        else if (addOption == 2) {
            Spread newBet = createSpreadObject();
            Manager.addSpreadBet(newBet);
        }
        else if (addOption == 3) {
           Prop newBet = createPropObject();
           Manager.addPropBet(newBet);
        }
        else if (addOption == 4) {
            OverUnder newBet = createOverUnderObject();
            Manager.addOverUnderBet(newBet);
        }
        else if (addOption == 5) {
            add = 'n';
        }
        else {
            std::cout << "\nInvalid Input\n";
        }
        std::cout << "\nAdd another bet? (enter 'y' if yes, anything else for no): ";
        char input;
        std::cin >> input;
        add = input;
    }
}

void printDeleteMenu() {
    std::cout << "\nDelete Bets\n";
    std::cout << "1. Delete MoneyLine Bet\n";
    std::cout << "2. Delete Prop Bet\n";
    std::cout << "3. Delete Spread Bet\n";
    std::cout << "4. Delete Over/Under Bet\n";
    std::cout << "5. Delete all bets for a team/player\n";
    std::cout << "6. Delete all bets against a team/player";
    std::cout << "7. Delete all bets\n";
    std::cout << "8. Main Menu\n";
}

void deleteBets(SportsBetManager &Manager) {
    char deleteBet = 'y';
    while (deleteBet == 'y') {
        printDeleteMenu();
        int deleteOption;
        std::cin >> deleteOption;
        if (deleteOption == 1) {
            std::cout << "\nEnter information about moneyline bet to delete:\n";
            SportsBet newBet = createMoneylineObject();
            Manager.deleteMoneylineBet(newBet);
        }
        else if (deleteOption == 2) {
            std::cout << "\nEnter information about prop bet to delete:\n";
            Prop newBet = createPropObject();
            Manager.deletePropBet(newBet);
        }
        else if (deleteOption == 3) {
            std::cout << "\nEnter information about spread bet to delete:\n";
            Spread newBet = createSpreadObject();
            Manager.deleteSpreadBet(newBet);
        }
        else if (deleteOption == 4) {
            std::cout << "\nEnter information about Over/Under bet to delete:\n";
            OverUnder newBet = createOverUnderObject();
            Manager.deleteOverUnderBet(newBet);
        }
        else if (deleteOption == 5) {
            std::cout << "\nEnter the team/player you wish to delete all bets for: ";
            std::string team;
            std::cin >> team;
            Manager.deleteBetsFor(team);
        }
        else if (deleteOption == 6) {
            std::cout << "\nEnter the team/player you wish to delete all bets against: ";
            std::string team;
            std::cin >> team;
            Manager.deleteBetsAgainst(team);
        }
        else if (deleteOption == 7) {
            std::cout << "\nWARNING: Are you sure you want to delete all bets? Enter 'y' for yes, anything else for no: ";
            char warning;
            std::cin >> warning;
            if (warning == 'y')
                Manager.deleteAllBets();
        }
        else if (deleteOption == 8)
            deleteBet = 'n';

        else {
            std::cout << "\nInvalid Input\n";
        }
    }
}

void updateDate(SportsBetManager &Manager) {
    int day, month, year;
    std::cout << "\nEnter today's month (1-12): ";
    std::cin >> month;
    std::cout << "\nEnter today's day (1-31): ";
    std::cin >> day;
    std::cout << "\nEnter the current year: ";
    std::cin >> year;
    Date newDate;
    newDate.setDate(month, day, year);
    Manager.deleteBetsBefore(newDate);

}

int main() {

    SportsBetManager Manager;

    bool flag = true;

    while (flag) {
        printMainMenu();
        int menuOption;
        std::cin >> menuOption;
        if (menuOption == 1) {
            if (Manager.isEmpty())
                std::cout<< "\nNo Bets Stored\n";
            else
                std::cout<<Manager.getAllBets();
        }

        else if (menuOption == 2)
            add(Manager);

        else if (menuOption == 3)
            deleteBets(Manager);

        else if (menuOption == 4)
            updateDate(Manager);

        else if (menuOption == 5) {
            std::cout << "What sport would you like to view bets of? ";
            std::string sport;
            std::cin >> sport;
            std::cout << Manager.getBetsOfSport(sport);
        }

        else if (menuOption == 6) {
            std::cout << "What team/player would you like to view bets of? ";
            std::string team;
            std::cin >> team;
            std::cout << Manager.getBetsFor(team);
        }

        else if (menuOption == 7) {
            std::cout << "What team/player would you like to view bets Against? ";
            std::string team;
            std::cin >> team;
            std::cout << Manager.getBetsAgainst(team);
        }

        else if (menuOption== 8)
            flag = false;

        else
            std::cout << "\nINVALID INPUT\n";
        }

}
