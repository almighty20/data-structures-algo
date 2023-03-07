#include <iostream>
using namespace std;
class Node
{
public int data;
public Node* next;
	Node(int d)
	{
	data=d;
	next=null;
	}
};
class linked_list
{
public Node* head;
	linked_list()
	{
		head=null;
	}

void traverse()
	{
	Node* temp=head;
	while (temp->next!=null)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<temp->data;
	}
	void addatBag(int data)
	{
	Node* n1 == new Node(data);
	if(head==null)
		{
		head = n1;
		return;
		}
	else
		{
		n1->next=head;
		head=n1;
		return;
		}
	}
};
int main()
{

}

