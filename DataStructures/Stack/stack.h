#ifndef STACK_H
#define STACK_H
#include "listnode.h"
//using namespace std;
template <typename sType>
class Stack:private List <sType>
{
public:
	void push ()
	{
		 insertAtBack();

	}
	void pop  ()
	{
		 removeFromBack();
	}
	bool isStackEmpty()

	{
		return isEmpty()
	}
	int stackSize()
	{
		return size(); 
	}
	void stackDisplay()
	{
		display();
	}
	bool stackSwap(Stack<sType>& stackVar )
	{
		int i = 0;
		sType data;
		Node<sType>* stack1Ptr;
		Node<sType>* stack2Ptr ;
		stack1Ptr = this->getFirstPtr();
		stack2Ptr= stackVar.getFirstPtr();
		

		if ( stackVar.size() != this->size())
			return false;
		else
		{
			for ( int j =1; j <= this->stackSize(); j++)
			{
				data= stack1Ptr->getData();
				stack1Ptr->setData(stack2Ptr->getData());
				stack2Ptr->setData(data);
				stack1Ptr = stack1Ptr->getNextPtr();
				stack2Ptr = stack2Ptr->getNextPtr();



			}


		}
		return true;
	}
	
	Node<sType>* stackTop()
	{
		Node<sType>* topPtr = getLastPtr(); 
		return topPtr;
	}
	
};
#endif