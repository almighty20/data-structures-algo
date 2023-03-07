#include "iostream"
using namespace std;

class Node{
	public:
	float data;
	Node* next;
	Node* prev;
	Node(float d){
		data = d;
		next = NULL;
		prev = NULL;
	}
};

class Double_Linked_List{
	public:
	int count;
	Node* head;
	Node* tail;

	Double_Linked_List(){
		count = 0;
		head = NULL;
		tail = head;
	}

    bool isEmpty(){
        return head==NULL;
    }

	void add_at_end(float ele){
		Node* n = new Node(ele);
		if(head == NULL){
			head = n;
			tail = head;
		}
		else{
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
		count++;
	}

	float remove_from_beg(){
		float t;
        if(head == NULL){
			return -1;
		}
		else if(head == tail){
            t = head->data;
			delete head;
			head = NULL;
			tail = NULL;
		}
		else{
			Node* temp = head;
			head = head->next;
			head->prev = NULL;
            t = temp->data;
			delete temp;
		}
        count--;
        return t;
	}

    void traverse(){
		Node* temp = head;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}

};

void insert_sort(Double_Linked_List L, int n){
    Node* t = L.head;
    if(n < 2){
        return;
    }
    for(int i=0; i<n-1; i++){
        int j = i+1;
        int count = 0;
        while(count < j){
            t = t->next;
            count++;
        }
        float temp = t->data;
        while(j>0 && t->prev != NULL && t->prev->data > temp){
            t->data = t->prev->data;
            t = t->prev;
            j--;
        }
        t->data = temp;
    }
}

void bucket_sort(float arr[], int n){
    Double_Linked_List b[n];
    for(int i=0; i<n; i++){
        int ind = int(arr[i]*n);
        b[ind].add_at_end(arr[i]);
    }
    int k = 0;
    for(int i=0; i<n; i++){
        insert_sort(b[i], b[i].count); 
        while(!b[i].isEmpty()){
            arr[k++] = b[i].remove_from_beg();
        }
    }
}

int main(){
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;
    float arr[n];
    cout<<"Enter the elements of array :-"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<endl;
    cout<<"Unsorted array: ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;

    bucket_sort(arr, n);

    cout<<"Sorted array: ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}