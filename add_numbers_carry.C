#include "iostream"
using namespace std;
class Stack
{
	public:
		int *arr, size;
        	int top;
		Stack(int s)
		{
			size=s; 
			top=0; 
			arr=new int[size];
		}
        bool isEmpty()
		{
		return(top==0);
		}

		bool isFull()
		{
			return(top==size);
		}
        void push(int e)    
		{
			if(isFull())
	                {
				cout<<"Stack Overflow"<<endl;
			}
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
};
int carry;
int addtwonum(Stack s1, Stack s2)
{
            Stack s3(20);
            while(!s1.isEmpty() && !s2.isEmpty())
            {
                int d1=s1.pop();
                int d2=s2.pop();
                int sum=d1+d2+carry;
                s3.push(sum%10);
                carry=sum/10;
            } 
            while (!s1.isEmpty())
            {
                int d=s1.pop();
                int s=d+carry;
                s3.push(s%10);
                carry=s/10;

            }
            while (!s2.isEmpty())
            {
                int d=s2.pop();
                int s=d+carry;
                s3.push(s%10);
                carry=s/10;
            }
            if(carry>0)
                s3.push(carry);
            while (!s3.isEmpty())
                cout<<s3.pop();
            
            return 0; 
}
int main()
{
	int size,ele,choice,Size,elt;
	cout<<"\n Enter the size of 1st Stack : "<<endl;
	cin>>size;
	Stack s1(size);
    	cout<<"\n Enter the Size of 2nd Stack : "<<endl;
    	cin>>Size;
        Stack s2(Size);
	cout<<"\n 1. Add to stack 1st";
	cout<<"\n 2. Add to stack 2nd";
        cout<<"\n 3. Exit";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	while(choice!=3)
	{
		switch(choice)
		{
			case 1 : cout<<"Enter element:";
				 cin>>ele;
				 s1.push(ele);
				 break;
            		case 2 : cout<<"Enter element:";
				 cin>>elt;
				 s2.push(elt);
				 break;
			case 3 : break;
			default : cout<<"Invalid input!!"<<endl;
				  break;
		}
	cout<<"Enter your choice:";
	cin>>choice;
	}
    addtwonum(s1,s2);
	return 0;
}

        
