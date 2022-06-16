class Solution {
public:

    
    string longestPalindrome(string s) {
        int n=s.length();
        int max_len=0;
        int start=0;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            start=i;
            max_len=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                max_len=2;
            }
        }
        for(int chain_len=3;chain_len<=n;chain_len++){
            for(int i=0;i<n-chain_len+1;i++){
                int j=i+chain_len-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                    if(dp[i][j]){
                        start=i;
                        max_len=j-i+1;
                    }
                }
            }
        }
        return s.substr(start,max_len);
    }
};