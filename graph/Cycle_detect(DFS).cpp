#include<bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list<int>*adj;
public:
    graph(int V){
    this->V=V;
    adj=new list<int>[V];
    }
    void addEdge(int u,int v){
        if(u>V ||u<0 ||v>V ||v<0)
            cout<<"It exceeds the value of vertex!!"<<endl;
        else{
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
    }
     bool iscycleUtil(int u,bool visited[],int parent){
        visited[u]=true;
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            if(!visited[*it]){
                iscycleUtil(*it,visited,u);
            }
            else if(*it!=parent)
                return true;
        }
        return false;
    }
     bool iscycle(){
        bool*visited=new bool[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(iscycleUtil(i,visited,-1))
                return true;
                }
            }
     return false;
     }
};

     int main(){
        int V=4;
        graph g(5);
        g.addEdge(0,1);
        g.addEdge(0,2);
        g.addEdge(1,2);
        g.addEdge(2,3);
        g.iscycle()?cout<<"The cycle is present"<<endl:cout<<"The cycle is not present"<<endl;
        graph g1(3);
        g1.addEdge(0,1);
        g1.addEdge(1,2);
        g1.iscycle()?cout<<"The cycle is present"<<endl:cout<<"The cycle is not present"<<endl;
        return 0;
        }
