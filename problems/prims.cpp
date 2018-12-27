#include<bits/stdc++.h>
using namespace std;
int V=5;
int min_key(int key[],bool MST[]){
    int q=INT_MAX,ind;
    for(int v=0;v<V;v++){
        if(MST[v]==false && key[v]<q){
            q=key[v];ind=v;
        }
    }
    return ind;
}
void printMST(int graph[V][V],int parent[]){
    for(int i=1;i<V;i++){
        cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
}
void primMST(int graph[V][V]){
    int key[V];
    int parent[V];
    bool MST[V];
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        MST[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<V-1;i++){
        int u=min_key(key,MST);
        MST[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v] &&key[u]>graph[u][v] &&MST[v]==false){
                parent[v]=u;
                key[u]=graph[u][v];
            }
        }
    }
    printMST(graph,parent);
}
int main(){
   int graph[V][V] = {{0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0}};

   primMST(graph);
return 0;
}
