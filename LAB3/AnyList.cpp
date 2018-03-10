#include"AnyList.h"
//overloaded insertion operator
ostream& operator<<(ostream& out, const AnyList& list)
{
	cout << list.ptrToFirst->getData();
	if (list.ptrToFirst != nullptr) // check if list is empty
	{
		Node *current;	//create a pointer to traverse the list 
		current = list.ptrToFirst;	//set the current pointer to point to the first node
		while (current != nullptr)	//while the current pointer is not pointing to NULL
		{						//  that is, the current pointer has not reached the 
								//  end of the list
			cout << " " << current->getData();	//output the data 
			current = current->getPtrToNext();		//move the current pointer forward
		}
		cout << endl;
	}
	return out;
}
//constructor
AnyList::AnyList()
{
	ptrToFirst = nullptr;
	count = 0;
}
//copy constuctor
AnyList::AnyList(const AnyList& otherList)
{
	Node* current = otherList.ptrToFirst;
	while(current != nullptr)
	{
		insertFront(current->getData());
		current = current->getPtrToNext();
	}
}
//move construcotr
AnyList::AnyList(AnyList&& otherList)
{
	count = otherList.count;
	ptrToFirst = otherList.ptrToFirst;
	otherList.count = 0;
	otherList.ptrToFirst = nullptr;
}
//insertFront
void AnyList::insertFront(string newData)
{
	Node *ptrToNewNode;		//create a pointer to point to a new node
	ptrToNewNode = new Node;	//create a new node

	ptrToNewNode->setData(newData);		//store data in the new node
	ptrToNewNode->setPtrToNext(ptrToFirst);	//set new node's pointer to point to the first node

	ptrToFirst = ptrToNewNode;		//make the new node be the "first" node

									/*
									There is better way to write the four statements above:

									Node *ptrToNewNode = new Node(newData, ptrToFirst);
									ptrToFirst = ptrToNewNode;

									Or even better:

									ptrToFirst = newNode(newData, ptrToFirst);
									*/

	++count;
}
// asignment operator
AnyList& AnyList::operator=(const AnyList& otherList)
{
	destroyList();

	Node * current = otherList.ptrToFirst;

	while (current != nullptr)
	{
		insertFront(current->getData());
		current = current->getPtrToNext();
	}

	return *this;
}
//move assignement operatior
AnyList& AnyList::operator=(AnyList&& otherList)
{
	ptrToFirst = otherList.ptrToFirst;
	count = otherList.count;
	delete otherList.ptrToFirst;
	otherList.ptrToFirst = nullptr;
	otherList.count = 0;
	return *this;
}
Node* AnyList::getFirst() const
{
	return ptrToFirst;
}
const AnyList* AnyList::addressObject() const
{
	return this;
}

const Node* AnyList::addressFirst() const
{
	return ptrToFirst;
}

//deleteNode
void AnyList::deleteNode(string deleteData)
{
	//Case: List is empty
	if (ptrToFirst == nullptr)
	{
		cerr << "Cannot delete from an empty list.\n";
	}
	else
	{
		Node *current;		   //create a pointer to traverse the list		
		bool found = false;	   //set a boolean value to keep track of 
							   //   whether the item is found or not

							   //Case: The node to be deleted is the first
		if (ptrToFirst->getData() == deleteData)
		{
			current = ptrToFirst;  //set current to point to first
			ptrToFirst = ptrToFirst->getPtrToNext();	//make first be the next node						
			delete current;
			current = nullptr;
			--count;
			found = true;
		}
		//Keep on searching the list
		else
		{
			Node *trailCurrent;	   //create a pointer to be right behind current
			trailCurrent = ptrToFirst;		 //set trailCurrent to point to the first node
			current = ptrToFirst->getPtrToNext(); //set current to point to the second node

			while ((current != nullptr) && (!found))	//while you are not to the end of the list
			{										//   and the item has not been found
													//we already checked the first node
													//  and we know does not contain the 
													//  data we are looking for,
													//  so we look at the second node
													//  (current is pointing to that)
				if (current->getData() == deleteData)	//if current is pointing to the item
				{										//  to be deleted, delete that node

														//Case: The item was found
					trailCurrent->setPtrToNext(current->getPtrToNext());
					delete current;
					current = nullptr;
					--count;
					found = true;
				}
				else
				{
					trailCurrent = current;			//move trailCurrent forward
					current = current->getPtrToNext();	//move current forward
				}
			}
		}
		//Case: Not found
		if (!found)
			cout << "Item to be deleted is not in the list." << endl;
	}
}

//destroyList - Does not delete the list object; it only deletes the nodes.
void AnyList::destroyList()
{
	Node  *temp; //pointer to delete the node

	while (ptrToFirst != nullptr)
	{
		temp = ptrToFirst;
		ptrToFirst = ptrToFirst->getPtrToNext();
		delete temp;
		temp = nullptr;
	}
	count = 0;
}
//destructor
AnyList::~AnyList()
{
	destroyList();
}
