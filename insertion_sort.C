#include "iostream"
using namespace std;
void insertionSort(int arr[], int n) 
{
int temp;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
	if(arr[j+1]<arr[j])
	{
		temp=arr[j+1];
		arr[j+1]=arr[j];
		arr[j]=temp;		
	}
}
}
}
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
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
    insertionSort(arr, n); 
    printArray(arr, n);
    return 0; 
} 
