#include <iostream>
#include "Footballer.h"

using namespace std;

namespace Ratings {
    Footballer::Footballer(string& club,
        const string& position,
        int jnum,
        const string& firstName,
        const string& lastName)
        : mClub(club), mPosition(position), mJnum(jnum),
        mFirstName(firstName), mLastName(lastName)
    {
    }

    void Footballer::extend(int extension, int salaryInc)
    {
        setContractLength(getContractLength() + extension);
        setWage(getWage() + salaryInc);
    }

    void Footballer::terminate()
    {
        mHired = false;
    }

    void Footballer::reduceWage(int reduction)
    {
        setWage(getWage() - reduction);
    }

    void Footballer::buy(int fee, string& myClub) {
        setTransferFee(fee);
        setClub(myClub);
        mHired = true;
    }

    void Footballer::sell(int fee, string& newClub)
    {
        setTransferFee(fee);
        setClub(newClub);
        mHired = false;
    }

    void Footballer::injure()
    {
        mInjured = true;
    }

    void Footballer::hire()
    {
        mHired = true;
    }

    void Footballer::score()
    {
        mGoals++;
    }

    void Footballer::assist()
    {
        mAssists++;
    }

    void Footballer::display()
    {
        cout << endl;
        cout << "Footballer: " << getFirstName() << " " << getLastName() << endl;
        cout << "Number: " << getFootballerNumber() << endl;
        cout << "----------------------------" << endl;
        if (isHired()) {
            cout << "Current Player for " << getClub() << endl;
        }
        else {
            cout << "Former Player, now plays for " << getClub() << endl;
        }
        cout << "Jersey Number: " << getJnum() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Currently earning: $" << getWage() << endl;
        cout << "Latest Transfer fee: $" << getTransferFee() << endl;
        cout << "Length of Contract: " << getContractLength() << endl;
        cout << "Goals Scored: " << mGoals << endl;
        cout << "Assists Made: " << mAssists << endl;
        cout << (isInjured() ? "Currently injured" : "Currently fit") << endl;
    }

    void Footballer::setFirstName(const string& firstName)
    {
        mFirstName = firstName;
    }

    const string& Footballer::getFirstName() const
    {
        return mFirstName;
    }

    void Footballer::setLastName(const string& lastName)
    {
        mLastName = lastName;
    }

    const string& Footballer::getLastName() const
    {
        return mLastName;
    }

    void Footballer::setFootballerNumber(int footballerNumber) {
        mFootballerNumber = footballerNumber;
    }

    int Footballer::getFootballerNumber() const
    {
        return mFootballerNumber;
    }

    void Footballer::setClub(string& club)
    {
        mClub = club;
    }

    string& Footballer::getClub()
    {
        return mClub;
    }

    void Footballer::setPosition(const string& position)
    {
        mPosition = position;
    }

    const string& Footballer::getPosition() const
    {
        return mPosition;
    }

    void Footballer::setJnum(int jnum)
    {
        mJnum = jnum;
    }

    int Footballer::getJnum() const
    {
        return mJnum;
    }

    void Footballer::setWage(int wage)
    {
        mWage = wage;
    }

    int Footballer::getWage() const
    {
        return mWage;
    }

    void Footballer::setTransferFee(int fee)
    {
        mTransferFee = fee;
    }

    int Footballer::getTransferFee() const
    {
        return mTransferFee;
    }

    void Footballer::setContractLength(int length)
    {
        mContractLength = length;
    }

    int Footballer::getContractLength() const
    {
        return mContractLength;
    }

    int Footballer::getGoals() const
    {
        return mGoals;
    }

    int Footballer::getAssists() const
    {
        return mAssists;
    }

    bool Footballer::isHired() const
    {
        return mHired;
    }

    bool Footballer::isInjured() const {
        return mInjured;
    }
}