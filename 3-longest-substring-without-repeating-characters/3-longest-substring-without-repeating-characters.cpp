class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0;
        int ans=0;
        int n=s.length()-1;
        while(j<=n){
            char x=s[j];
            mp[x]++;
            while(mp[x]>1){   
                mp[s[i]]--;
                 i++; 
            }
            if(mp[x]==1){
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
};