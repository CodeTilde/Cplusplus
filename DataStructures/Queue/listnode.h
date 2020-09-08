#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream> 
using namespace std;

template <typename nType>
class Node
{
public:
	//friend class List;
	Node(const nType &) ;
	Node();
	void setData(const nType &);
	nType getData() const; //return data in node //How about pointer or reference
	void setNextPtr( Node <nType> *);
	Node <nType> * getNextPtr () const;
private:
    Node <nType> * nextPtr;
    nType data;
};

template <typename nType>
class List
{
public:
	List ();
	~List ();
	void insertAtBack();
	void insertAtFront();
	int insertAtPos();
	void removeFromBack();
	void removeFromFront();
	int removeFromPos();
	void sort();
    int update();
    void reverse();
	void display() const;
	bool isEmpty ()const;
	int size() const;
	Node<nType>* getFirstPtr() const;
	Node<nType>* getLastPtr() const;
private:
	Node <nType> *firstPtr; //pointer to first node
	Node <nType> *lastPtr; //pointer to last node
	Node <nType> *createNewNode(const nType &);

};
#endif



