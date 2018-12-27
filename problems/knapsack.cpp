#include<bits/stdc++.h>

using namespace std;
int main(){
    int W,n;
    cout<<"Enter the knapsack bag capacity and no of items"<<endl;
    cin>>W>>n;
    int wt[n],v[n];
    cout<<"Enter the weights of items"<<endl;;
    for(int i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter the profits of items"<<endl;
    for(int i=0;i<n;i++)
        cin>>v[i];
    int k[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0){
                k[i][j]=0;
            }
            else if(j>=wt[i-1]){
                k[i][j]=max(v[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
            }
            else{
                k[i][j]=k[i-1][j];
            }
        }
    }
    cout<<"The max profit is : "<<k[n][W];
    return 0;
}
