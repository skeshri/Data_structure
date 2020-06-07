/*
==> Linked list (LL) efficienct in terms 
    of memory management compared to the array. 

==> Fundamental unit of a LL is Node. 
    Combining nodes form LL.

Implementation :
-- Insert elements.
-- Print elements.


Note: Traversing through all the nodes inside LL requires
first address of nodes preserved, also may be called as head node.
*/

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
	Node* head = nullptr;
	int size=0;
public:
	void InsertAtEnd(int data); // Inserting elements at the end of the list.
	void InsertAtBeginning(int data); // Inserting elements at beginning of the list
	int GetSize() const; // counts how many time insert method called.
	void Print() const; // Print elements of the list.
	void FreeMemory(); // Free the memory, allocated dynamically.

	~LinkedList()
	{
		FreeMemory();
	}
};

void LinkedList::InsertAtEnd(int data)
{
	size++;
	Node *temp1 = new Node();
	temp1->data = data;
	temp1->next = nullptr;
	if(head == nullptr)
	{
		head = temp1;
	}
	else
	{
		Node *temp2 = head;
		while(temp2->next != nullptr)
		{
			temp2 = temp2->next;
		}
		temp2->next=temp1;
	}
}

void LinkedList::InsertAtBeginning(int data)
{
	size++;
	Node *temp1 = new Node();
	temp1->data = data;
	temp1->next = nullptr;
	if (head == nullptr)
	{
		head = temp1;
	}
	else
	{
		Node *temp2 = head;
		head = temp1;
		temp1->next = temp2;
	}
}

int LinkedList::GetSize() const
{
	return size;
}

void LinkedList::Print() const
{
	cout<<"List all the elements in the LL"<<endl;
	Node* temp = head;
	while(temp != nullptr)
	{
		cout<<temp->data<<",  ";
		temp = temp->next;
	}
	cout<<endl;
}


void LinkedList::FreeMemory()
{
	if(head != nullptr)
	{
		Node* toDelete = head;
		while(toDelete != nullptr)
		{
			Node * next = toDelete->next;
			delete toDelete;
			toDelete = next;
		}
	}
}


int main()
{
	LinkedList l;
	l.InsertAtBeginning(1);
	l.InsertAtBeginning(2);
	l.InsertAtBeginning(3);
	l.InsertAtBeginning(4);
	l.Print();
	cout<<"size of the LinkedList: "<<l.GetSize()<<endl;
}