#include "TwoWayList.h"
#include <iostream>

using namespace std;

int main()
{
	TwoWayList list;
	int n;
	int a;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		list.pushFront(a);
	}

	n /= 2;

	Node* beg = list.GetHead();
	Node* end = list.GetHead();

	while (end->next != nullptr)
	{
		end = end->next;
	}

	for (int i = 0; i < n - 1; i++)
	{
		sum += beg->data * end->data;
		end = end->prev;
		beg = beg->next;
	}

	sum += end->data * beg->data;

	cout << "-------------------" << endl;
	cout << sum;
}