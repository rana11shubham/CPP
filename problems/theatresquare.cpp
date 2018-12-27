#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
 double n,m,a;
cin>>n>>m>>a;
ll count1=ceil(n/a);
ll count2=ceil(m/a);
cout<<count1*count2;
return 0;
}
