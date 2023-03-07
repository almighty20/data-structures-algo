#include "iostream"
using namespace std;
void m(int arr[],int l,int h,int mid)
{
	int b[h-l+1];
	int i,j,k;
	for(i=l,j=mid+1,k=0;i<mid+1&&j<=h;)
	{
		if(arr[i]<arr[j])
		{
			b[k]=arr[i];
			i++;k++;
		}
		else if(arr[j]<arr[i])
		{
			b[k]=arr[j];
			j++;k++;
		}
		else
		{
			b[k]=arr[i];
			k++;
			b[k]=arr[j];
			k++;
			j++;
			i++;
		}
	}
	while(i<=mid)
		b[k++]=arr[i++];
	while(j<=h)
		b[k++]=arr[j++];
	k=0;
	for(i=l;i<h+1;i++)
	arr[i]=b[k++];
}
void ms(int arr[],int l, int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		ms(arr,l,mid);
		ms(arr,mid+1,h);
		m(arr,l,h,mid);
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
	ms(arr,0,n-1);
	cout<<"Sorted array is "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}
