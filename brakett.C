#include "iostream"
using namespace std;
class astack
{
	public:
		int top,*arr;
		int size;
		astack(int s)
		{	size=s;
			arr=new int[size];
		}
		bool isempty()
		{	return(top==0);
		}
		bool isfull()
		{	return(top==size-1);
		}
		void push(int e)
		{	if(isfull())
			{	cout<<"stack overflow";
				return;
			}
			arr[top]=e;
			top++;
		}
		int pop()
		{	if(isempty())
			{	cout<<"Stack underflow";
				return -1;
			}
			top--;
			return arr[top];
		}
		void display()
		{	for(int i=top-1;i>=0;i++)
			{	cout<<arr[i]<<" ";
			}
		}
		int peek()
		{	if(!isempty())
			{	return arr[top-1];
			}
		}
				
};
bool isvalid(char arr[],int n)
		{	astack s(n);
			bool valid=true;
			for(int i=0;i<n;i++)
			{	if(arr[i]=='(' || arr[i]=='[' || arr[i]=='{')
				{	s.push(arr[i]);
				}
				else if(arr[i]==')')
				{	if(!s.isempty())
					{	char ch=(char)(s.peek());
						if(ch=='(')
						{	s.pop();
						}
						else			
						{	valid=false;
							break;
						}
					}
					else
					{	valid=false;
						break;
					}
				}
				else if(arr[i]==']')
				{	if(!s.isempty())
					{	char ch=(char)s.peek();
						if(ch=='[')
						{	s.pop();
						}
						else			
						{	valid=false;
							break;
						}
					}
					else
					{	valid=false;
						break;
					}
				}
				else if(arr[i]=='}')
				{	if(!s.isempty())
					{	char ch=(char)s.peek();
						if(ch=='{')
						{	s.pop();
						}
						else			
						{	valid=false;
							break;
						}
					}
					else
					{	valid=false;
						break;
					}
				}
				else
				{	valid=false;
					break;
				}
			}
			if (!s.isempty())
			{
				valid=false;
			}
			return valid;
		}
int main()
{	char *arr;
	int n;

	cout<<"Enter the size of array:";
	cin>>n;
	arr=new char[n];
	cout<<"Enter the expression:";
	for(int i=0;i<n;i++)
	{	cin>>arr[i];
	}

	bool valid=isvalid(arr,n);
		if(valid)
		{	cout<<"Valid Expresiion";
		}
		else
		{	cout<<"Invalid Expression";
		}
	
return 0;
} 

