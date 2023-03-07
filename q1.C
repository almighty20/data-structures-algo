#include "iostream"
using namespace std;
int bsearch(int array[], int left, int right)
{
     if(left < right)
     {
         if(array[left] < array[right])             // case 1
             return array[left];
         int mid = left + (right - left)/2;
         if(array[mid] > array[right])
             return bsearch(array, mid + 1, right);  // case 2
         else 
             return bsearch(array, left, mid);     // case 3
     }
    return array[left];
}
int main()
{
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	int *array = new int[size];
	cout<<"Enter the value in the array:"<<endl;
	for(int i = 0; i<size;i++)
		cin>>array[i];
	cout<<"The minimum is : "<<bsearch(array, 0, size - 1)<<endl;
}
