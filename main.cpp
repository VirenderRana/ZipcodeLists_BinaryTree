#include <string>
#include <fstream>
#include <iostream>
#include "Household.h"
#include "ZipCodeList.h"
#include "BSTree.h"
#include "List.h"
using namespace std;

Household::Household()
{
    lastName="";
    streetAddress="";
    stateInitials="";
    zipCode="";
    numOccupants=0;
}

void Household::setLastName(string LastName)
{
    this->lastName=LastName;
}
void Household::setStreeAddress(string streetAddress)
{
    this->streetAddress=streetAddress;
}
void Household::setStateInitials(string stateInitials)
{
    this->stateInitials=stateInitials;
}
void Household::setZipCode(string zipCode)
{
    this->zipCode=zipCode;
}
void Household::setnumOccupants(int numOccupants)
{
    this->numOccupants=numOccupants;
}
string Household::getLastName()
{
    return lastName;
}
string Household::getStreeAddress()
{
    return streetAddress;
}
string Household::getStateInitials()
{
    return stateInitials;
}
string Household::getZipCode()
{
    return zipCode;
}
int Household::getnumOccupants()
{
    return numOccupants;
}

bool Household:: operator <(Household rhsH)
{
    if(lastName<rhsH.lastName)
        return true;
    return false;
}
bool Household:: operator <=(Household rhsH)
{
    if(lastName<rhsH.lastName)
        return true;
    return false;
}
bool Household:: operator !=(Household rhsH)
{
    if(lastName<rhsH.lastName)
        return true;
    return false;
}
bool Household:: operator >(Household rhsH)
{
    if(lastName<rhsH.lastName)
        return true;
    return false;
}
bool Household:: operator >=(Household rhsH)
{
    if(lastName<rhsH.lastName)
        return true;
    return false;
}
bool Household:: operator ==(Household rhsH)
{
    if(lastName<rhsH.lastName)
        return true;
    return false;
}
string Household::toString() const
{
    stringstream s;
    string strA;
    s << lastName << "   " <<streetAddress <<"    "<<stateInitials<<"    "<<zipCode<<"      "<<numOccupants<<endl; 
    strA = s.str();
    return strA;
}
ostream & operator <<(ostream &out, const Household &p)
{
    out<<p.toString();
    return out;
}

int printMenu();
void InitializeTreeFromFile(string filename, BSTree<ZipCodeList<Household>> a)
{
    ifstream in;
    in.open(filename);
    
    int i=0;
    while(in){
    Household h1;
    string ln,ad,st,zc,no,ex;
    getline(in,ln);
    getline(in,ad);
    getline(in,ex);
    string sp = " ";
    int it=0;
    
    }
}
//void addHousehold(BSTree a);

//void deleteHousehold(BSTree a);

