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
        adj[u].push_back(v);
    }
     void DFSutil(int u,bool visited[]){
        visited[u]=true;
        cout<<u<<" ";
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            if(!visited[*it]){
                DFSutil(*it,visited);
               }
        }
    }
     void DFS(){
        bool *visited=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        for(int i=0;i<V;i++){
            if(visited[i]==false)
                DFSutil(i,visited);
        }
    }
};
int main(){
   int V=4;
    graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS();
    return 0;
}
