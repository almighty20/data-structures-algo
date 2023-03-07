#include "iostream"
using namespace std;
int bs(int a[],int ns,int l, int u)
{
	int m;
	while(l<=u)
	{
		m = (l+u)/2;
		if (a[m]==ns)
		return m;
		else if (a[m]<ns)
		l=m+1;
		else
		u=m-1;
	}
	return -1;
}
int ls(int a[],int ns,int l,int u)
{
	int i;
	for(i=l;i<u;i++)
	{
		if(a[i]==ns)
		return i;
	}	
	return -1;
}
int main()
{
	int n;
	cout<<"Enter the limit :";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array : "<<endl;
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	}
	int ns;
	cout<<"Enter the number to be searched using both search!!! "<<endl;
	cin>>ns;
	int r=bs(arr,ns,0,n);
	if (r==-1)
	cout<<"Binary Search unsucessfull."<<endl;
	else
	cout<<"Found at "<<(r+1)<<"using linear search."<<endl;
	int rl=ls(arr,ns,0,n);
	if (rl==-1)
	cout<<"Linear Search unsucessfull."<<endl;
	else
	cout<<"Found at "<<(rl+1)<<" using linear search."<<endl;
}
