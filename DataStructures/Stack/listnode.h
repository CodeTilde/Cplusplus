#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream> 
using namespace std;

template <typename sType>
class Node
{
public:
	//friend class List;
	Node(const sType &) ;
	Node();
	void setData(const sType &);
	sType getData() const; //return data in node //How about pointer or reference
	void setNextPtr( Node <sType> *);
	Node <sType> * getNextPtr () const;
private:
    Node <sType> * nextPtr;
    sType data;
};

template <typename sType>
class List
{
public:
	List ();
	~List ();
	void insertAtFront();
	void insertAtBack();
	int insertAtPos();
	void removeFromFront();
	void removeFromBack();
	int removeFromPos();
	void sort();
    int update();
    void reverse();
	void display() const;
	bool isEmpty ()const;
	int size() const;
	Node<sType>* getFirstPtr() const;
	Node<sType>* getLastPtr() const;
private:
	Node <sType> *firstPtr; //pointer to first node
	Node <sType> *lastPtr; //pointer to last node
	Node <sType> *createNewNode(const sType &);

};
#endif

