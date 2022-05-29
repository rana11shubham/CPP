class Solution {
public:
    unordered_map<int,int>mp;
    bool bipartite(int u,vector<vector<int>>&graph,vector<int>&vis){
            int col=mp[u];
            for(auto it:graph[u]){
                if(mp.find(it)!=mp.end() && mp[it]==col){
                    return false;
                }
                else if(!vis[it]){
                vis[it]=true;
                mp[it]=1-col;
                if(!bipartite(it,graph,vis))
                    return false;
            }
        }
       return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                mp[i]=0;
                if(!bipartite(i,graph,vis)){
                    return false;
                }
            }
        }
        return true;
    }
};