int main()
{

    BSTree<ZipCodeList<Household>> a;
    int selection;
    string fileName; 

    cout << "Programmed by Virender Singh\n\n";
    cout << "Enter the file to load the tree: ";
    getline(cin, fileName);

    InitializeTreeFromFile(fileName, a);
 	do
 	{
		selection = printMenu();
		switch (selection)
		{

		case 1:
			a.printTree();
			break;
		case 2:
		    //addHousehold(a);
		 	break;
		case 3:
		 	//deleteHousehold(a);
		 	break;
		case 4:
			break;
		default:
		    cout << "Invalid selection! Please Re-enter!\n";
		}
	}while (selection != 4);
	return 0; 

    return 0;
/*
    //Household Test Code
    List<Household> a;
    Household h1;
    h1.setLastName("Tetzner");
    h1.setnumOccupants(4);
    h1.setStateInitials("IL");
    h1.setStreeAddress("100 State Road");

    Household h2;
    h2.setLastName("Smith");
    h2.setnumOccupants(5);
    h2.setStateInitials("IL");
    h2.setStreeAddress("250 Castle Road");

    a.insert(h1);
    a.insert(h2);
    if(h1<h2)
        cout<<"h1 is less";
    else
    {
        cout<<"bef"<<endl;
    }
    a.printList();
    
    cout<<h1.toString();
    cout<<h2.toString();


    // List Test code
    List<int> trial;
    trial.insert(18);
    trial.insert(20);
    trial.insert(15);
    trial.insert(12);
    trial.insert(17);
    trial.insert(25);
    trial.insert(20);
    trial.insert(22);
    cout << "Initial" << endl;
    trial.printList();
    List<int>trial2(trial);
    trial2.insert(21);
    cout << "Test Copy Constructor" << endl;
    cout << "Trial" <<endl;
    trial.printList();
    cout << "Trial2" <<endl; 
    trial2.printList();
    cout << "Test Deletes" << endl;
    
    int x;
    if(trial.deleteAndPassBackListItem(17, x))
        cout << "Removed" << x << " from list" <<endl;
    else
    {
        cout << "17 not in list" <<endl;
    }
    trial.printList();
    if(trial.deleteAndPassBackListItem(4, x))
        cout << "Removed " << x << " from list" << endl;
    else
    {
        cout << "4 not in list" << endl;
    }
    trial.printList();
    if(trial.deleteFirstAndPassBackListItem(x))
    {
        cout << "Removed " << x << " from list" << endl;
    }
    else
    {
        cout << "list is empty." << endl;
    }
    
    
    trial.deleteListItem(25);
    trial.deleteListItem(12);
    trial.deleteListItem(22);
    trial.printList();*/

    /*BSTree<int> rt;
    rt.insert(12);
    rt.insert(67);
    rt.insert(34);
    rt.insert(10);
    rt.insert(5);
    rt.insert(7);
    rt.insert(38);
    rt.insert(11);
    rt.insert(69);
    BSTree<int> rt2;
    rt2 = rt;
    rt2.printTree();
    //cout<<"done";
    //rt.deleteTree();
    //rt.printTree();
    
    Household h1;
    h1.setLastName("Tetzner");
    h1.setnumOccupants(4);
    h1.setStateInitials("IL");
    h1.setStreeAddress("100 State Road");
    Household h2;
    h2.setLastName("Smith");
    h2.setnumOccupants(5);
    h2.setStateInitials("IL");
    h2.setStreeAddress("250 Castle Road");
    Household h3;
    h3.setLastName("Apple");
    h3.setnumOccupants(6);
    h3.setStateInitials("IL");
    h3.setStreeAddress("111 Stone Road");
    Household h4;
    h4.setLastName("Zebra");
    h4.setnumOccupants(7);
    h4.setStateInitials("IL");
    h4.setStreeAddress("54 Runner Road");
    Household h5;
    h5.setLastName("Show");
    h5.setnumOccupants(8);
    h5.setStateInitials("IL");
    h5.setStreeAddress("1458 Tree St");
    Household h6;
    h6.setLastName("Umbrella");
    h6.setnumOccupants(9);
    h6.setStateInitials("IL");
    h6.setStreeAddress("5 Elm St");
    cout<<"begin";
    ZipCodeList<Household> list1;
    list1.setZipCode("22222");
    list1.insertIntoList(h1);
    list1.insertIntoList(h2);
    list1.insertIntoList(h3);
    cout<<"1";

    ZipCodeList<Household> list2;
    list2.setZipCode("11111");
    list2.insertIntoList(h4);
    list2.insertIntoList(h5);
    list2.insertIntoList(h6);
    cout<<"2";

    ZipCodeList<Household> list3;
    list3.insertIntoList(h1);
    list3.insertIntoList(h2);
    list3.insertIntoList(h3);
    list3.setZipCode("33333");
    list3.insertIntoList(h4);
    list3.insertIntoList(h5);
    list3.insertIntoList(h6);

    ZipCodeList<Household> list4;
    list4.setZipCode("44444");
    list4.insertIntoList(h4);

    BSTree<ZipCodeList<Household>> tree1;
    cout<<"tree";
    tree1.insert(list1);
    tree1.insert(list2);
    tree1.insert(list3);
    cout<<"ts";
    cout << "Tree to begin" << endl;
    tree1.printTree();
    

    ZipCodeList<Household> tmp;
    if(tree1.deleteNodePassBackData(list2, tmp))
    {
        cout<<"Deleted:"<<endl;
        cout<<tmp;
    }
    else
    {
        cout<<"Could not delete: "<<endl;
        cout<<tmp;
    }
    if(tree1.deleteNodePassBackData(list4, tmp))
    {
        cout<<"Deleted:"<<endl;
        cout<<tmp;
    }
    else
    {
        cout<<"Could not delete: "<<endl;
        cout<<list4;
    }
    cout<<endl<<"After Deleting"<<endl;
    tree1.printTree();
    */
}

int printMenu()
{
    string schoice;
    cout << endl;
    cout << "1.\tPrint census by zipcode" << endl;
    cout << "2.\tAdd household to zipcode" << endl;
    cout << "3.\tDelete household from  zipcode" << endl;
    cout << "4.\tExit" << endl;
    cout << "Enter your selection: ";
    getline(cin,schoice);
    int choice = stoi(schoice);

    return choice;
    
}