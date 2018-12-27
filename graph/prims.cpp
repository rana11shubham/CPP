#include<bits/stdc++.h>
using namespace std;
#define V 5
int min_key(int key[],bool mstSet[]){
    int mini=INT_MAX;
    int index;
    for(int i=0;i<V;i++){
        if(key[i]<mini &&mstSet[i]==false){
            mini=key[i];
            index=i;
        }
    }
    return index;
}
void print(int G[V][V],int parent[],int key[]){
    for(int i=1;i<V;i++){
        cout<<parent[i]<<"-"<<i<<" "<<G[i][parent[i]]<<endl;
    }

}
void primMst(int G[V][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<V-1;i++){
        int u=min_key(key,mstSet);
        mstSet[u]=true;
        for(int v=0;v<V;v++){
            if(G[u][v]&&mstSet[v]==false && key[v]>G[u][v]){
                key[v]=G[u][v];
                parent[v]=u;
            }
        }
    }
    print(G,parent,key);
}
int main(){
int graph[V][V] = {{0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0}};

    primMst(graph);

return 0;
}
