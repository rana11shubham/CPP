#include<bits/stdc++.h>
using namespace std;
#define x 1000
vector<int>adj[x];
int a[x];
int dp[x+1]={0};
vector<bool>visited(x,false);
void dfs(int u){
    dp[u]=a[u];
    int mx=0;
    visited[u]=true;
    for(auto child:adj[u]){
            if(visited[child]) continue;
        if(!visited[child]){
            dfs(child);
            mx=max(mx,dp[child]);
           // cout<<mx<<endl;
        }
    }
    dp[u]+=mx;

}
int main(){
    int n,e;
    cin>>n;
    int u,v;
   // int a[n];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    cout<<dp[1]<<endl;
    return 0;
}
