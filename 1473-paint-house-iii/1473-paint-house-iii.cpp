class Solution {
public:
    int dp[100][100][101];
    int solve(int i,int c,int k,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        // Base case
        if(k>target)
            return 1e9;
        if(i==m){
            return (k==target)?0:1e9;
        }
        // string temp=to_string(i)+""+to_string(c)+""+to_string(k);
        // if(mp.find(temp)!=mp.end())
        //     return mp[temp];
        if(dp[i][c][k]!=-1){
            return dp[i][c][k];
        }
        int ans=1e9;
        if(houses[i]==0){
            for(int j=0;j<n;j++){
                ans=min(ans,cost[i][j]+solve(i+1,j+1,(c==j+1)?k:k+1,houses,cost,m,n,target));
            }
        }
        else{
            ans=min(ans,solve(i+1,houses[i],(c==houses[i])?k:k+1,houses,cost,m,n,target));
        }
        return dp[i][c][k]= ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // unordered_map<string,int>mp;
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,houses,cost,m,n,target);
        return ans==1e9?-1:ans;
    }
};