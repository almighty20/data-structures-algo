using namespace std;
#include "iostream"
int minn(int a[],int n)
		
	{
		int min = a[0];
		for(int i = 1;i<n;i++)
		{
			
			if(min>a[i])
			{
				min = a[i];
			}
		}
		return min;

	}
int maxx(int a[],int n)
		
	{
		int max = a[0];
		for(int i = 1;i<n;i++)
		{
			
			if(max<a[i])
			{
				max = a[i];
			}
		}
		return max;

	}
void countSort(int arr[],int n)
{
	int min = minn(arr,n);
	int max = maxx(arr, n);
	int size = max - min + 1;
	int c[size];
	int b[n];
	for( int i = 0;i<size;i++)
	{
	c[i] = 0;
	}
	for( int i = 0;i<n;i++)
	{
	c[arr[i] - min] ++;
	}
	for( int i = 1;i<size;i++)
	{
	c[i] += c[i-1];
	}
	
	
	for(int i = n-1; i>=0;i--)
	{
		b[c[arr[i]-min]-1] = arr[i];
		c[arr[i]-min]--;
	}
	cout<< "Sorted array is : ";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}

}


int main()
{
	int n;
	cout<<"Enter length of array : ";
	cin>>n;
	int arr[n],num;
	cout<<"Enter array : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"Min is "<<minn(arr,n)<<endl;
	cout<<"Max is "<< maxx(arr,n)<<endl;
	countSort(arr,n);
	return 0;
}
