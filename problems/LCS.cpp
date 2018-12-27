#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int n1=a.length();
    int n2=b.length();
    int c[n1+1][n2+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0)
             c[i][j]=0;
             else if(a[i-1]==b[j-1]){
                c[i][j]=c[i-1][j-1]+1;
             }
             else if(c[i-1]<=c[j-1]){
                c[i][j]=c[i][j-1];
             }
             else{
                c[i][j]=c[i-1][j];
             }
        }
    }
            cout<<"The length of LCS is :"<<c[n1][n2];
     return 0;
}
