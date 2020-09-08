#include <iostream>
#include <string>
#include "listnode.h"
#include "listnode.cpp"
#include "stack.h"
using namespace std;
void menuinstruction ()
{
	cout <<" ENTER 1 for PUSH \n "<<endl;
	cout <<" ENTER 2 for POP \n "<<endl;
	cout <<" ENTER 3 for SIZE \n "<<endl;
	cout <<" ENTER 4 for STACK TOP \n "<<endl;
	cout <<" Enter 5 for DISPLAY\n"<<endl;
	cout <<" Enter 6 for End\n"<<endl;

};
//////////////////////////////
template <typename sType>
void stackFunction (Stack<sType> &stack1, const string &typeName)
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
			stack1.push();
			break;
		case 2:
			stack1.pop();
			break;
		case 3:
			cout<< "The stack size is " <<stack1.stackSize()<<"\n";
			break;
		case 4:
			if ( stack1.stackTop() == 0 )
				cout<< "The stack is empty\n";
			else
				cout<< "The stack top element is "<< stack1.stackTop()->getData() <<"\n";			
			break;
		case 5:
			stack1.stackDisplay();
			break;		
		}
	}
	while ( choise != 6);

};

int main()
{
	Stack <int> integerStack1;
	Stack <int> integerStack2;
	cout<<"STACK MANUPULATION FOR INTEGER STACK 1 \n";
	stackFunction (integerStack1, "INTEGER");
	cout<<"STACK MANUPULATION FOR INTEGER STACK 2 \n";
	stackFunction (integerStack2, "INTEGER");
	cout<<"STACK INTEGER1 is \n";
	integerStack1.stackDisplay();
	cout<<"STACK INTEGER2 is \n";
	integerStack2.stackDisplay();
	cout<<"AFTER STACK SWAP \n\n";
	if  ( integerStack1.stackSwap(integerStack2))
	{
		cout<<"STACK INTEGER1 is \n";
		integerStack1.stackDisplay();
		cout<<"STACK INTEGER2 is \n";
		integerStack2.stackDisplay();
	}
	else
		cout<<"THE STACK ARE NOT AT THE SAME LENGTH\n";


	/////////////////////////////////////////////////////////////////
	Stack <double> doubleStack;
	stackFunction (doubleStack, "DOUBLE");	
	return 0;
}
