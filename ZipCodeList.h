#ifndef ZIPCODELIST_H
#define ZIPCODELIST_H
#include <string>
#include <iostream>
#include "List.h"
using namespace std;

template <class DataType>
class ZipCodeList
{
    private:
    string zipCode;

    public:
    List<DataType> list;

    void insertIntoList(DataType a)
    {
        list.insert(a);
    }
    bool deleteFromList(DataType a)
    {
        list.deleteListItem(a);
    }
    bool deleteFromListPassBackItem(DataType a, DataType &tm)
    {
        list.deleteAndPassBackListItem(a, &tm);
    }
    void setZipCode(string zip)
    {
        zipCode = zip;
    }
    string getZipCode()
    {
        return zipCode;
    }
    void printList()
    {
        list.printList();
    }
    bool operator <(ZipCodeList rhsH)
    {
        if(zipCode < rhsH.zipCode)
            return true;
        else
        {
            return false;
        }
        
    }
    bool operator <=(ZipCodeList rhsH)
    {
        if(zipCode <= rhsH.zipCode)
            return true;
        else
        {
            return false;
        }
    }
    bool operator >(ZipCodeList rhsH)
    {
        if(zipCode > rhsH.zipCode)
            return true;
        else
        {
            return false;
        }
    }
    bool operator ==(ZipCodeList rhsH)
    {
        if(zipCode == rhsH.zipCode)
            return true;
        else
        {
            return false;
        }
    }
    bool operator >=(ZipCodeList rhsH)
    {
        if(zipCode >= rhsH.zipCode)
            return true;
        else
        {
            return false;
        }
    }
    bool operator !=(ZipCodeList rhsH)
    {
        if(zipCode != rhsH.zipCode)
            return true;
        else
        {
            return false;
        }
    }
};
template<class DataType>
ostream & operator <<(ostream &out, ZipCodeList<DataType>& c)
{
    out<<"ZipCode: "<<c.getZipCode()<<endl;
    c.printList();
}

#endif