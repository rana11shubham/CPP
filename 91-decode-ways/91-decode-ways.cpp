class Solution {
public:
    int dp[101];

    
    int numDecodings(string s) {
        int n=s.length();
        if(s[0]=='0' || n==0)
            return 0;
        else if(n==1)
            return 1;
       dp[0]=1;
        int a=1,b=1;
        for(int i=1;i<n;i++){
            int u=s[i]-'0';
            int t=s[i-1]-'0';
            int res=t*10+u;
            if(u==0){
                if(res>=1 && res<=26){
                    dp[i]=a;
                }
                
                else{
                    return 0;
                }
            }
            else{
                if(res>=1 && res<=26 && t!=0){
                    dp[i]=a+b;
                }
                else dp[i]=b;
            }
            a=b;
            b=dp[i];
        }
        return dp[n-1];
    }
};