class Solution {
public:
    unordered_map<int,int>mp;
    unordered_map<string,bool>dp;
    bool solve(int start,int target,int k){
        // Base cases
        if(start==target)
            return true;
        if(start>target)
            return false;
        bool opt1=false;
        bool opt2=false;
        bool opt3=false;
        string temp=to_string(start)+""+to_string(k);
        if(dp.find(temp)!=dp.end())
            return dp[temp];
        if(mp[start+k-1]==1 and start+k-1>start)
             opt1=solve(start+k-1,target,k-1);
        if(mp[start+k]==1 and start+k>start)
             opt2=solve(start+k,target,k);
        if(mp[start+k+1]==1 and start+k+1>start)
             opt3=solve(start+k+1,target,k+1);
        return dp[temp]= (opt1||opt2||opt3);
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
       
        for(auto it:stones)
            mp[it]=1;
       // dp.assign(stones[n-1]+1,-1);
        return solve(stones[0],stones[n-1],0);
    }
};