class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    
    bool compare(string &s1,string &s2){
        if((s2.length()-s1.length())!=1)
           return false;
        int i=0,j=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]!=s2[j]){
                    j++;
                continue;
                }
            i++;
            j++;
          }
          if(j==s2.length()-1)
           return true;
         return i==s1.length() && j==s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        int ans=1;
        vector<int>dp(n+1,1);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(compare(words[i],words[j])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};