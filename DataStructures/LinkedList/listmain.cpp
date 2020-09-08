//Link list implementation using template
#include <iostream>
#include <string>
#include "listnode.h"
#include "listnode.cpp"
using namespace std;
void menuinstruction ()
{
	cout <<" ENTER 1 for INSERT at FRONT\n "<<endl;
	cout <<" ENTER 2 for INSERT at BACK\n "<<endl;
	cout <<" ENTER 3 for INSERT at POS\n "<<endl;
	cout <<" ENTER 4 for REMOVE from FRONT \n "<<endl;
	cout <<" ENTER 5 for REMOVE from BACK \n "<<endl;
	cout <<" ENTER 6 for REMOVE from POS \n "<<endl;
	cout <<" ENTER 7 for SORT \n"<<endl;
	cout <<" ENTER 8 for REVERSE \n"<<endl;
	cout <<" ENTER 9 for UPDATE \n"<<endl;
	cout <<" Enter 10 for SIZE\n"<<endl;
	cout <<" Enter 11 for DISPLAY\n"<<endl;
	cout <<" Enter 12 for End\n"<<endl;

};
//////////////////////////////
template <typename nType>
void listFunction (List<nType> &mylist, const string &typeName)
{
	int choise;
	cout<< "The LIST IS of TYPE "<<typeName<<"\n";
	do 
	{
		menuinstruction();
		cout << " ENTER the CHOICE\n";
		cin>>choise;
		switch ( choise )
		{
		case 1:
			mylist.insertAtFront();
			break;
		case 2:
			mylist.insertAtBack();
			break;
		case 3:
			mylist.insertAtPos();
			break;
		case 4:
			mylist.removeFromFront();
			break;
		case 5:
			mylist.removeFromBack();
			break;
		case 6:
			mylist.removeFromPos();
			break;
		case 7: 
			mylist.sort();
			break;
		case 8:
			mylist.reverse();
			break;
		case 9:
			mylist.update();
			break;
		case 10:
			cout<<"The size is "<< mylist.size() <<"\n"; 
			break;
		case 11:
			mylist.display();
			break;
		}
	}
	while ( choise !=12);

};

int main()
{
	List <int> integerList;
	listFunction (integerList, "integer");
	/////////////////////////////////////////////////////////////////
	List <double> doubleList;
	listFunction (doubleList, "double");	
	return 0;
}
