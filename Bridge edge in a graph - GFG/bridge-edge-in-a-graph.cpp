// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int u,v;
	vector<int>in_time;
	vector<int>low_time;
	vector<int>vis;
	int time;
    //Function to find if the given edge is a bridge in graph.
    int status;
    void dfs(int node,vector<int>adj[],int par=-1){
        vis[node]=1;
        time++;
        in_time[node]=low_time[node]=time;
        for(auto it:adj[node]){
            if(par==it){
                continue;
            }
            if(vis[it]){
                low_time[node]=min(low_time[node],in_time[it]);
            }
            else{
                dfs(it,adj,node);
                low_time[node]=min(low_time[node],low_time[it]);
                if(node==u and it==v || node==v and it==u){
                    if(low_time[it]>in_time[node]){
                        status=1;
                    }
                }
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        u=c,v=d;
        status=0;
        in_time.assign(V,-1);
        low_time.assign(V,-1);
        vis.assign(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj);
            }
        }
        return status==1;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends