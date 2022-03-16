class Solution {
public:
    #define INF 1000000007
    int jump(vector<int>& A) {
       int n=A.size();
        int dp[n];
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<n;i++){
            int reach=A[i];
            for(int j=1;j<=reach;j++){
                if(i+j<n){
                    dp[i+j]=min(dp[i+j],1+dp[i]);
                }
            }
        }
        return dp[n-1];
    }
};