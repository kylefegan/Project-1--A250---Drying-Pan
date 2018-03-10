#ifndef ANYLIST_H
#define ANYLIST_H

#include<iostream>
#include <string>		//Need to include for NULL			
using namespace std;

class Node
{
public:
	Node() : data(""), ptrToNext(nullptr) {}
	Node(string theData, Node *newPtrToNext)
		: data(theData), ptrToNext(newPtrToNext) {}
	Node* getPtrToNext() const { return ptrToNext; }
	string getData() const { return data; }
	void setData(string theData) { data = theData; }
	void setPtrToNext(Node *newPtrToNext)
	{
		ptrToNext = newPtrToNext;
	}
	~Node() {}
private:
	string data;
	Node *ptrToNext;	//pointer that points to next node
};


class AnyList
{
	friend ostream& operator<<(ostream& out, const AnyList& list);
public:
	AnyList();
	//default constructor

	AnyList(const AnyList& otherList);
	//copy constructor

	AnyList(AnyList&& otherList);
	//move constuctor

	AnyList& operator=(AnyList&& otherList);
	//move assignment operator

	AnyList& operator=(const AnyList& otherList);
	//assignmt operator

	//get first
	Node* getFirst() const;

	//return address of object
	const AnyList* addressObject() const;

	//get address of first 
	const Node* addressFirst() const;
	
	void insertFront(string);
	//insertFront - Inserts a node to the front of the list.
	//@param int - Value stored in the node that is inserted.

	void deleteNode(string);
	//deleteNode - Deletes a node from the list.
	//@param int - Value stored in the node to be deleted.

	void destroyList();
	//destroyList - Destroys all nodes in the list.

	~AnyList();
	//destructor

private:
	Node *ptrToFirst; //pointer to point to the first node in the list
	int count;	      //keeps track of number of nodes in the list
};

#endif#pragma once

