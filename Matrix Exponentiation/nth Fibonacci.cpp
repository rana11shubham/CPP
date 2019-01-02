#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void mul(ll a[3][3],ll b[3][3]){
    ll c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=0;
            for(int k=0;k<3;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j]=c[i][j];
        }
    }
}
ll power(ll f[3][3],ll n){
    ll mull[3][3]={{1,1,0},{1,0,0},{0,1,0}};
    if(n==1)
        return f[0][0]+f[0][1];
    power(f,n/2);
    mul(f,f);
    if(n%2!=0){
        mul(f,mull);
    }
    return f[0][0]+f[0][1];
}
ll fib(ll n){
    ll f[3][3]={{1,1,0},{1,0,0},{0,1,0}};
    ll ans=power(f,n-2);
    return ans;
}
int main(){
    ll n;
    cin>>n;
    ll ans=fib(n);
    cout<<ans<<endl;
    return 0;
}
