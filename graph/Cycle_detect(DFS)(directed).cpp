#include<bits/stdc++.h>
using namespace std;
class graph{
    int V;
    vector<int>*adj;
public:
    graph(int V){
    this->V=V;
    adj=new vector<int>[V];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    bool iscycleUtil(int u,vector<bool>&visited,vector<bool>&vis_stack){
        if(visited[u]==false){
        visited[u]=true;
        vis_stack[u]=true;
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            if(!visited[*it]){
                if(iscycleUtil(*it,visited,vis_stack)){
                    return true;
                }
            }
            else if(vis_stack[*it]){
                return true;
            }
        }
        return false;
    }
     vis_stack[u]=false;
     return false;
}
    bool iscycle(){
    vector<bool>visited(V,false);
    vector<bool>vis_stack(V,false);
    for(int i=0;i<V;i++){
        if(!(visited[i])){
            if(iscycleUtil(i,visited,vis_stack)){
                return true;
            }
        }
    }
    return false;
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
    g.iscycle()?cout<<"Cycle is present\n":cout<<"Cycle is not present\n";
    graph g1(4);
    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,0);
    g1.iscycle()?cout<<"Cycle is present\n":cout<<"Cycle is not present\n";
    return 0;
    }
