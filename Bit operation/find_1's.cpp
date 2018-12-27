
#include<bits/stdc++.h>
using namespace std;
int main(void) {
	// your code goes here
	int x;
	cin>>x;
	int sum=0;
	while(x>0){
		sum+=x&&1;
		x>>=1;
	}
	cout<<sum;
	return 0;
}
