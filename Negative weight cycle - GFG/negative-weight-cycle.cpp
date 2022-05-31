// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n,1e9);
	    dist[0]=0;
	    int e=edges.size();
	    for(int k=1;k<=n-1;k++){
	    for(int i=0;i<e;i++){
	        // Check relaxation
	        int u=edges[i][0];
	        int v=edges[i][1];
	        int wt=edges[i][2];
	        if(dist[v]>dist[u]+wt){
	            dist[v]=dist[u]+wt;
	        }
	    }
	   }
	    for(int i=0;i<e;i++){
	        // Check relaxation
	        int u=edges[i][0];
	        int v=edges[i][1];
	        int wt=edges[i][2];
	        if(dist[v]>dist[u]+wt){
	            return 1;
	            dist[v]=dist[u]+wt;
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends