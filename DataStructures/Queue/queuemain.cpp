#include <iostream>
#include <string>
#include "listnode.h"
#include "listnode.cpp"
#include "queue.h"
using namespace std;
void menuinstruction ()
{
	cout <<" ENTER 1 for PUSH BACK\n "<<endl;
	cout <<" ENTER 2 for POP FRONT\n "<<endl;
	cout <<" ENTER 3 for SIZE \n "<<endl;
	cout <<" ENTER 4 for QUEUE TOP \n "<<endl;
	cout <<" Enter 5 for DISPLAY\n"<<endl;
	cout <<" Enter 6 for END\n"<<endl;

};
//////////////////////////////
template <typename qType>
void queFunction (Que<qType> &que, const string &typeName)
{
	int choise;
	cout<< "The QUEUE IS of TYPE "<<typeName<<"\n";
	do 
	{
		menuinstruction();
		cout << " ENTER the CHOICE\n";
		cin>>choise;
		switch ( choise )
		{
		case 1:
			que.push_Back();
			break;
		case 2:
			que.pop_Front();
			break;
		case 3:
			cout<< "The queue size is " <<que.queSize()<<"\n";
			break;
		case 4:
			if (que.top()==0)
				cout << "The queue is empty\n";
			else
				cout <<"The queue top element is "<< que.top()->getData() <<"\n";
			break;
		case 5:
			que.queDisplay();
			break;		
		}
	}
	while ( choise != 6);

};

int main()
{
	Que <int> integerQue;
	queFunction (integerQue, "INTEGER");
	

	/////////////////////////////////////////////////////////////////
	Que <double> doubleQue;
	queFunction (doubleQue, "DOUBLE");	
	return 0;
}
