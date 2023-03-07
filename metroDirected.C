#include "iostream"
#include "string.h"
using namespace std;

class Stack{
	public:
	int top;
	int *arr;
	int size;

	Stack(int s){
		size = s;
		top = 0;
		arr = new int[size];
	}

	
	bool isEmpty(){
		return (top==0);
	}

	bool isFull(){
		return (top==size);
	}

	void push(int e){
		if(isFull()){
			cout<<"Stack Overflow"<<endl;
			return;
		}
		arr[top] = e;
		top++;
	}

	int pop(){
		if(isEmpty()){
			cout<<"Stack Underflow"<<endl;
			return -1;
		}
		top--;
		return arr[top];
	}

	int peek(){
		if(isEmpty()){
			cout<<"Stack Underflow"<<endl;
			return -1;
		}
		return arr[top-1];
	}	

	void display(){
		if(isEmpty()){
			cout<<"Stack Empty"<<endl;
			return;
		}
		for(int i=top-1; i>=0; i--){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

class Queue{
	public:
	int end;
	int *arr;
	int size;

	Queue(int Q){
		size = Q;
		end = 0;
		arr = new int[size];
	}

	
	bool isEmpty(){
		return (end==0);
	}

	bool isFull(){
		return (end==size);
	}

	void enqueue(int e){
		if(isFull()){
			cout<<"Queue Overflow"<<endl;
			return;
		}
		arr[end] = e;
		end++;
	}

	int dequeue(){
		if(isEmpty()){
			cout<<"Queue Underflow"<<endl;
			return -1;
		}
		
		int ele = arr[0];
		for(int i=1; i<=end;i++){
			arr[i-1] = arr[i];
		}
		end--;
		
		return ele;
	}

	int peek(){
		if(isEmpty()){
			cout<<"Queue Empty"<<endl;
			return -1;
		}
		return arr[0];
	}

	void display(){
		if(isEmpty()){
			cout<<"Queue Empty"<<endl;
			return;
		}
		for(int i=0; i<end; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

class Station{
    public:
    int id;
    string name;

    Station(int id, string name){
        this->id = id;
        this->name = name;
    }
};

class metroMap{
    public:
    int map[10][10];
    Station *s[10];
    int count;

    metroMap(){
        count = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                map[i][j] = 0;
            }
            s[i] = NULL;
        }
    }

    int findStation(int id){
        for(int i=0; i<count; i++){
            if(s[i]->id == id)
                return i;
        }
        return -1;
    }

    void display(){
        cout<<"Here's the metro map :-"<<endl;
        cout<<"  ";
        for(int i=0; i<10; i++){
            cout<<i+1<<" ";
        }
        cout<<endl;
        for(int i=0; i<10; i++){
            cout<<i+1<<"|";
            for(int j=0; j<10; j++){
                cout<<map[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int addNode(int id, string name){
        if(count >= 10)
            return 1;
        s[count] = new Station(id, name);
        count++;
        display();
        return 0;
    }

    int removeNode(int id){
        int s1 = findStation(id);
        if(count == 0 || s1 == -1)
            return 1;
        int i = s1 + 1;
        for(;i<count; i++){
            s[i-1] = s[i];
        }
        s[i] = NULL;
        for(int i = s1+1; i<count; i++){
            for(int j=0; j<count; j++){
                cout<<"i = "<<i<<endl;
                cout<<"j = "<<j<<endl;
                map[i-1][j] = map[i][j];
            }
        }
        for(int i = s1+1; i<count; i++){
            for(int j=0; j<count; j++){
                map[j][i-1] = map[j][i];
            }
        }
        for(int i = 0; i<10; i++){
            map[i][count-1] = 0;
            map[count-1][i] = 0;
        }
        count--;
        display();
        return 0;
    }

    int addConn(int id1, int id2, int cost){
        int s1 = findStation(id1);
        int s2 = findStation(id2);
        if(s1 == -1 || s2 == -1){
            return 1;
        }
        map[s1][s2] = cost;
        display();
        return 0;
    }

    int removeConn(int id1, int id2){
        int s1 = findStation(id1);
        int s2 = findStation(id2);
        if(s1 == -1 || s2 == -1){
            return 1;
        }
        map[s1][s2] = 0;
        display();
        return 0;
    }

    void bfs(int id){
        Queue q(count);
        bool visited[count];
        for(int i=0; i<count; i++){
            visited[i] = false;
        }
        int ind = findStation(id);
        cout<<"Breadth First Search :-"<<endl;
        q.enqueue(ind);
        visited[ind] = true;
        while(!q.isEmpty()){
            ind = q.dequeue();
            cout<<s[ind]->id<<" ";
            for(int i=0; i<count; i++){
                if(map[ind][i] > 0 && !visited[i]){
                    q.enqueue(i);
                    visited[i] = true;
                }
            }
        }
        cout<<endl;
    }

    void dfs(int id){
        Stack S(count);
        bool visited[count];
        for(int i=0; i<count; i++){
            visited[i] = false;
        }
        int ind = findStation(id);
        cout<<"Depth First Search :-"<<endl;
        S.push(ind);
        visited[ind] = true;
        while(!S.isEmpty()){
            ind = S.pop();
            cout<<s[ind]->id<<" ";
            for(int i=0; i<count; i++){
                if(map[ind][i] > 0 && !visited[i]){
                    S.push(i);
                    visited[i] = true;
                }
            }
        }
        cout<<endl;
    }

    int sp(int s, int d){
        Queue q(count);
        bool visited[count];
        int level[count];
        for(int i=0; i<count; i++){
            visited[i] = false;
            level[i] = 0;
        }

        int ind = findStation(s);
        q.enqueue(ind);
        visited[ind] = true;
        while(!q.isEmpty()){
            ind = q.dequeue();
            for(int i=0; i<count; i++){
                if(map[ind][i] > 0 && visited[i] == false){
                    q.enqueue(i);
                    visited[i] = true;
                    level[i] = level[ind] + 1;
                }
            }
        }
        d = findStation(d);
        cout<<endl;
        return level[d] - 1;
    }

    int inDegree(int id){
        int ind = findStation(id);
        int degree = 0;
        for(int i=0; i<count; i++){
            if(map[i][ind] > 0){
                degree++;
            }
        }
        return degree;
    }

    int outDegree(int id){
        int ind = findStation(id);
        int degree = 0;
        for(int i=0; i<count; i++){
            if(map[ind][i] > 0){
                degree++;
            }
        }
        return degree;
    }

    int findZeroDegreeNode(int cind[], bool visited[]){
        for(int i = 0; i<count; i++){
            if(cind[i] == 0 && !visited[i]){
                return i;
            }
        }
        return -1;
    }

    int topo_sort(int seq[]){
        int cind[count];
        for(int i=0; i<count; i++){
            cind[i] = inDegree(s[i]->id);
        }
        cout<<endl;
        int traversed = 0;
        bool visited[count];
        for(int i=0; i<count; i++){
            visited[i] = false;
        }
        while(traversed != count){
            int id = findZeroDegreeNode(cind, visited);
            if(id == -1){
                return 1;
            }
            visited[id] = true;
            seq[traversed++] = s[id]->id;
            for(int i=0; i<count; i++){
                if(map[id][i] > 0){
                    cind[i]--;
                }
            }
        }
        return 0;
    }

    int findMinNode(int cost[], bool visited[]){
        int min = 1000, minNode = -1;
        for(int i = 0; i<count; i++){
            if(min > cost[i] && !visited[i]){
                min == cost[i];
                minNode = i;
            }
        }
        return minNode;
    }

    int djikstras(int s, int d, int path[]){
        s = findStation(s);
        d = findStation(d);
        int parent[count];
        int cost[count];
        bool visited[count];
        for(int i=0; i<count; i++){
            parent[i] = -1;
            cost[i] = 1000;
            visited[i] = false;
        }
        cost[s] = 0;

        int traversed = 0, id = s;
        while(traversed != count){
            for(int i=0; i<count; i++){
                if(map[id][i] > 0 && !visited[i]){
                    int cc = cost[id] + map[id][i];
                    if(cc < cost[i]){
                        cost[i] = cc;
                        parent[i] = id;
                    }
                }
            }
            visited[id] = true;
            id = findMinNode(cost, visited);
            traversed++;
        }
        int k = 0;
        id = d;
        while(id != -1){
            path[k++] = id;
            id = parent[id];
        }
        return cost[d];
    }
};

int main(){
    int ch = 0;
    int id = 1;
    metroMap M;

    string name;
    int id1, id2, cost;
    int seq[M.count];
    while(ch != -1){
        cout<<"1. Add a Station\n2. Remove a Station\n3. Add a connection\n4. Remove a connect\n5. Display\n6. BFS\n7. DFS\n8. Minimum no. of stations between 2 stations\n9. Degree of a station\n10. Topological Sort\n11. 10. Shortest path(Djikstra's Algorithm)"<<endl;
        cout<<"Enter -1 to exit"<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Station ID is "<<id<<endl;
                cout<<"Enter Station name: ";
                cin>>name;
                M.addNode(id++, name);
                break;
            
            case 2:
                cout<<"Enter Station ID to be removed: ";
                cin>>id1;
                M.removeNode(id1);
                break;

            case 3:
                cout<<"Enter 1st ID: ";
                cin>>id1;
                cout<<"Enter 2nd ID: ";
                cin>>id2;
                cout<<"Enter cost of path: ";
                cin>>cost;
                M.addConn(id1, id2, cost);
                break;

            case 4:
                cout<<"Enter 1st ID: ";
                cin>>id1;
                cout<<"Enter 2nd ID: ";
                cin>>id2;
                M.removeConn(id1, id2);
                break;
            
            case 5:
                M.display();
                break;

            case 6:
                cout<<"Enter BFS source: ";
                cin>>id1;
                M.bfs(id1);
                break;

            case 7:
                cout<<"Enter DFS source: ";
                cin>>id1;
                M.dfs(id1);
                break;

            case 8:
                cout<<"Enter source: ";
                cin>>id1;
                cout<<"Enter destination: ";
                cin>>id2;
                cout<<"No. of minimum stations in between: "<<M.sp(id1, id2)<<endl;
                break;

            case 9:
                cout<<"Enter station ID for degree: ";
                cin>>id1;
                cout<<"inDegree: "<<M.inDegree(id1)<<endl;
                cout<<"outDegree: "<<M.outDegree(id1)<<endl;
                break;
            
            case 10:
                for(int i=0; i<M.count; i++){
                    seq[i] = 0;
                }
                M.topo_sort(seq);
                cout<<"Topological sort is :-"<<endl;
                for(int i=0; i<M.count; i++){
                    cout<<seq[i]<<" ";
                }
                cout<<endl<<endl;
                break;
            case 11:
                for(int i=0; i<M.count; i++){
                    seq[i] = 0;
                }
                cout<<"Enter source: ";
                cin>>id1;
                cout<<"Enter destination: ";
                cin>>id2;
                cout<<"Shortest distance is: "<<M.djikstras(id1, id2, seq)<<endl<<endl;
                break;
        }
    }
    return 0;
}
