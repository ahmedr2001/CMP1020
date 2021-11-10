#include <bits/stdc++.h>
#include "Database.h"

using namespace std;
using namespace Ratings;

int displayMenu();
void doHire(Database& db);
void doTerminate(Database& db);
void doExtend(Database& db);
void doReduceWage(Database& db);
void doBuy(Database& db, string& myClub);
void doSell(Database& db);
void doInjure(Database& db);
void doScore(Database& db);
void doAssist(Database& db);

int main()
{
    Database footballerDB;
    string myClub;

    cout << "Enter your club: ";
    cin >> myClub;
    string position;
    string club;
    bool done = false;
    while (!done) {
        int query = displayMenu();
        switch (query) {
        case 0:
            done = true;
            break;
        case 1:
            doHire(footballerDB);
            break;
        case 2:
            doTerminate(footballerDB);
            break;
        case 3:
            doExtend(footballerDB);
            break;
        case 4:
            doReduceWage(footballerDB);
            break;
        case 5:
            doBuy(footballerDB, myClub);
            break;
        case 6:
            doSell(footballerDB);
            break;
        case 7:
            doInjure(footballerDB);
            break;
        case 8:
            doScore(footballerDB);
            break;
        case 9:
            doAssist(footballerDB);
            break;
        case 10:
            footballerDB.displayAll();
            break;
        case 11:
            footballerDB.displayCurrent();
            break;
        case 12:
            footballerDB.displayFormer();
            break;
        case 13: 
            cout << "Enter position: ";
            cin >> position;
            footballerDB.displayByPosition(position);
            break;
        case 14:
            cout << "Enter club: ";
            cin >> club;
            footballerDB.displayByClub(club);
            break;
        default:
            cerr << "Unknown command." << endl;
            break;
        }
    }
    return 0;
}

int displayMenu()
{
    int query;
    cout << endl;
    cout << "Footballer Database" << endl;
    cout << "-------------------" << endl;
    cout << "1) Hire a new footballer" << endl;
    cout << "2) Terminate a footballer's contract" << endl;
    cout << "3) Extend a footballer's contract" << endl;
    cout << "4) Reduce a footballer's wages" << endl;
    cout << "5) Buy a player" << endl;
    cout << "6) Sell a player" << endl;
    cout << "7) Injure a player" << endl;
    cout << "8) Score a goal" << endl;
    cout << "9) Make an assist" << endl;
    cout << "10) Display all players" << endl;
    cout << "11) Display current players" << endl;
    cout << "12) Display former players" << endl;
    cout << "13) Display by position" << endl;
    cout << "14) Display by club" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    cin >> query;
    return query;
}

void doHire(Database& db)
{
    string club;
    string position;
    string firstName;
    string lastName;
    int jnum;

    cout << "First Name? ";
    cin >> firstName;

    cout << "Last Name? ";
    cin >> lastName;
    cout << "Jersey Number? ";
    cin >> jnum;

    cout << "Position? ";
    cin >> position;

    cout << "Club? ";
    cin >> club;

    db.addFootballer(club, position, jnum, firstName, lastName);
}

void doTerminate(Database& db)
{
    int footballerNumber;

    cout << "Footabller Number? ";
    cin >> footballerNumber;

    try {
        Footballer& player = db.getFootballer(footballerNumber);
        player.terminate();
        cout << "Footballer " <<
            player.getFirstName() << " " <<
            player.getLastName() << " " << " terminated." << endl;
    }
    catch (const std::logic_error& exception) {
        cerr << "Unable to terminate footballer: " << exception.what() << endl;
    }
}

void doExtend(Database& db)
{
    int footballerNumber;
    int extension;
    int raiseAmount;

    cout << "Footballer Number? ";
    cin >> footballerNumber;

    cout << "Added years? ";
    cin >> extension;

    cout << "Increase in Salary? ";
    cin >> raiseAmount;

    try {
        Footballer& player = db.getFootballer(footballerNumber);
        player.extend(extension, raiseAmount);
    }
    catch (const std::logic_error& exception) {
        cerr << "Unable to extend player: " << exception.what() << endl;
    }
}

void doReduceWage(Database& db)
{
    int footballerNumber;
    int reduction;

    cout << "Footballer Number? ";
    cin >> footballerNumber;

    cout << "Reduction in Salary? ";
    cin >> reduction;

    try {
        Footballer& player = db.getFootballer(footballerNumber);
        player.reduceWage(reduction);
    }
    catch (const std::logic_error& exception) {
        cerr << "Unable to reduce player's wages: " << exception.what() << endl;
    }
}

void doBuy(Database& db, string& myClub)
{
    int footballerNumber;
    int fee;

    cout << "Footballer Number? ";
    cin >> footballerNumber;

    cout << "Fee? ";
    cin >> fee;

    try {
        Footballer& player = db.getFootballer(footballerNumber);
        string& oldClub = player.getClub();
        player.buy(fee, myClub);
        cout << "Footballer " << player.getFirstName() << " "
            << player.getLastName() << " bought from "
            << oldClub << " for $" << fee << endl;
    }
    catch (const std::logic_error& exception) {
        cerr << "Unable to buy: " << exception.what() << endl;
    }
}

void doSell(Database& db)
{
    int footballerNumber;
    int fee;
    string newClub;

    cout << "Footballer Number? ";
    cin >> footballerNumber;

    cout << "Fee? ";
    cin >> fee;

    cout << "Destination Club? ";
    cin >> newClub;

    try {
        Footballer& player = db.getFootballer(footballerNumber);
        player.sell(fee, newClub);
        cout << "Footballer " << player.getFirstName()
            << " " << player.getLastName()
            << " sold to " << newClub
            << " for $" << fee << endl;
    }
    catch (const std::logic_error& exception) {
        cerr << "Unable to sell player: " << exception.what() << endl;
    }
}

void doInjure(Database& db)
{
    int footballerNumber;

    cout << "Footballer Number? ";
    cin >> footballerNumber;

    try {
        Footballer& player = db.getFootballer(footballerNumber);
        player.injure();
        cout << "Player " << player.getFirstName()
            << " " << player.getLastName()
            << " picked up an injury." << endl;
    }
    catch (const std::logic_error& exception) {
        cerr << "Unable to injure player: " << exception.what() << endl;
    }
}

void doScore(Database& db)
{
    int footballerNumber;

    cout << "Footballer Number? ";
    cin >> footballerNumber;

    try {
        Footballer& player = db.getFootballer(footballerNumber);
        player.score();
        cout << player.getFirstName() << " "
            << player.getLastName()
            << " scores!" << endl
            << "His goal tally now is: " << player.getGoals()
            << endl;
    }
    catch (const std::logic_error& exception) {
        cerr << "Unable to score: " << exception.what() << endl;
    }
}

void doAssist(Database& db)
{
    int footballerNumber;

    cout << "Footballer Number? ";
    cin >> footballerNumber;

    try {
        Footballer& player = db.getFootballer(footballerNumber);
        player.assist();
        cout << player.getFirstName() << " "
            << player.getLastName()
            << " assists!" << endl
            << "His assist tally now is: " << player.getAssists()
            << endl;
    }
    catch (const std::logic_error& exception) {
        cerr << "Unable to assist: " << exception.what() << endl;
    }
}

