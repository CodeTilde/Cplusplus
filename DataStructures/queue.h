#ifndef QUEUE_H
#define QUEUE_H
#include <iostream> 
#include "listnode.h"
using namespace std;
template <typename qType>
class Que:private List <qType>
{
public:
	void pop_Front(){
		removeFromFront(); 
	}
	void push_Back(){
		insertAtBack();
	}
	Node<qType>* back(){
		return getFirstPtr();
		
	}
	Node <qType>* top(){
		return getLastPtr();
	}
	int queSize()
	{
		return size();

	}
	bool queEmpty()
	{
		return isEmpty();
	}
	void queDisplay()
	{
		display();
	}
	
};
#endif
