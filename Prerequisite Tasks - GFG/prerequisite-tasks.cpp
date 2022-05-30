// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int>vis(N,0);
	    vector<int>indegree(N,0);

	    unordered_map<int,vector<int>>mp;
	    for(auto it:prerequisites){
	        indegree[it.second]++;
	        mp[it.first].push_back(it.second);
	    }
	    int cnt=0;
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	            if(indegree[i]==0){
	   
	            queue<int>q;
	            q.push(i);
	            vis[i]=1;
	            while(!q.empty()){
	                auto it=q.front();
	                q.pop();
	                cnt++; 
	                for(auto u: mp[it]){
	                    if(!vis[u]){
	                        vis[u]=1;
	                    }       
	                    indegree[u]--;
	                    if(indegree[u]==0)
	                    {
	                        q.push(u);
	                    }
	                }
	            }
	        }
	    }
	  //  cout<<cnt<<endl;
	   
	}
	 return cnt==N;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends