#include "iostream"
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		Node(int d)
		{
			data=d;
			next=NULL;
		}
};
class singlelinkedstack
{
	public:
		Node *head;
		int count,temp;
		singlelinkedstack()
		{
			count=0;
			head=NULL;
		}
		void push(int data)
		{
			Node *n1=new Node(data);
			if(isEmpty())
			{
				head=n1;
				
			}
			else
			{
				n1->next=head;
				head=n1;
				
			}
			count++;
		}
		void traverse()
		{
			Node *temp=head;
			if(isEmpty())
				cout<<"List is empty";
			else
			{
				while(temp->next!=NULL)
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<temp->data<<" ";
			}
		}
		int LinSearch(int ele)
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
		int pop()
		{	
			if(isEmpty())
				return -1;
			else
			{
				cout<<"Element to be deleted : "<<head->data<<endl;
				Node *temp=head;
				head=temp->next;
				delete temp;
			}
			count--;
			return 0;
		}
		bool isEmpty(){
		return(head==NULL);}
		int peak()
		{
			if(isEmpty())
			{
			cout<<"Stack Underflow"<<endl;
			return -1;
			}
			else{
			return head->data;}
		}
};
int main()
{
	int ele,choice,pos,x;
	singlelinkedstack obj;
	cout<<"\n ***********MENU**********";
	cout<<"\n 1. Push";
	cout<<"\n 2. Print";
	cout<<"\n 3. Is Empty";
	cout<<"\n 4. Peek";
	cout<<"\n 5. Search";
	cout<<"\n 6. Pop";
	cout<<"\n 7. Exit";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	while(choice!=7)
	{
		switch(choice)
		{
			case 1 : cout<<"Enter element:";
				 cin>>ele;
				 obj.push(ele);
				 break;
			case 2 : obj.traverse();
				 break;
			case 3 : cout<<(obj.isEmpty())<<endl;
				 break;
			case 4 : cout<<(obj.peak())<<endl;
				 break;
			case 5 : cout<<"Enter element to be searched: ";
				 cin>>ele;
				 x=obj.LinSearch(ele);
				 if(x!=-1)
				 	cout<<"\n Element found at position: "<<x<<endl;
				 else 
				 	cout<<"\n Element not found!!"<<endl;
				 break;
			case 6 : x=obj.pop();
				 if(x!=-1)
					cout<<"Element deleted from beginning!!"<<endl;
				 else
					cout<<" List is empty!!";
				 break;
			default : cout<<"Invalid input!!"<<endl;
				  break;
		}
	cout<<"Enter your choice:";
	cin>>choice;
	}
	return 0;
}
