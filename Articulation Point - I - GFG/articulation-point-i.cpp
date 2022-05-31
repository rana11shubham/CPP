// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int>insert_time;
    vector<int>low_time;
    vector<int>vis;
    vector<int>articulation;
    int time;
    void dfs(int node,vector<int>adj[],int par=-1){
        vis[node]=1;
        int child=0;
        time++;
        low_time[node]=insert_time[node]=time;
        for(auto it:adj[node]){
            if(par==it)continue;
            if(!vis[it]){
                dfs(it,adj,node);
                low_time[node]=min(low_time[node],low_time[it]);
                if(insert_time[node]<=low_time[it] && par!=-1){
                    articulation[node]=1;
                }
                 child++;
            }
           
            else{
                low_time[node]=min(low_time[node],insert_time[it]);    
            }
        }
            if(par==-1 and child>1){
                articulation[node]=1;
            
        }
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        insert_time.assign(V,-1);
        low_time.assign(V,-1);
        vis.assign(V,0);
        vector<int>ans;
        time=0;
        articulation.assign(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj);
            }
        }
        for(int i=0;i<V;i++){
            if(articulation[i])
                ans.push_back(i);
        }
       if(ans.size()==0){
           return {-1};
       }
       return ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends