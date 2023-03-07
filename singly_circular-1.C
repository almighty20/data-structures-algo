#include "iostream"
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		Node(int d)
		{
			this->data=d;
			next=NULL;
		}
};
class Linked_list
{
	public:
		Node *head,*tail;
		int count;
		Linked_list()
		{
			count=0;
			head=NULL;
			tail=NULL;
		}
		void addAtBeg(int data)
		{
			Node *n1=new Node(data);
			if(head==NULL)
			{
				head=n1;
				tail=n1;
				tail->next=head;
				
			}
			else
			{
				n1->next=head;
				head=n1;
				tail->next=head;
				
			}
			count++;
		}
		void traverse()
		{
			Node *temp=head;
			if(head!=NULL)
			{
				while(temp->next!=head)
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<temp->data<<" ";
			}
			else
			{
				cout<<"List is empty";
			}
		}
		void addAtEnd(int data)
		{
			Node *n1=new Node(data);
			if(head==NULL)
			{
				tail=n1;
				head=n1;
				tail->next=head;
				
			}
			else
			{
				tail->next=n1;
				n1->next=head;
				tail=n1;
			}
			count++;
		}
		void addAtPos(int data,int pos)
		{
			if(head==NULL && pos==0)
			{
				Node *n1=new Node(data);
				head=n1;
				
			}
			else if(head!=NULL && pos==0)
				addAtBeg(data);
			else if(pos<=count)
			{
				Node *temp=head;
				Node *n1=new Node(data);
				int i=0;
				while(temp->next!=NULL && i<pos-1)
				{
					temp=temp->next;
					i++;
				}
				n1->next=temp->next;
				temp->next=n1;
			}
			count++;
		}
		int LinSearch(int ele)
		{
			int i=0;
			Node *temp=head;
			if(temp==head)
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
		int removeFromBeg()
		{	
			if(head==NULL)
				return -1;
			else if(head==tail)
			{
				delete head;head=tail=NULL;
			}
			else
			{
				Node *temp=head;
				head=head->next;
				delete temp;
				tail->next=head;
			}
			count--;
			return 0;
		}
		int removeFromEnd()
		{	
			if(head==NULL)
				return -1;
			else if(head==tail)
			{
				delete head;
				head=NULL;tail=NULL;
			}
			else
			{
				Node *temp=head;
				while(temp->next->next!=NULL)
					temp=temp->next;
				delete temp;
				tail=temp;
				tail->next=head;
			}
			count--;
			return 0;
		}
		int removeFromPos(int pos)
		{
			if(head==NULL)
				return -1;
			else if(pos==0)
				removeFromBeg();
			else if(pos==count-1)
				removeFromEnd();
			else
			{
				Node *temp=head;
				int i=0;
				while(temp->next!=NULL && i<pos-1)
				{
					temp=temp->next;
					i++;
				}
				Node *t=temp->next;
				temp->next=temp->next->next;
				delete t;
				count--;
			}
		}
};
int main()
{
	Linked_list obj;
	int ele,choice,pos,x;
	cout<<"***********MENU**********";
	cout<<"\n 1. Add at begining";
	cout<<"\n 2. Traverse";
	cout<<"\n 3. Add at end";
	cout<<"\n 4. Add at position";
	cout<<"\n 5. Linear search";
	cout<<"\n 6. Remove from Beginning";
	cout<<"\n 7. Remove from End";
	cout<<"\n 8. Remove from Position";
	cout<<"\n 9. Exit";
	cout<<"\nEnter your choice:";
	cin>>choice;
	while(choice!=9)
	{
		switch(choice)
		{
			case 1 : cout<<"Enter element:";
				 cin>>ele;
				 obj.addAtBeg(ele);
				 break;
			case 2 : obj.traverse();
				 break;
			case 3 : cout<<"Enter element:";
				 cin>>ele;
				 obj.addAtEnd(ele);
				 break;
			case 4 : cout<<"Enter element:";
				 cin>>ele;
				 cout<<"Enter position:";
				 cin>>pos;
				 if(pos<=obj.count+1){
				 obj.addAtPos(ele,pos);}
				 else
				 cout<<"Wrong position, Choose again!!!! "<<endl;
				 break;
			case 5 : cout<<"Enter element to be searched:";
				 cin>>ele;
				 x=obj.LinSearch(ele);
				 if(x!=-1)
				 	cout<<"Element found at position:"<<x;
				 else 
				 	cout<<"Element not found!!"<<endl;
				 break;
			case 6 : x=obj.removeFromBeg();
				 if(x!=-1)
					cout<<"Element deleted from beginning!!"<<endl;
				 else
					cout<<" List is empty!!";
				 break;
			case 7 : x=obj.removeFromEnd();
				 if(x!=-1)
					cout<<"Element deleted from end!!"<<endl;
				 else
					cout<<" List is empty!!";
				 break;
			case 8 : cout<<"Enter position:";
				 cin>>pos;
				 if(pos<obj.count){
				 obj.removeFromPos(pos);
				 cout<<"Element deleted!!"<<endl;}
				 else
				 cout<<"Wrong position, Choose again!!!! "<<endl;
				 break;
			case 9:  break;
			default : cout<<"Invalid input!!"<<endl;
				  break;
		}
	cout<<"Enter your choice:";
	cin>>choice;
	}
	return 0;
}
