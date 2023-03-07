#include "iostream"
using namespace std;
int bs(int a[],int ns,int l, int u)
{
	int m;
	m = (l+u)/2;
	if(l>u)
		return -1;
	else
		{
		if (a[m]==ns)
			return m;
		else if (a[m]<ns)
			return(bs(a,ns,m+1,u));
		else
			return(bs(a,ns,l,u-1));		
		}
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
	cout<<"Enter the number to be searched using binary recursive search!!! "<<endl;
	cin>>ns;
	int r=bs(arr,ns,0,n);
	if (r==-1)
		cout<<"Binary Search unsucessfull."<<endl;
	else
		cout<<"Found at "<<(r+1)<<" using binary recursive search."<<endl;
}
