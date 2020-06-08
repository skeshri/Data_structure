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
	void InsertAtIndex(int data, int index); // Inserting elements at particular index
	int  Remove(int index); // Remove element at particular index
	int  GetSize() const; // counts how many time insert method called.
	void Print() const; // Print elements of the list.
	void FreeMemory(); // Free the memory, allocated dynamically.
	void IterativeReverse(); // Reverse the list iteratively.

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

void LinkedList::InsertAtIndex(int data, int index)
{
	size++;
	Node *temp1 = new Node();
	temp1->data = data;
	temp1->next = nullptr;
	if(index == 1)
	{
		temp1->next = head;
		head = temp1;
	}
	else
	{
		Node *temp2 = head;
		for(int i=1; i<index-1 ;i++)
		{
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
	}

}

int LinkedList::Remove(int index)
{
	//current is the pointer to the node to be removed.
	int data;
	if (index == 1)
	{
		Node *current = head;
		head = current->next;
		data = current->data;
		delete current;
		return data;
	}
	else 
	{
		Node* prev = head;
		Node *current = nullptr;
		for(int i=1; i<index-1; i++)
		{
			prev = prev->next;
		}
		current = prev->next;
		prev->next = current->next;
		data = current->data;
		delete current;
		return data;
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


void LinkedList::IterativeReverse()
{
	Node *current = head;
	Node *next, *prev;
	prev = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
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
	l.InsertAtBeginning(10);
	l.InsertAtIndex(100,5);
	l.Print();
//	cout<<"element removed from list: "<<l.Remove(5)<<endl;
//	cout<<"element removed from list: "<<l.Remove(1)<<endl;

	l.IterativeReverse();
	l.Print();
	cout<<"size of the LinkedList: "<<l.GetSize()<<endl;
}