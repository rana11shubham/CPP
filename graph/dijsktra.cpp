#include<bits/stdc++.h>
using namespace std;
#define V 9
int mindistance(int dist[],bool sptSet[]){
    int mini=INT_MAX;
    int index;
    for(int i=0;i<V;i++){
        if(dist[i]<mini &&sptSet[i]==false){
            mini=dist[i];
            index=i;
        }
    }
    return index;
}
void print(int dist[]){
    for(int i=0;i<V;i++){
        cout<<i <<":"<< dist[i]<<endl;
    }

}
void primMst(int G[V][V],int src){
    int dist[V];
    bool sptSet[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int u=mindistance(dist,sptSet);
        sptSet[u]=true;
        for(int v=0;v<V;v++){
            if(G[u][v]&& sptSet[v]==false &&dist[u]!=INT_MAX &&dist[v]>G[u][v]+dist[u]){
                dist[v]=G[u][v]+dist[u];
            }
        }
    }
    print(dist);
}
int main(){
int graph[V][V] =  {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    primMst(graph,0);

return 0;
}
