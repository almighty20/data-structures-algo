#include "iostream"
using namespace std;
class Stack
{
	public:
		int top, *arr, size;
		Stack(int s)
		{
			size=s; top=0; arr=new int[size];
		}
		bool isEmpty(){
		return(top==0);}
		bool isFull(){
		return(top==size);}
		void push(int e)
		{
			if(isFull()){
				cout<<"Stack Overflow"<<endl;}
			else
			{
				arr[top]=e;
				top++;
			}
		}
		int pop()
		{
			if(isEmpty())
			{
				cout<<"Stack Underflow"<<endl;
				return -1;			
			}
			else
			{
				top--;
				return arr[top];
			}
		}
		void display(){
		for(int i=top-1;i>=0;i--)
		cout<<arr[i]<<",";}
		int peak()
		{
			if(isEmpty())
			{
			cout<<"Stack Underflow"<<endl;
			return -1;
			}
			else
			return arr[top-1];
		}
};

int main()
{
	cout<<"Enter the size of Stack : "<<endl;
	int size,ele,choice,pos,x;
	cin>>size;
	Stack obj(size);
	cout<<"\n ***********MENU**********";
	cout<<"\n 1. Push";
	cout<<"\n 2. Pop";
	cout<<"\n 3. Display";
	cout<<"\n 4. Peek";
	cout<<"\n 5. Is Empty";
	cout<<"\n 6. Is full";
	cout<<"\n 7. Remove from End";
	cout<<"\n 8. Remove from Beg";
	cout<<"\n 9. Add at End";
	cout<<"\n 10. Add at Beg";
	cout<<"\n 11. Exit";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	while(choice!=11)
	{
		switch(choice)
		{
			case 1 : cout<<"Enter element:";
				 cin>>ele;
				 obj.push(ele);
				 break;
			case 2 : cout<<(obj.pop())<<endl;
				 break;
			case 3 : obj.display();
				 break;
			case 4 : cout<<(obj.peak())<<endl;
				 break;
			case 5 : cout<<(obj.isEmpty())<<endl;
				 break;
			case 6 : cout<<(obj.isFull())<<endl;
				 break;
			case 7 : cout<<(obj.pop())<<endl;
				 break;
			case 8 : 
			case 9:  cout<<"Enter element:";
				 cin>>ele;
				 obj.push(ele);
				 break;
			case 10:
			default : cout<<"Invalid input!!"<<endl;
				  break;
		}
	cout<<"Enter your choice:";
	cin>>choice;
	}
	return 0;
}
