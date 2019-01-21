#include<bits/stdc++.h>
#define mod 11
using namespace std;
int mod_inverse(int n,int p){
        int res=1;
        n=n%mod;
        while(p>0){
            if(p&1!=0){
                res=res*n%mod;
                }
            p=p>>1;
            n=n*n%mod;
            }
        return res;
    }
int comp(int n){
    return mod_inverse(n,mod-2);
    }
int power(int n,int k){
    if(k==0)
        return 1;
    int fact[n+1];
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=i*fact[i-1]%mod;
    }
    int result=fact[n]*comp(fact[k])*comp(fact[n-k])%mod;
    return result;
    }
//-------------------------------------------------------------------------------------------
int main(){
    int n,k;
    cin>>n>>k;
    int result=power(n,k);
    cout<<result<<endl;
    return 0;
    }
