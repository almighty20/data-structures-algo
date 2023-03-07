#include <iostream>
using namespace std;

class Node
{
public : int data;
public : Node *next;
	Node(int d)
	{
	data=d;
	next=NULL;
	}
};
class linked_list
{
public : Node *head;
	linked_list()
	{
		head=NULL;
	}

public : void traverse()
{
	public : Node* temp=head;
	while (temp->next!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<temp->data;
}
public : void addatBag(int data)
{
	public : Node *n1 = new Node(data);
	if(head==NULL)
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
public : void attheEnd(int data)
{
	public : Node *n = new Node(data);
	if(head==NULL)
		{
		head=n;
		return;
		}
	else
	{
	Node *temp=head;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=n;
	}
}
public : void atthepos(int data,int pos)
{
	if(head==NULL&pos==0)
	{
		Node *n2=new Node(data);
		head=n2;
		return;
	}
	else if(temp!=NULL&&pos==0)
		attheBag(data);
	else (pos<=count)
	{
		Node *temp=head;
		Node *n3=new Node(data);
		int i=0;
	while(temp->!=NULL&&i<pos)
	{
		temp=temp->next;
		i++;
	}
	n3->next=temp->next;
	temp->next=n3;
	}	
	count++;
}

public : int ls(int ele)
{
	int i=0;
	Node *temp=head;
	if(temp==NULL)
		return -1;
	while(temp->next!=NULL)
	{
		if(ele==temp->data)
		return i;
		i++;
		temp=temp->next;
	}
	if(temp->data==ele)
		return i;
	return -1;
}
};
