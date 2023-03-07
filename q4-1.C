#include <iostream>
using namespace std;
class node
{   public:
    int r,c,e;
    node *next;
    node(int row,int coloumn,int element)
    {   r=row;
        c=coloumn;
        e=element;
        next=NULL;
    }
};
class linkedlist
{   public:
    node *head,*tail;
    int count;
    linkedlist()
    {   head=NULL;
        tail=NULL;
        count=0;
    }
    void push(int r,int c,int e)
    {   node *n=new node(r,c,e);
        if(head==NULL)
        {   n->r=r;
            n->c=c;
            n->e=e;
            head=n;
            tail=n;
            return;
        }
        else
        {   tail->next=n;
            n->r=r;
            n->c=c;
            n->e=e;
            tail=n;
        }
        count++;
    }
    void display()
    {   if(head==NULL)
        {   cout<<"NULL";
            return;
        }
        else 
        {   
            cout<<"("<<head->r<<","<<head->c<<","<<head->e<<")->";
            node *temp=head->next;
            while(temp->next!=NULL )
            {   if(temp->e!=0)
                {   cout<<"("<<temp->r<<","<<temp->c<<","<<temp->e<<")->";
                }
                temp=temp->next;
            }
            if(temp->e!=0)
            {   cout<<"("<<temp->r<<","<<temp->c<<","<<temp->e<<")->NULL";
            }
            else
            {   cout<<"NULL";
            }
        }
    }
    void array()
    {   node *temp=head->next;
        int arr[head->r][head->c];
        int i=0,j=0;
        for( i=0;i<head->r;i++)
        {   
            for( j=0;j<head->c;j++)
            {   
            	arr[i][j]=temp->e;
                temp=temp->next;
            }
        }
        for( i=0;i<head->r;i++)
        {   
        	for( j=0;j<head->c;j++)
                	cout<<arr[i][j]<<"   ";
                cout<<endl;
        }
    }
};
int main() {
    int row,coloumn;
    linkedlist l;
    cout<<"Enter the rows:"<<endl;
    cin>>row;
     cout<<"Enter the coloumns:"<<endl;
    cin>>coloumn;
    int a;
    l.push(row,coloumn,0);
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<row;i++)
    {   
    	for(int j=0;j<coloumn;j++)
        {   
        	cin>>a;
                l.push(i,j,a);
        }
    }
    l.display();
    cout<<endl;
    l.array();

    return 0;
}
