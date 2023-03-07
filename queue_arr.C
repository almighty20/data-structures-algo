#include "iostream"
using namespace std;
class Queue
{
	public:
		int end, *arr, size;
		Queue(int s)
		{
			size=s; end=0; arr=new int[size];
		}
		bool isEmpty(){
		return(end==0);}
		bool isFull(){
		return(end==size);}
		void enqueue(int e)
		{
			if(isFull()){
				cout<<"Stack Overflow"<<endl;}
			else
			{
				arr[end]=e;
				end++;
			}
		}
		int dequeue()
		{
			if(isEmpty())
			{
				cout<<"Stack Underflow"<<endl;
				return -1;			
			}
			else
			{
				int j = arr[0];
				for(int i=1;i<end;i++)
				{
					arr[i-1]=arr[i];
				}
				return j;
			}
		}
		void display(){
		for(int i=0;i<=end-1;i++)
		cout<<arr[i]<<",";}
		int peek()
		{
			if(isEmpty())
			{
			cout<<"Stack Underflow"<<endl;
			return -1;
			}
			else{
			return arr[0];}
		}
};

int main()
{
	cout<<"Enter the size of Queue : "<<endl;
	int size,ele,choice,pos,x;
	cin>>size;
	Queue obj(size);
	cout<<"\n ***********MENU**********";
	cout<<"\n 1. Enqueue";
	cout<<"\n 2. Dequeue";
	cout<<"\n 3. Display";
	cout<<"\n 4. Peek";
	cout<<"\n 5. Is Empty";
	cout<<"\n 6. Is full";
	cout<<"\n 7. Exit";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	while(choice!=7)
	{
		switch(choice)
		{
			case 1 : cout<<"Enter element:";
				 cin>>ele;
				 obj.enqueue(ele);
				 break;
			case 2 : cout<<(obj.dequeue())<<endl;
				 break;
			case 3 : obj.display();cout<<endl;
				 break;
			case 4 : cout<<(obj.peek())<<endl;
				 break;
			case 5 : cout<<(obj.isEmpty())<<endl;
				 break;
			case 6 : cout<<(obj.isFull())<<endl;
				 break;
			case 7 : break;
			default : cout<<"Invalid input!!"<<endl;
				  break;
		}
	cout<<"Enter your choice:";
	cin>>choice;
	}
	return 0;
}
