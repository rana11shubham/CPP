//T(n)=2*T(n-1)+3*T(n-2)
//T(0)=1,T(1)=1
//for n=3 T(n)=13

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void mul(ll a[2][2],ll b[2][2]){
    ll m[2][2];
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            m[i][j]=0;
            for(ll k=0;k<2;k++){
                m[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            a[i][j]=m[i][j];
        }
    }
}
ll go(ll n,ll m[2][2]){
    ll f[2][2]={{2,3},{1,0}};
    if(n==1)
        return m[0][0]+m[0][1];
    go(n/2,m);
    mul(m,m);
    if(n%2!=0)
        mul(m,f);
    return m[0][0]+m[0][1];
}
ll term(ll n){
    ll m[2][2]={{2,3},{1,0}};
    return go(n-1,m);
}
int main(){
    ll n;
    cin>>n;
    cout<<term(n)<<endl;
    return 0;
}
