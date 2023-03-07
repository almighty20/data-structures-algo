#include "iostream"
using namespace std;
class queue
{
    public:
    int f,r, *arr,size;
    queue(int s)
    {
        size=s;
        f=-1;
        r=-1;
        arr=new int[size];
    }
    bool isEmpty()
    {
        return(r==-1);
    }
    bool isFull()
    {
        return(f==(r+1)%size);
    }
    void enqueue(int e)
    {
        if(!isFull())
        {
            if(r==-1)
            {
                f=0;
            }
            r=(r+1)%size;
            arr[r]=e;
        }
        else 
        {
            cout<<"Queue is full"<<endl;
        }
    }
    int dequeue()
    {
        int temp=-1;
        if(!isEmpty())
        {
            temp=arr[f];
            f=(f+1)%size;
            if(f==(r+1)%size)
            {
                f=-1; r=-1;
            }
        }
        return temp;
    }
    void display()
    {
        int front=f, rear=r;
        if(front==-1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Elements are : \n";
        if(front<=rear)
        {
            while(front<=rear)
            {
                cout<<arr[front]<<" ";
                front++;
            }

        }
        else{
            while(front<=size-1)
            {
                cout<<arr[front]<<" ";
                front++;
            }
            front=0;
            while(front<=rear)
            {
                cout<<arr[front]<<" ";
                front++;
            }
        }
        cout<<endl;
    }
   int peak()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else 
            return arr[0];
    }
    
};

int main()
{
    cout<<"Size of queue : "<<endl;
    int size,e,choice,x;
    cin>>size;
    queue a(size);
    cout<<"\n";
    cout<<"\n 1. Enqueue";
    cout<<"\n 2. Dequeue";
    cout<<"\n 3. Display";
    cout<<"\n 5. Peak";
    cout<<"\n 4. Exit"<<endl;
    cout<<"Enter choice : "<<endl;
    cin>>choice;
    while(choice!=4)
    {
        switch(choice)
        {
            case 1 : cout<<"Enter element : ";
                    cin>>e;
                    a.enqueue(e);
                    break;

            case 2 : cout<<"Deleted : "<<a.dequeue()<<endl; break;

            case 3 : a.display();
                    break;

            case 5 : a.peak(); break;
            case 4 :  break;
            default : cout<<"Invalid input"<<endl;
                    break;
        }
        cout<<"Enter choice : ";
        cin>>choice;
    }
    return 0;
}