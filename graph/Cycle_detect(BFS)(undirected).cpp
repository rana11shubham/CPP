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
        adj[v].push_back(u);
        }
    bool isconnected(int u,vector<bool>&visited){
        vector<int>parent(V,-1);
        list<int>queue;
        queue.push_back(u);
        visited[u]=true;
        while(!queue.empty()){

        int x=queue.front();
        queue.pop_front();
        for(auto it=adj[x].begin();it!=adj[x].end();it++){
            if(!visited[*it]){
                queue.push_back(*it);
                visited[*it]=true;
                parent[*it]=x;
            }
            else if(parent[x]!=*it){
                return true;
            }
        }

    }
    return false;
    }
    bool isdisconnected(){
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(isconnected(i,visited))
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
        g.isdisconnected()?cout<<"The cycle is present"<<endl:cout<<"The cycle is not present"<<endl;
        graph g1(3);
         g1.addEdge(0,1);
        g1.addEdge(1,2);
        g1.isdisconnected()?cout<<"The cycle is present"<<endl:cout<<"The cycle is not present"<<endl;
    return 0;
}
