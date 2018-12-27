#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
 int a[5][5],ans1=0,ans2=0;
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++)
    {
        cin>>a[i][j];
        if(a[i][j]==1){
             ans1=abs(2-i);
             ans2=abs(2-j);
        }
    }
}

cout<<ans1+ans2;
return 0;
}
