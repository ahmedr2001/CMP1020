#pragma once
#include <bits/stdc++.h>
#include "Footballer.h"

namespace Ratings {
    const int kFirstPlayerNum = 1;

    class Database
    {
    public:
        Footballer& addFootballer(std::string& club, 
            const std::string& position, 
            int jnum, 
            const std::string& firstName, 
            const std::string& lastName);
        Footballer& getFootballer(int footballerNumber);
            
        Footballer& getFootballer(const std::string& firstName, 
            const std::string& lastName);

        void displayAll();
        void displayCurrent();
        void displayFormer();
        void displayByPosition(const std::string& position);
        void displayByClub(std::string& club);

    private:
        std::vector<Footballer> mFootballers;
        int mNextFootballerNumber = kFirstPlayerNum;
    };
}