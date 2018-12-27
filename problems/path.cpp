#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1003;
int a[N][N],dp[N][N],vis[N][N],n,m;
int go(int i,int j){
    if(i==n-1 && j==m-1)
        return a[i][j];
        if(vis[i][j])
            return dp[i][j];
        vis[i][j]=1;
    int& ans=dp[i][j];
    if(i<n-1 && j<m-1)
        ans=a[i][j]+std::max(go(i,j+1),go(i+1,j));
    else if(i==n-1)
        ans=a[i][j]+go(i,j+1);
    else
        ans=a[i][j]+go(i+1,j);
    return ans;
}
int main(){
cin>>n>>m;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
}
cout<<go(0,0)<<endl;
}
