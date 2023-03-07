#include "iostream"
using namespace std;
class Node
{
	public:
		int data;
		Node *next, *prev;
		Node(int d)
		{
			this->data=d;
			next=NULL;
			prev=NULL;
		}
};
class doublylinkedqueue
{
	public:
		Node *head,*tail;
		int count,temp;
		doublylinkedqueue()
		{
			count=0;
			head=NULL;
			tail=NULL;
		}
		void enqueue(int data)
		{
			Node *n1=new Node(data);
			if(head==NULL)
			{
				head=n1;
				tail=n1;
			}
			else
			{
				n1->next=head;
				head->prev=n1;
				head=n1;
			}
			count++;
		}
		void traverse()
		{
			Node *temp=tail;
			if(isEmpty())
				cout<<"List is empty";
			else
			{
				while(temp->prev!=NULL)
				{
					cout<<temp->data<<" ";
					temp=temp->prev;
				}
				cout<<temp->data<<" ";
			}
		}
		int LinSearch(int ele)
		{
			int i=0;
			Node *temp=tail;
			if(temp==NULL)
				return -1;
			while(temp->prev!=NULL)
			{
				if(ele==temp->data)
					return i;
				i++;
				temp=temp->prev;
			}
			if(temp->data==ele)
				return i;
			return -1;
		}
		int dequeue()
		{	
			if(isEmpty())
				return -1;
			else if(head->next==NULL)
			{
				cout<<"Element to be deleted : "<<tail->data<<endl;
				delete head;
				head=NULL;tail=NULL;
			}
			else
			{
				cout<<"Element to be deleted : "<<tail->data<<endl;
				tail=tail->prev;
				delete tail->next;
				tail->next=NULL;
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
			return tail->data;}
		}
};
int main()
{
	int ele,choice,pos,x;
	doublylinkedqueue obj;
	cout<<"\n ***********MENU**********";
	cout<<"\n 1. Enqueue";
	cout<<"\n 2. Print";
	cout<<"\n 3. Is Empty";
	cout<<"\n 4. Peek";
	cout<<"\n 5. Search";
	cout<<"\n 6. Dequeue";
	cout<<"\n 7. Exit";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	while(choice!=7)
	{
		switch(choice)
		{
			case 1 : cout<<"Enter element: ";
				 cin>>ele;
				 obj.enqueue(ele);
				 break;
			case 2 : obj.traverse();
				 cout<<"\n";
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
			case 6 : x=obj.dequeue();
				 if(x!=-1)
					cout<<"Element deleted from End!!"<<endl;
				 else
					cout<<" List is empty!! "<<endl;
				 break;
			default : cout<<"Invalid input!!"<<endl;
				  break;
		}
	cout<<"Enter your choice:";
	cin>>choice;
	}
	return 0;
}
