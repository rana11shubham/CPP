
#include<bits/stdc++.h>
using namespace std;
int sum(int x,int y){
    if(y==0)
        return x;
    int a=x^y;
    int par_sum=x&y;
    par_sum <<=1;
    cout<<par_sum<<endl;
    return sum(a,par_sum);

}
int main(void) {
	// your code goes here
	int x,y;
	cin>>x>>y;
	int sum1=sum(x,y);
	cout<<sum1;
	return 0;
}
