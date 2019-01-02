#include<bits/stdc++.h>
using namespace std;
#define edge pair<int,int>
class graph{
    int V;
    int E;
    vector<pair<int,edge> >G;
public:
    graph(int V,int E){
    this->V=V;
    this->E=E;
    }
    void addEdge(int u,int v,int w){
    G.push_back(make_pair(w,edge(u,v)));
    }
    void print(vector<int> &dist){
        cout<<"Vertex "<<"  "<<"Distance"<<endl;
        for(int i=0;i<V;i++){
        cout<<i <<"       "<<dist[i]<<endl;
        }
    }
    void bellman(int src){
    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    for(int i=0;i<=V-1;i++){
        for(int v=0;v<E;v++){
            int u=G[v].second.first;
            int w=G[v].second.second;
            if(dist[u]!=INT_MAX && dist[u]+G[v].first<dist[w]){
                dist[w]=dist[u]+G[v].first;
            }
        }
    }
    for(int i=0;i<E;i++){
        int u=G[i].second.first;
        int v=G[i].second.second;
        int w=G[i].first;
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            cout<<"The negative cycle exists \n";
        }
    }
    print(dist);
    }

};

int main(){
    int V=5,E=8;
    graph g(V,E);
    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);
    g.bellman(0);
return 0;
}
