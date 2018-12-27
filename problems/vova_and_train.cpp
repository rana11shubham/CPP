#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
ll t,L,v,l,r;
cin>>t;
while(t--){
    cin>>L>>v>>l>>r;
    //vector<ll>a;
    cout<<(L/v)-((r/v)-(l-1)/v)<<endl;
}
return 0;
}
