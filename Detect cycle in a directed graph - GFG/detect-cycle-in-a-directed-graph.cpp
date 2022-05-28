// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    unordered_map<int,int>recStack;
    bool isCycle(int v,vector<int>adj[],vector<int>&vis){
        vis[v]=true;
        recStack[v]=1;
        for(auto it:adj[v]){
            if(vis[it] and recStack[it]){
                return true;
            }
            else{
                if(!vis[it] && isCycle(it,adj,vis))
                    return true;
            }
        }
        recStack[v]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i] and isCycle(i,adj,vis)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends