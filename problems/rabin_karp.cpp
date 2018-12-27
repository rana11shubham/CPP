#include <iostream>
#include<bits/stdc++.h>
#define q 101
#define ll long long int
using namespace std;


int main() {
	string s,t;
	cin>>s>>t;
	ll n1=s.length();
	ll n2=t.length();

	ll h=1;
	for(int i=0;i<n2-1;i++){
		h=(h*256)%q;
	}
	ll t1=0;
	ll p=0;

	for(int i=0;i<n2;i++){
		p=(256*p+t[i])%q;
		t1=(t1*256+s[i])%q;

	}
	//cout<<p<<""<<t1<<endl;

	for(int ss=0;ss<=n1-n2;ss++){
		if(p==t1){
			int j;
			for(j=0;j<n2;j++){
				if(s[ss+j]!=t[j]){

					break;
				}

			}
				if(j==n2){
					cout<<"String found at shift "<<ss<<endl;

				}


		}
		if(ss<n1-n2){
			t1=(256*(t1-s[ss]*h)+s[ss+n2])%q;
			//cout<<t1<<endl;

		    if(t1<0){
				t1=t1+q;
				//cout<<t1<<endl;

		}
	}
	}

	return 0;
}
