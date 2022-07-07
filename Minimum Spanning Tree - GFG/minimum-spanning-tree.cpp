// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>dist(V,INT_MAX);
        dist[0]=0;
        vector<int>MST(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
         while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int u=it.second;
            MST[u]=1;
            for(auto v:adj[u]){
                int node=v[0];
                int wt=v[1];
                if(MST[node]==false and wt<dist[node]){
                    dist[node]=wt;
                    pq.push({wt,node});
                    //parent[node]=u;
                } 
            }
        }
        // for(auto it:dist)
        //     cout<<it<<endl;
        return accumulate(dist.begin(),dist.end(),0);
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends