#pragma once
#include <string>

namespace Ratings {
    const int kDefaultStartingSalary = 1000000;
    const int kDefaultContractLength = 1;
    class Footballer
    {
    public:
        Footballer() = default;
        Footballer(std::string& club,
            const std::string& position,
            int jnum,
            const std::string& firstName,
            const std::string& lastName);

        void extend(int extension, int salaryInc);
        void terminate();
        void reduceWage(int salaryDec);
        void buy(int fee, std::string& myClub);
        void sell(int fee, std::string& newClub);
        void injure();
        void hire();
        void score();
        void assist();
        void display();

        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;

        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;

        void setFootballerNumber(int footballerNumber);
        int getFootballerNumber() const;

        void setClub(std::string& club);
        std::string& getClub();

        void setJnum(int jnum);
        int getJnum() const;

        void setPosition(const std::string& position);
        const std::string& getPosition() const;

        void setWage(int wage);
        int getWage() const;

        void setTransferFee(int fee);
        int getTransferFee() const;

        void setContractLength(int length);
        int getContractLength() const;

        int getGoals() const;
        int getAssists() const;

        bool isHired() const;
        bool isInjured() const;

    private:
        std::string mFirstName;
        std::string mLastName;
        std::string mClub;
        std::string mPosition;
        int mFootballerNumber = -1;
        int mContractLength = kDefaultContractLength;
        int mTransferFee = 0;
        int mGoals = 0;
        int mAssists = 0;
        int mJnum;
        int mWage = kDefaultStartingSalary;
        bool mHired = true;
        bool mInjured = false;
    };
}