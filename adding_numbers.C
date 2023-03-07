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
class doublylinkedstack
{
	public:
		Node *head,*tail;
		int count,temp;
		doublylinkedstack()
		{
			count=0;
			head=NULL;
			tail=NULL;
		}
		void push(int data)
		{
			Node *n1=new Node(data);
			if(isEmpty())
			{
				head=n1;
				tail=n1;
				
			}
			else
			{
				tail->next=n1;
				n1->prev=tail;
				tail=n1;
			}
			count++;
		}
		int pop()
		{	
			int out;
			out=tail->data;
			if(isEmpty())
				return -1;
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;tail=NULL;
			}
			else
			{
				tail=tail->prev;
				delete tail->next;
				tail->next=NULL;
			}
			count--;
			return out;
		}
		bool isEmpty()
		{
		return(head==NULL);
		}
		int peek()
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
int pow(int a,int b)
{
	int ans=1;
	for(int i=1;i<=b;i++)
	{
		ans*=a;
	}
	return ans;
}
int add(doublylinkedstack s1,doublylinkedstack s2)
{
	int i=0,sum=0,digit=0,ca;
	while(!s1.isEmpty()&&!s2.isEmpty())
	{
		digit=s1.pop()+s2.pop();
		sum+=digit*pow(10,i);
		i++;
	}
	while(!s1.isEmpty())
	{
		digit=s1.pop();
		sum+=digit*pow(10,i);
		i++;
	}
	while(!s2.isEmpty())
	{
		digit=s2.pop();
		sum+=digit*pow(10,i);
		i++;
	}
	return sum;
}
int main()
{
	int ele,choice,pos,x;
	doublylinkedstack obj1;
	doublylinkedstack obj2;
	int i1=0,i2=0;
	cout<<"Enter the 1st number to add and -1 to exit"<<endl;
	while (true)
	{
		cin>>i1;
		if (i1!=-1)
		{
			obj1.push(i1);	
			cout<<obj1.peek()<<endl;
		}
		else
		{
			cout<<obj1.peek()<<endl;
			break;
		}
	}
	cout<<"Enter the 2nd number to add and -1 to exit"<<endl;	
	while (true)
	{
		cin>>i2;
		if (i2!=-1)
		{
			obj2.push(i2);	
			cout<<obj2.peek()<<endl;
		}
		else
		{
			cout<<obj2.peek()<<endl;
			break;
		}
	}
	cout<<"The sum is: "<<add(obj1,obj2)<<endl;
	return 0;
}

