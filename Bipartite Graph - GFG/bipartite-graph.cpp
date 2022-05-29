// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>vis(V,0);
	    vector<int>col(V,-1);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            queue<pair<int,int>>q;
	            q.push({i,0});// Assigning white color
	            vis[i]=1;
	            col[i]=0;
	            while(!q.empty()){
	                auto it=q.front();
	                q.pop();
	                int u=it.first;
	                int c=it.second;
	                for(auto v:adj[u]){
	                    if(!vis[v]){
	                        q.push({v,1-c});
	                        vis[v]=1;
	                        col[v]=1-c;
	                    }
	                    else if(col[v]==c){
	                        return false;
	                    }
	                }
	            }
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends