#include<bits/stdc++.h>
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL),cout.tie(NULL);

using namespace std;
const int size= 1e7;
int balance[size];
int main(){
	fio
	int n,m,u,v,w;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	       cin>>u>>v>>w;
	       balance[u]-=w;
	       balance[v]+=w;
	}
	multiset<int>s;
	for(int i=0;i<n;i++){
		if(balance[i]!=0)
		   s.insert(balance[i]);
	}
	int count=0;
	while(!s.empty()){
		int poor=*s.begin(); s.erase(s.begin());
		int rich=*s.rbegin(); s.erase(prev(s.end()));
		int amt=min(-poor,rich);
		count++;
		poor+=amt;
		rich-=amt;
		if(poor) s.insert(poor);
		if(rich) s.insert(rich);

	}
	cout<<count<<endl;
	return 0;
}
