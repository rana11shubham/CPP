class Solution {
public:
    int dp[4];
    int solve(vector<int>& matchsticks,int pos){
        int n=matchsticks.size();
        if(pos==n){
            for(int i=0;i<4;i++)
            {
                if(dp[i]!=0)
                    return false;
            }
            return true;
        }
        if(matchsticks[pos]<=dp[0]){
            dp[0]-=matchsticks[pos];
            if(solve(matchsticks,pos+1))
                return true;
            dp[0]+=matchsticks[pos];
        }
         if(matchsticks[pos]<=dp[1]){
            dp[1]-=matchsticks[pos];
            if(solve(matchsticks,pos+1))
                return true;
            dp[1]+=matchsticks[pos];
        }
         if(matchsticks[pos]<=dp[2]){
            dp[2]-=matchsticks[pos];
            if(solve(matchsticks,pos+1))
                return true;
            dp[2]+=matchsticks[pos];
        }
         if(matchsticks[pos]<=dp[3]){
            dp[3]-=matchsticks[pos];
            if(solve(matchsticks,pos+1))
                return true;
            dp[3]+=matchsticks[pos];
        }
        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(),matchsticks.rend());
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0)
            return false;
        int target=sum/4;
        for(int i=0;i<4;i++)
            dp[i]=target;
        int sum1=0,cnt=0;
        return solve(matchsticks,0);
    }
};