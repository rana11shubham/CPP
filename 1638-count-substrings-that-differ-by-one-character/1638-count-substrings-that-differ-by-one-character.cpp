class Solution {
public:
    int countSubstrings(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        vector<vector<int>>dp1(n1+1,vector<int>(n2+1,0));
        int ans=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    dp1[i][j]=dp1[i-1][j-1];
                }
                else{
                        dp1[i][j]=dp[i-1][j-1]+1;
                }
                        ans+=dp1[i][j];
                    
                }
                
            }
        
        return ans;
    }
};


