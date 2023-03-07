#include <iostream>
using namespace std;

// function to swap the the position of two elements
void swap(int a, int b) 
{
  int temp = a;
  a = b;
  b = temp;
}

void printArray(int array[], int size) 
{
  for (int i = 0; i < size; i++) 
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

void max_heapify(int arr[],int i,int n)
{
	int li=2*i;
	int ri=2*i+1;
	int large=i;
	if(li<=n && arr[li] > arr[large])
		large=li;
	if(ri<=n && arr[ri] > arr[large])
		large=ri;
	if(large!=i)
	{
		swap(arr[i],arr[large]);
		max_heapify(arr,large,n);
	}
	return;
}

void build_heap(int arr[],int n)
{
	for(int i=n/2;i>=0;i--)
		max_heapify(arr,i,n);
}

void heapSort(int arr[],int n)
{
	build_heap(arr,n);
	for(int i=n;i>0;i--)
	{
		cout<<"Before swap in heapSort";
		swap(arr[i],arr[0]);
		n--;
		max_heapify(arr,0,n);
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
  heapSort(arr, n-1);
  cout << "Sorted array in Acsending Order:\n";
  printArray(arr, n);
}
