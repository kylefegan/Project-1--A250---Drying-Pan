/*
	Cortes, Andre

	CS A200
	May 13,2018

	Lab 6
*/

#include "BST.h"


// Definition function insert (non-recursive) 
void BST::insert(int item)
{
	Node *newNode = new Node;
	newNode->data = item;
	if (root == nullptr)
		root = newNode;
	else
	{
		Node *current = root;
		bool found = true;
		while (found)
		{
			if (item == current->data)
			{
				cout << "The item to insert is already in the list – duplicates are not allowed.";
				found = false;
			}
			else if (current->data > item && current->llink != nullptr)
				current = current->llink;
			else if (current->data < item && current->rlink != nullptr)
				current = current->rlink;
			else if (current->data > item)
			{
				current->llink = newNode;
				found = false;
			}
			else
			{
				current->rlink = newNode;
				found = false;
			}
		}
	}
}
// Definition function totalNodes
int BST::totalNodes() const
{
	if (root == nullptr)
		return 0;
	else
	{
		return totalNodes(root);
	}
}
// Definition function totalNodes (recursive)
int BST::totalNodes(const Node* p) const
{
	int count = 1;
	if (p->llink != nullptr) 
	{
		count += totalNodes(p->llink);
	}
	if (p->rlink != nullptr) 
	{
		count += totalNodes(p->rlink);
	}
	return count;
}
// Definition overloaded function preorderTraversal
void BST::preorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is not tree.";
	else
	{
		preorderTraversal(root);
	}
}
// Definition overloaded function preorderTraversal (recursive)

void BST::preorderTraversal(const Node *p) const
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		preorderTraversal(p->llink);
		preorderTraversal(p->rlink);
	}
}
// Definition overloaded function postorderTraversal

void BST::postorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is not tree.";
	else
	{
		postorderTraversal(root);
	}
}
// Definition overloaded function postorderTraversal (recursive)
void BST::postorderTraversal(const Node *p) const
{
	if (p != nullptr)
	{
		postorderTraversal(p->llink);
		postorderTraversal(p->rlink);
		cout << p->data << " ";
	}
}