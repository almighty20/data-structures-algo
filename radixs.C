#include<iostream>
using namespace std;

class queue{
public:
	int n,f,r;
	int *arr;
	queue(int s)
	{
		n = s;
		f = r = -1;
		arr = new  int[n];
	}
	
	bool isempty()
	{
		return (r == -1);
	}
	
	bool isfull()
	{
		return (f == (r + 1)%n);
	}
	
	void enqueue(int e)
	{
		if(isfull())
			return;
		if(r == -1)
			f == 0;
		r = (r + 1)%n;
		arr[r] = e;
	}
	
	int dequeue()
	{
		if(isempty())
			return -1;
		int t = arr[f];
		if(f == n)
			f = r = -1;
		f = (f+1)%n;
		return t;
	}
};

int count_digits(int e)
{
	int d = 0;
	while(e > 0)
	{
		d++;
		e = e/10;
	}
	return d;
}

int get_dig(int e,int d)
{
	int a;
	while(d > 0)
	{
		a = e % 10;
		e = e / 10;
		d--;
	}
	return a;
}

int get_max(int a[],int n)
{
	int b = a[0];
	for(int i = 1;i<n;i++)
	{
		if(b < a[i])
			b = a[i];
	}
	return b;
}

int r_s(int a[],int n)
{
	
	int max = get_max(a,n);
	int k = count_digits(max);
	queue q[10](n);
	for(int i = 0;i < k;i++)
	{
		for(int j = 0;j < n;j++)
		{
			int d = get_dig(a[j],i);
			q[d].enqueue(a[j]);
		}
		
		for(int j = 0;j < 10;j++)
		{
			int m = 0;
			while(!q[j].isempty())
			{
				a[m++] = q[j].dequeue();
			}
		}
	}
}

void printArr(int a[], int n) 
{
    int i;  
    for (i = 0; i < n; i++)  
        cout << a[i] <<" ";  
} 

int main()
{
	int n,e;
	cout<<"Enter the size of array\n";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of array\n";
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	 cout<<"Before sorting array elements are - "<<endl;  
    	 printArr(a, n);  
	 r_s(a,n); 
   	 cout<<"\nAfter sorting array elements are - "<<endl;  
  	 printArr(a, n);  
  	 cout<<"\n";
  	 return 0;  
}

