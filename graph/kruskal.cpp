#include<bits/stdc++.h>
using namespace std;
#define edge pair<int,int>
class graph{
    int V;
    vector<pair<int,edge> >G;
    vector<pair<int,edge> >mst;
    int *parent;
public:
    graph(int V){
    this->V=V;
    parent=new int[V];
    for(int i=0;i<V;i++)
        parent[i]=i;
    }
    void AddWeightedEdge(int u,int v,int w){
    G.push_back(make_pair(w,edge(u,v)));
    }
    int find_set(int i){
    if(i==parent[i]){
        return i;
    }
    return find_set(parent[i]);
    }
    void union_set(int i,int j){
    parent[i]=parent[j];
    }
    void kruskal(){
     int i,uRep,vRep;
    sort(G.begin(),G.end());
    /*for(int i=0;i<G.size();i++){
        cout<<G[i].first<<" "<<G[i].second.first<<" "<<G[i].second.second<<endl;
    }*/
    for(int i=0;i<G.size();i++){
        uRep=find_set(G[i].second.first);
        vRep=find_set(G[i].second.second);
        if(uRep!=vRep){
            mst.push_back(G[i]);
            union_set(uRep,vRep);
        }
    }
    }
    void print(){
     cout<<"Edge: "<<"Weight"<<endl;
    for(int i=0;i<mst.size();i++){
        cout<<mst[i].second.first<<"-"<<mst[i].second.second<<" ";
        cout<<mst[i].first<<endl;
    }
    /*for(int i=0;i<V;i++)
        cout<<parent[i]<<" "; */
    }
};
int main(){
     graph g(4);
    g.AddWeightedEdge(0, 1, 10);
    g.AddWeightedEdge(0, 2, 6);
    g.AddWeightedEdge(0, 3, 5);
    g.AddWeightedEdge(1, 3, 15);
    g.AddWeightedEdge(2, 3, 4);
   /* g.AddWeightedEdge(2, 1, 2);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 2, 3);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(4, 2, 4);
    g.AddWeightedEdge(4, 3, 3);
    g.AddWeightedEdge(5, 2, 2);
    g.AddWeightedEdge(5, 4, 3); */
    g.kruskal();
    g.print();
    return 0;
}
