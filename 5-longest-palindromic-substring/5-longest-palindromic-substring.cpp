class Solution {
public:
  
    string longestPalindrome(string s) {
        int n=s.length();
        bool dp[n][n];
        string ans;
        int start=0;
        int max_len=0;
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=true,start=i,max_len=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                max_len=2;
            }
        }
        for(int chain=3;chain<=n;chain++){
            for(int i=0;i<n-chain+1;i++){
                int j=i+chain-1;
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                        if(dp[i][j]){
                              start=i;
                              max_len=chain;
                        }
                
                }
                
            }
        }
        return s.substr(start,max_len);
    }
    /*
        abcdaaad
        dp[i,j]=dp[i+1,j-1]+2 when s[i]==s[j]
        dp[i,j]=max(dp[i+1,j],dp[i,j-1]);
    */
};