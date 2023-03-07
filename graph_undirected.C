#include "iostream"
using namespace std;
class metro
{	
	public:
	int id;
	string sname;
	metro(int a,string b)
	{	id =a;
		sname = b;
	}
};
class queue
{	public:
	int *arr,end,n;
	queue(int s)
	{	n=s;
		arr= new int[n];
		end=0;
	}
	bool isfull()
	{	return (n==end);
	}
	bool isempty()
	{	return (end==0);
	}
	void enqueue(int e)
	{	if(isfull())
		{	cout<<"Queue overflow";
			return;
		}
		else
		{	arr[end]=e;
			end++;	
		}
	}
	int dequeue()
	{	if(isempty())
		{	cout<<"Queue underflow";
			return -1;
		}
		else
		{	int e=arr[0];
			for(int i=1;i<end;i++)
			{	arr[i-1]=arr[i];
			}	
			end--;
			return e;
		}
	}
};
class graph
{	public:
	int map[100][100];
	metro * m[100];
	int count;
	graph()
	{	count=0;
		for(int i=0;i<100;i++)
		{	for(int j=0;j<100;j++)
			{	map[i][j]=0;
			}		
			m[i]=NULL;
		}
	}
	int findstation(int id)
	{	for(int i=0;i<count;i++)
		{	if(m[i]->id==id)
			{	return i;
			}	
		}
		return -1;
	}
	int addstation(int id,string name)
	{	if(count>=100)
		{	return 1;
		}
		m[count]=new metro(id,name);
		count++;
		return 0 ;
	}
	int removestation(int id)
	{	if(count==0)
		{	return 1;
		}
		int m1=findstation(id);
		delete m[m1];
		int i;
		for(i=m1+1;i<count;i++)
		{	m[i-1]=m[i];
		}
		m[i]=NULL;
		for(int i=m1+1;i<count;i++)
		{	for(int j=0;j<count;j++)
			{	map[i-1][j]=map[i][j];
			}
		}
		for(int i=m1+1;i<count;i++)
		{	for(int j=0;j<count;j++)
			{	map[j][i-1]=map[i][j];
			}
		}
		count--;
		return 0;
	}
	int addlink(int id1,int id2)
	{	int s1=findstation(id1);
		int s2=findstation(id2);
		map[s1][s2]=1;
		map[s2][s1]=1;
	}
	int removelink(int id1,int id2)
	{	int s1=findstation(id1);
		int s2=findstation(id2);
		map[s1][s2]=0;
		map[s2][s1]=0;
	}
	void bfs(int id)
	{	queue q(count);
		bool visited[count];
		for(int i=0;i<count;i++)
		{	visited[i]=false;
		}
		int ind = findstation(id);
		q.enqueue(ind);
		while(!q.isempty())
		{	int id=q.dequeue();
			cout<<id;
			visited[ind]=true;
			for(int i=0;i<count;i++)
			{	if(map[ind][i]==1 && visited[i]==false)
				{	q.enqueue(i);
				}
			}
		}
	}
	
	int sp(int s, int d){
        queue q(count);
        bool visited[count];
        int level[count];
        for(int i=0; i<count; i++){
            visited[i] = false;
            level[i] = 0;
        }

        int ind = findstation(s);
        q.enqueue(ind);
        visited[ind] = true;
        while(!q.isempty()){
            ind = q.dequeue();
            for(int i=0; i<count; i++){
                if(map[ind][i] == 1 && visited[i] == false){
                    q.enqueue(i);
                    visited[i] = true;
                    level[i] = level[ind] + 1;
                }
            }
        }
        d = findstation(d);
        cout<<endl;
        return level[d] - 1;
	}
};
int main()
{	graph g;	
	int choice,id,id1,id2,i;
	string name;
	cout<<"Enter 1 to add a station."<<endl;
	cout<<"Enter 2 to remove a station."<<endl;
	cout<<"Enter 3 to add a link."<<endl;
	cout<<"Enter 4 to remove a link."<<endl;
	cout<<"Enter 5 to find a station."<<endl;
	cout<<"Enter 6 to for bfs."<<endl;
	cout<<"Enter 7 to to sp."<<endl;
	cout<<"Enter 8 to to quit."<<endl;
	cout<<"Enter your choice."<<endl;
	cin>>choice;
	while(choice!=8)
	{	switch(choice)
		{	case 1:
				cout<<"Enter the id of the station."<<endl;
				cin>>id;
				cout<<"Enter the name of the station."<<endl;
				cin>>name;
				g.addstation(id,name);
				break;
			case 2:
				cout<<"Enter the id of the station."<<endl;
				cin>>id;
				g.removestation(id);
				break;
			case 3:
				cout<<"Enter the id of the first station."<<endl;
				cin>>id1;
				cout<<"Enter the id of the second station."<<endl;
				cin>>id2;
				g.addlink(id1,id2);
				break;
			case 4:
				cout<<"Enter the id of the first station."<<endl;
				cin>>id1;
				cout<<"Enter the id of the second station."<<endl;
				cin>>id2;
				g.removelink(id1,id2);
				break;
			case 5:
				cout<<"Enter the id of the station."<<endl;
				cin>>id1;
				i=g.findstation(id1);
				cout<<"The station found at: "<<i;
				break;
			case 6:
				cout<<"Enter the id of the station."<<endl;
				cin>>id1;
				g.bfs(id1);
			case 7:
				cout<<"Enter the id of the station."<<endl;
				cin>>id1;
				cout<<"Enter the id of the second station."<<endl;
				cin>>id2;
				cout<<g.sp(id1,id2);
				
			default:
				cout<<"Enter the correct choice"<<endl;
				break;
		}
	cout<<"Enter your choice"<<endl;
	cin>>choice;
	}	
return 0;
}
