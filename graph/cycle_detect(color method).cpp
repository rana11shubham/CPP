#include<bits/stdc++.h>
using namespace std;
enum Color {White,Grey,Black};
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
    bool iscycleUtil(int u,vector<int>&color){
        color[u]=Grey;
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            if(color[*it]==White && iscycleUtil(*it,color)){
                return true;
            }
            else if(color[*it]==Grey){
                return true;
            }
        }
        color[u]=Black;
        return false;
    }
    bool iscycle(){
    vector<int>color(V,White);
    for(int i=0;i<V;i++){
        if(color[i]==White && iscycleUtil(i,color)){
            return true;
        }
    }
    return false;
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
    if(g.iscycle())
        cout<<"Cycle is present\n";
    else cout<<"Cycle is not present\n";
    return 0;
}
