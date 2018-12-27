#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class sol{
	bool isbalanced(string s){
		int cnt=0;
		for(char x:s){
		if(x=='(') cnt++;
		else if(x==')') cnt--;
		if(cnt<0)
		  return 0;
	}
	return cnt==0;
  }

public:
      map<string,bool>vis;
      vector<string>remove_paranth(string s){
      queue<string>Q;
      vector<string>ans;
      Q.push(s);
      int found=0;
      while(!Q.empty()){
      	string u=Q.front(); Q.pop();
      //	cout<<u<<endl;
      	if(vis[u]) continue;
      	vis[u]=1;
      	if(isbalanced(u)){ found=1; ans.push_back(u);}
      	if(found) continue;
      	for(int i=0;i<u.size();i++){
      		if(u[i]=='('||u[i]==')'){
      		   string t=u.substr(0,i)+u.substr(i+1,u.size());

      		   Q.push(t);
      		}
      	}
      	}
      	return ans;
      }
};
int main() {
	sol so;
	string s;
	cin>>s;
	vector<string>ans=so.remove_paranth(s);
	for(string curr:ans) cout<< curr <<endl;
	return 0;
}
