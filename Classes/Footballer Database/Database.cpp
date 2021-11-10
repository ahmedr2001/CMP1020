#include <bits/stdc++.h>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Ratings {
    Footballer& Database::addFootballer(std::string& club,
        const std::string& position,
        int jnum,
        const std::string& firstName,
        const std::string& lastName)
    {
        Footballer Footballer(club, position, jnum, firstName, lastName);
        Footballer.hire();
        Footballer.setFootballerNumber(mNextFootballerNumber++);
        mFootballers.push_back(Footballer);
        return mFootballers[mFootballers.size() - 1];
    }

    Footballer& Database::getFootballer(int footballerNumber)
    {
        for (auto& footballer : mFootballers) {
            if (footballer.getFootballerNumber() == footballerNumber)
                return footballer;
        }
        throw logic_error("No footballers found.");
    }

    Footballer& Database::getFootballer(const std::string& firstName,
        const std::string& lastName)
    {
        for (auto& footballer : mFootballers) {
            if (footballer.getFirstName() == firstName and footballer.getLastName() == lastName) {
                return footballer;
            }
        }
        throw logic_error("No footballers found.");
    }

    void Database::displayAll()
    {
        for (auto& footballer : mFootballers) {
            footballer.display();
        }
    }

    void Database::displayCurrent()
    {
        for (auto& footballer : mFootballers) {
            if (footballer.isHired()) {
                footballer.display();
            }
        }
    }

    void Database::displayFormer()
    {
        for (auto& footballer : mFootballers) {
            if (!footballer.isHired()) {
                footballer.display();
            }
        }
    }

    void Database::displayByPosition(const std::string& position) {
        for (auto& footballer : mFootballers) {
            if (footballer.getPosition() == position) {
                footballer.display();
            }
        }
    }

    void Database::displayByClub(std::string& club)
    {
        for (auto& footballer : mFootballers) {
            if (footballer.getClub() == club) {
                footballer.display();
            }
        }
    }
}
