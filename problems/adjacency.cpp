#include<bits/stdc++.h>
#define fo(i,v) for(i=0;i<v;i++)
#define pb(u) push_back(u);
using namespace std;
const int v=5;
vector<int>dp[v];
void add_edge(int u,int w){
    dp[u].pb(w);
    dp[w].pb(u);
}

int main(){
    int w[v],n[v],i;

    fo( i,v){
        cin>>w[i]>>n[i];
        add_edge(w[i],n[i]);
}
fo(i,v){
    cout<<i<<" :"<<" ";
for(auto x:dp[i])
    cout<<x<<endl;
}
return 0;
}
