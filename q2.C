#include "iostream"
using namespace std;
void m(int arr[],int l,int h,int mid,int n)
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
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void ms(int arr[],int l, int h, int n)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		ms(arr,l,mid,n);
		ms(arr,mid+1,h,n);
		m(arr,l,h,mid,n);
	}
}
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int arr[], int start, int end,int n)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl; 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end,int n)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end,n);
    quickSort(arr, start, p - 1,n);
    quickSort(arr, p + 1, end,n);
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
	cout<<"Merge Sort!!!"<<endl;
	ms(arr,0,n-1,n);
	cout<<"Quick Sort!!!"<<endl;
	quickSort(arr, 0, n - 1,n);
}
