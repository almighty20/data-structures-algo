#include "iostream"
using namespace std;

class CQueue{
	public:
	int *arr;
	int s, f, r;
	CQueue(int n){
		s = n;
		f = -1;
		r = -1;
		arr = new int[s];
		}

	bool isFull(){
		return(f == (r+1)%s);	
	}
	
	bool isEmpty(){
		return (r == -1);
	
	}

	void enqueue(int e){
		if(!isFull()){
			if(r == -1){
				f = 0;
			}
			r=(r+1)%s;
			arr[r]=e;
		}
		else{
			cout<<"Queue overflow"<<endl;
		}		
	}

	int dequeue(){
			int temp = -1;
			if(!isEmpty()){
				temp = arr[f];
				f=(f+1)%s;
				if(f==(r+1)%s){
					f = -1;
					r = -1;				
				}
				
			}
			else{
				cout<<"Queue is empty"<<endl;
			}
			return temp;
							
	}
	

};

int count_digit(int e){
	int d = 0;
	while(e>0){
		d++;
		e = e/10;
	}
	return d;
}

int get_digit(int e,int d){
	int digit;
	while(d>0){
		digit = e%10;
		e = e/10;
		d--;
	}
	return digit;
}
void radix_sort(int arr[],int n){
	int max = arr[0];
	for(int i=0; i<n; i++){
		if(arr[i]>max){
			max = arr[i];
			
		}
	
		
	}
	int k = count_digit(max);
	CQueue *q[10];
	for(int i= 0; i<10;i++){
		q[i] = new CQueue(n);
	}
	for(int i = 1; i<= k; i++){
		for(int j = 0;j <n; j++){
			int d = get_digit(arr[j],i);
			q[d]->enqueue(arr[j]);	
		}
		
		int m =0;
		for(int j=0; j<10;j++){
			while(!q[j]->isEmpty()){
				arr[m++] = q[j]->dequeue();
			}
		}
	}
	
	
}

int main(){
	cout<<"Enter the size of array: ";
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the array: ";
	for(int i = 0; i<n; i++){
		cin>>arr[i];
		
	}
	
	radix_sort(arr,n);
	
	cout<<"Sorted Array: "<<endl;
	for(int i = 0;i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
