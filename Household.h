#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H
#include<string>
#include<iostream>
using namespace std;

class Household
{
    private:
        string lastName;
        string streetAddress;
        string stateInitials;
        string zipCode;
        int numOccupants;
    public:
        Household();
        void setLastName(string LastName);
        void setStreeAddress(string streetAddress);
        void setStateInitials(string stateInitials);
        void setZipCode(string zipCode);
        void setnumOccupants(int numOccupants);

        string getLastName();
        string getStreeAddress();
        string getStateInitials();
        string getZipCode();
        int getnumOccupants();

        bool operator <(Household rhsH);
        bool operator <=(Household rhsH);
        bool operator !=(Household rhsH);
        bool operator >(Household rhsH);
        bool operator >=(Household rhsH);
        bool operator ==(Household rhsH);

        string toString() const;
};

ostream & operator <<(ostream &out, const Household &p);

#endif