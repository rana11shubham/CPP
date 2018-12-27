#include<bits/stdc++.h>
using namespace std;
int main(){
   string a,b;
   getline(cin,a);
   getline(cin,b);
   int m=a.length();
   int n=b.length();
  // cout<<m;
   for(int i=0;i<=m-n;i++){
     int j=0;
     while(j<n && a[i+j]==b[j]){
        j++;
     }
     if(j>n-1){
            cout<<"Pattern found at "<<i<<endl;
   }
   else{
        cout<<"No valid Shift found at "<<i<<endl;
         continue;
   }
}
return 0;
}
