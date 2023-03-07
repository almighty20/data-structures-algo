using namespace std;
#include "iostream"
int linear(int arr[],int ele)
{
	for(int i=0;i<10;i++)
	{
		if(arr[i]==ele)
			return i;
	}
	return -1;
}

int main()
{
	int arr[10],num;
	cout<<"Enter array:";
	for(int i=0;i<10;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter element to be searched:";
	cin>>num;
	int pos=linear(arr,num);
	if(pos == -1)
		cout<<"element not found";
	else
		cout<<"Element found at position:"<<pos+1;
	return 0;
}
