#include "iostream"
using namespace std;
void bS(int arr[], int n) 
{
int temp;
for(int i=0;i<n;i++)
{
for(int j=i+1;j<n-1;j++)
{
	if(arr[j]<arr[i])
	{
		temp=arr[i];
		arr[i]=arr[j];
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
    bS(arr, n); 
    printArray(arr, n);
    return 0; 
} 
