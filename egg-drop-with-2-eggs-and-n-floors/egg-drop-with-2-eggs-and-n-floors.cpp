class Solution {
public:
 
    int dp[3][1001];
    int solve(int n,int k){
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        if(k==1 || k==0 || n==1 )
            return k;
        if(n<=0)
            return 0;
   
        int ans=INT_MAX;
        int l=1,r=k;
        while(l<=r){
            int mid=l+(r-l)/2;
            int b_egg=solve(n-1,mid-1);
            int n_egg=solve(n,k-mid);
            int temp=max(b_egg,n_egg);
            ans=min(ans,temp+1);
            if(b_egg>n_egg){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return dp[n][k]= ans;
    }
    
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(2,n);

    }
};