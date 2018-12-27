#include<bits/stdc++.h>
using namespace std;
class graph{
private:
    int V;
    list<int>*adj;
public:
    graph(int V){
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int u,int w){
        adj[u].push_back(w);
    }
    void bfs(int s){
        list<int>queue;
        bool *visited=new bool[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
        queue.push_back(s);

        visited[s]=true;
        while(!queue.empty()){
            s=queue.front();
            cout<<s<<" ";
            queue.pop_front();
            for(auto a=adj[s].begin();a!=adj[s].end();a++){
                if(!visited[*a]){
                    visited[*a]=true;
                    queue.push_back(*a);
                }
            }
        }
    }

};
int main(){

    int V=5;
     graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.bfs(2);
 return 0;
}
