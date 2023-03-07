#include "iostream"
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		Node(int d)
		{
			data=d;
			next=NULL;
		}
};
class singlelinkedstack
{
	public:
		Node *head;Node* sorted;
		int count,temp;
		singlelinkedstack()
		{
			count=0;
			head=NULL;
		}
		void push(int data)
		{
			Node *n1=new Node(data);
			if(isEmpty())
			{
				head=n1;
				
			}
			else
			{
				n1->next=head;
				head=n1;
				
			}
			count++;
		}
		void insertionSort(Node* headref)
    {
        // Initialize sorted linked list
        sorted = NULL;
        Node* current = headref;
 
        // Traverse the given linked list
        // and insert every node to sorted
        while (current != NULL)
        {
            // Store next for next iteration
            Node* next = current->next;
 
            // Insert current in sorted
            // linked list
            sortedInsert(current);
 
            // Update current
            current = next;
        }
 
        // Update head_ref to point to
        // sorted linked list
        head = sorted;
    }
 
    /* Function to insert a new_node in a list.
       Note that this function expects a pointer
       to head_ref as this can modify the head of
       the input linked list (similar to push()) */
    void sortedInsert(Node* newnode)
    {
        // Special case for the head end
        if (sorted == NULL ||
            sorted->data >= newnode->data)
        {
            newnode->next = sorted;
            sorted = newnode;
        }
        else
        {
            Node* current = sorted;
 
            /* Locate the node before the
               point of insertion */
            while (current->next != NULL &&
                   current->next->data < newnode->data)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
    		int LinSearch(int ele)
		{
			int i=0;
			Node *temp=head;
			if(temp==NULL)
				return -1;
			while(temp->next!=NULL)
			{
				if(ele==temp->data)
					return i;
				i++;
				temp=temp->next;
			}
			if(temp->data==ele)
				return i;
			return -1;
		}
		void traverse()
		{
			Node *temp=head;
			if(isEmpty())
				cout<<"List is empty"<<endl;
			else
			{
				while(temp->next!=NULL)
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<temp->data<<" "<<endl;
			}
		}
		int pop(int pos)
		{
				Node *temp=head;
				int i=0,d;
				while(temp->next!=NULL && i<pos-1)
				{
					temp=temp->next;
					i++;
				}
				Node *t=temp->next;
				temp->next=temp->next->next;
				d=t->data;
				delete t;
				count--;
				return d;
		}
		bool isEmpty()
		{
		return(head==NULL);
		}
};
int main()
{
	int ele,choice,pos,x;
	singlelinkedstack obj;
	cout<<"\n ***********MENU**********";
	cout<<"\n 1. Push";
	cout<<"\n 2. Print";
	cout<<"\n 3. Sort";
	cout<<"\n 4. Delete Registration";
	cout<<"\n 5. Exit";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	while(choice!=5)
	{
		switch(choice)
		{
			case 1 : cout<<"Enter element: ";
				 cin>>ele;
				 cout<<endl;
				 if(obj.LinSearch(ele)==-1)
				 	obj.push(ele);
				 else
				 	cout<<"Duplicate bookings are not permitted!"<<endl;
				 break;
			case 2 : obj.traverse();
				 break;
			case 3 : (obj.insertionSort(obj.head));
				 break;
			case 4 : cout<<"Enter the roll number to cancel it's registration!"<<endl;
				 cin>>ele;
				 int pos;
				 pos = obj.LinSearch(ele);
                		 if(pos!=-1)
				 	cout<<"Cancelled registration is: "<<(obj.pop(pos))<<endl;
				 else
				 	cout<<"No such registration!"<<endl;
				 break;
			default : cout<<"Invalid input!!"<<endl;
				  break;
		}
	cout<<"Enter your choice:";
	cin>>choice;
	}
	return 0;
}
