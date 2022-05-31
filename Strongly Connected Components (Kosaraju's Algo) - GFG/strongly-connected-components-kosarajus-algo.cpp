// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	stack<int>s;
	vector<int>vis;
	int count;
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int>adj[],int u,int status){
	    vis[u]=1;
	    for(auto it:adj[u]){
	        if(!vis[it]){
	            dfs(adj,it,status);
	        }
	    }
	    if(status==0)
	        return;
	        else
	    s.push(u);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vis.assign(V,0);
        // First find all the topological sort
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,1);
            }
        }
        // Transpose all the edges in the graph
        vector<int>adj_trans[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i])
                adj_trans[it].push_back(i);
        }
        // Run dfs again
        vis.assign(V,0);
        count=0;
        while(!s.empty()){
            int it=s.top();
            s.pop();
            if(!vis[it]){
           //     cout<<it<<endl;
                count++;
                dfs(adj_trans,it,0);
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends