#include <iostream> 
#include "listnode.h"
using namespace std;
template <typename nType>
Node<nType>::Node(const nType & data)
{
	setData(data);
	nextPtr = 0;
	
}

template <typename nType>
Node<nType>::Node()
{
	nextPtr = 0;	
}

template <typename nType>
void Node<nType>::setData( const nType & data)
{
	this->data = data;
}
template <typename nType>
nType Node<nType>::getData() const
{
	return data;
}
template <typename nType>
Node<nType>* Node<nType>:: getNextPtr() const
{
	return nextPtr;
}
template <typename nType>
void Node<nType>::setNextPtr( Node<nType> * nodePtr)
{
	this->nextPtr = nodePtr;
}
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
template <typename nType>
List<nType>::List(): firstPtr(0), lastPtr(0)
{
	
}
template <typename nType>
List<nType>::~List()
{
	
	if ( isEmpty())
	{
		Node <nType> *currentPtr = firstPtr;
		Node <nType> *tempPtr;
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
template <typename nType>
void List <nType>::insertAtBack ()
{
	nType data;
	
	
	
	cout<<"Enter Data\n";
	cin>>data;
	Node<nType>* newNode = createNewNode(data);
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
template <typename nType>
void List<nType>::insertAtFront()
{
	nType data;
	cout<<"Enter Data\n";
	cin>>data;
	Node<nType>* newNode = createNewNode(data);
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
template <typename nType>
int List<nType>::insertAtPos()
{
	
	Node<nType> *currentPtr;
	Node<nType>  *tempPtr;
	nType data;
	cout<<"Enter Data\n";
	cin>> data;
	Node<nType>* newNode = createNewNode(data);
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
template <typename nType>
void List<nType>::removeFromBack()
{
	Node<nType> *currentPtr =firstPtr;;
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
template <typename nType>
void List<nType>::removeFromFront()
{


	Node<nType> *currentPtr =firstPtr;
	Node<nType> *temp;
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
template <typename nType>
int List<nType>::removeFromPos()
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
	Node<nType>* currentPtr = firstPtr;
	Node<nType> *tempPtr = firstPtr; 
	
	
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

template <typename nType>
void List<nType>::sort()
{
	Node<nType>* currentPtr = firstPtr;
	Node<nType>* tempPtr;
	int value;
	Node<nType>* ptr;
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
template <typename nType>
void List<nType>::reverse()
{
	Node <nType>* currentPtr = firstPtr;
	Node<nType> * tempPtr;
	int value;
	Node<nType>* ptr;
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
template <typename nType>
int List<nType>::update()
{
	if (isEmpty())
	{
		cout<<"The list is empty\n";
		return -1;
	}
	int value = -1;
	int pos;
	nType nodeValue;
	cout<<"Enter the node position that is to be updated \n";
	cin>>pos;
	cout<<"Enetr the new node value\n";
	cin>>nodeValue;
	Node<nType> *currentPtr = firstPtr;
	Node<nType>* tempPtr;
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
template <typename nType>
void List<nType>:: display() const 
{
	Node<nType> * currentPtr = firstPtr;
		cout<< "Displaying list \n";
		while ( currentPtr != 0)
		{
		
			cout<<currentPtr->getData()<<"\t"; 
			currentPtr = currentPtr->getNextPtr();

		}
		cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename nType>
bool List<nType>::isEmpty() const
{ if 
	(firstPtr == 0 )
		return true;
	else
		return false;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename nType>
int List<nType>::size() const
{
	int len = 0;
	Node<nType> * currentPtr = firstPtr;
	while ( currentPtr != 0)
	{
		
		len++; 
		currentPtr = currentPtr->getNextPtr();

	}
	return len;
		
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename nType>
Node<nType>*List<nType>::getFirstPtr() const
{
	return firstPtr;
}
//////////////////////////////////////////////////////////////////////////////
template <typename nType>
Node<nType>*List<nType>::getLastPtr() const
{
	return lastPtr;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename nType>
Node<nType>*List<nType>::createNewNode(const nType & data)
{
	return new Node<nType> (data);
}




