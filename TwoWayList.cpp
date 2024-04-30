#/*include "TwoWayList.h"

Node* TwoWayList::CreateNode(int data)
{
	Node* newnode = new Node;
	newnode->data = data;
	newnode->next = nullptr;
	return newnode;
}

void TwoWayList::NewNodeAtEnd(TwoWayList list, int data)
{
	Node* newnode = CreateNode(data);

	if (list.head == nullptr)
	{
		list.head = newnode;
	}
	else
	{
		Node* curr = list.head;

		while (curr->next != nullptr)
		{
			curr = curr->next;
		}

		newnode->prev = curr;
		curr->next = newnode;
	}
}*/