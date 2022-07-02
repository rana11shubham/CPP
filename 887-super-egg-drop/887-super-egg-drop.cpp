class Solution {
public:
    int dp[10001][101];
     int solve(int n,int k){
          if(dp[n][k]!=-1)
            return dp[n][k];
        if(n==1 || n==0 || k==1)
            return n;
         if(k<=0)
             return 0;
      
        int s=1,e=n,ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            int opt1=solve(mid-1,k-1);
            int opt2=solve(n-mid,k);
            ans=min(ans,max(opt1,opt2)+1);
            if(opt1>opt2){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return dp[n][k]= ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};