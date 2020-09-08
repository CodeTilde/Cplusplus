#include <iostream> 
#include "listnode.h"
using namespace std;
template <typename sType>
Node<sType>::Node(const sType & data)
{
	setData(data);
	nextPtr = 0;
	
}

template <typename sType>
Node<sType>::Node()
{
	nextPtr = 0;	
}

template <typename sType>
void Node<sType>::setData( const sType & data)
{
	this->data = data;
}
template <typename sType>
sType Node<sType>::getData() const
{
	return data;
}
template <typename sType>
Node<sType>* Node<sType>:: getNextPtr() const
{
	return nextPtr;
}
template <typename sType>
void Node<sType>::setNextPtr( Node<sType> * nodePtr)
{
	this->nextPtr = nodePtr;
}
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
List<sType>::List(): firstPtr(0), lastPtr(0)
{
	
}
template <typename sType>
List<sType>::~List()
{
	
	if ( isEmpty())
	{
		Node <sType> *currentPtr = firstPtr;
		Node <sType> *tempPtr;
		//free memory
		while ( currentPtr != 0)
		{
			tempPtr = currentPtr;
			cout<<tempPtr->getData()   <<'\n';
			currentPtr = currentPtr->getNextPtr();
			delete tempPtr;
		}
		//
		
	}

}
template <typename sType>
void List <sType>::insertAtFront ()
{
	sType data;
	
	
	
	cout<<"Enter Data\n";
	cin>>data;
	Node<sType>* newNode = createNewNode(data);
	if ( isEmpty())
	{
		firstPtr= lastPtr= newNode;
		

	}
	else
	{
		newNode->setNextPtr(firstPtr);
		firstPtr = newNode;
	}
}
template <typename sType>
void List<sType>::insertAtBack()
{
	sType data;
	cout<<"Enter Data\n";
	cin>>data;
	Node<sType>* newNode = createNewNode(data);
	if ( isEmpty())
	{
		firstPtr= lastPtr= newNode;
		

	}
	else
	{
		lastPtr-> setNextPtr(newNode);
		lastPtr = newNode;
	}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Insert at pos
template <typename sType>
int List<sType>::insertAtPos()
{
	
	Node<sType> *currentPtr;
	Node<sType>  *tempPtr;
	sType data;
	cout<<"Enter Data\n";
	cin>> data;
	Node<sType>* newNode = createNewNode(data);
	int pos;
	int i = 0;
	cout<<"What is the node position you want to insert at?\n";
	cin>> pos;
	if ( pos <0 ) 
	{
		cout<< "Out of index\n";
		return -1;
		
	}
	if ( pos == 0)
	{
		if ( firstPtr == 0)
		{
			firstPtr =  lastPtr = newNode;
			newNode->setNextPtr(0);
		}
			
		else
		newNode->setNextPtr (firstPtr);
		firstPtr = newNode;
	}
	else
	{
		currentPtr = firstPtr;
		while ( i < pos && currentPtr !=0 )
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->getNextPtr();
				i++;
		}
		if (i < pos && currentPtr == 0)
		{
			cout<<"out of index\n";
			return -1;
		}
		tempPtr->setNextPtr(newNode);
		newNode->setNextPtr(currentPtr);
		
		if (i == pos && currentPtr == 0)
		{
			lastPtr = newNode;
		}
		
	
	}
	return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
void List<sType>::removeFromFront()
{
	Node<sType> *currentPtr =firstPtr;;
	if (isEmpty())
	{
		cout<<"The list is empty \n"<<endl;
	}
	else
	{
		if (firstPtr == lastPtr )
			firstPtr = lastPtr = 0;
		else
			firstPtr = firstPtr->getNextPtr();
		}

		delete currentPtr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
void List<sType>::removeFromBack()
{


	Node<sType> *currentPtr =firstPtr;
	Node<sType> *temp;
	if (isEmpty())
	{
		cout<<"The list is empty \n"<<endl;
	}
	else
	{
		if (firstPtr == lastPtr )
			firstPtr = lastPtr = 0;
		else
		{
			//trversing the link list
			while ( currentPtr != lastPtr)
			{
				temp = currentPtr;
				currentPtr = currentPtr->getNextPtr();
			}

			lastPtr = temp;
			temp->setNextPtr(0);
		}
	}
		delete currentPtr;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
int List<sType>::removeFromPos()
{
	if ( isEmpty() )
	{
			cout<<"The list is empty \n";
			return -1;
	}
	int pos;
	int value =0;
	cout<<"Enter the postion of the node you want to remove\n";
	cin>>pos;
	Node<sType>* currentPtr = firstPtr;
	Node<sType> *tempPtr = firstPtr; 
	
	
	if ( pos < 0  )
	{
		cout<<"Invalid node position\n";
		return -1;
	}
	else
	
		
	{
		if ( pos ==0 )
			if (firstPtr == lastPtr)
				firstPtr = lastPtr =0;
			else
			{
				firstPtr = firstPtr->getNextPtr();
				
			}
		else
			
		{
			
			while ( currentPtr !=0   &&   value < pos)
			{
					value++;
					tempPtr = currentPtr;
					currentPtr = currentPtr->getNextPtr();
			}
			
			if ( currentPtr == 0 && value <= pos )
			{
				cout<<"Invalid node position\n";
				return -1;
			}
			tempPtr->setNextPtr(currentPtr->getNextPtr());
			if (currentPtr->getNextPtr() == 0 )
				lastPtr = tempPtr;


			
		}
		delete currentPtr;
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////

template <typename sType>
void List<sType>::sort()
{
	Node<sType>* currentPtr = firstPtr;
	Node<sType>* tempPtr;
	int value;
	Node<sType>* ptr;
	/////////////////////////////////////////////////////////////////////////
	

	////////////////////////////////////////////////////////////////////////

	if (firstPtr == 0)
		cout<<"The list is empty \n";
	else if ( firstPtr != lastPtr)
		
		while ( currentPtr->getNextPtr () != 0)
		{
			
			tempPtr = currentPtr->getNextPtr();
			
			while ( tempPtr !=0 )
			{
				
				if ( currentPtr->getData() > tempPtr->getData())
				{
					value = currentPtr->getData();
					currentPtr->setData (tempPtr->getData());
					tempPtr->setData(value);
				}
				tempPtr = tempPtr->getNextPtr();
			}
				
			currentPtr = currentPtr->getNextPtr();
			
				
		}


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
void List<sType>::reverse()
{
	Node <sType>* currentPtr = firstPtr;
	Node<sType> * tempPtr;
	int value;
	Node<sType>* ptr;
	if (firstPtr != lastPtr )
	{
		lastPtr = firstPtr;
		tempPtr = currentPtr->getNextPtr();
		currentPtr->setNextPtr(0);
		ptr = currentPtr;
		currentPtr = tempPtr;
		
		while ( currentPtr != 0)
		{	
			tempPtr = currentPtr->getNextPtr();
			currentPtr->setNextPtr(ptr);
			ptr = currentPtr;
			currentPtr = tempPtr;
			
		}

		firstPtr = ptr;
	}
		
}
template <typename sType>
int List<sType>::update()
{
	if (isEmpty())
	{
		cout<<"The list is empty\n";
		return -1;
	}
	int value = -1;
	int pos;
	sType nodeValue;
	cout<<"Enter the node position that is to be updated \n";
	cin>>pos;
	cout<<"Enetr the new node value\n";
	cin>>nodeValue;
	Node<sType> *currentPtr = firstPtr;
	Node<sType>* tempPtr;
	if  ( pos < 0)
	{
		cout<<"Invalid node position"<<endl;
		return -1;
	}
	
	else
		while ( currentPtr !=0 && value < pos) 
		{
			value ++;
			tempPtr = currentPtr;
			currentPtr = currentPtr->getNextPtr();
		}
		if ( currentPtr == 0 && value < pos )
		{
			cout<<"Invalid node position\n";
			return -1;
		}
		else
			tempPtr->setData(nodeValue);


}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
void List<sType>:: display() const 
{
	Node<sType> * currentPtr = firstPtr;
		cout<< "Displaying list \n";
		while ( currentPtr != 0)
		{
		
			cout<<currentPtr->getData()<<"\t"; 
			currentPtr = currentPtr->getNextPtr();

		}
		cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
bool List<sType>::isEmpty() const
{ if 
	(firstPtr == 0 )
		return true;
	else
		return false;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
int List<sType>::size() const
{
	int len = 0;
	Node<sType> * currentPtr = firstPtr;
	while ( currentPtr != 0)
	{
		
		len++; 
		currentPtr = currentPtr->getNextPtr();

	}
	return len;
		
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename sType>
Node<sType>*List<sType>::getFirstPtr() const
{
	return firstPtr;
}
//////////////////////////////////////////////////////////////////////////////
template <typename sType>
Node<sType>*List<sType>::getLastPtr() const
{
	return lastPtr;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename sType>
Node<sType>*List<sType>::createNewNode(const sType & data)
{
	return new Node<sType> (data);
}


