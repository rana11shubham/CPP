class Solution {
public:
    int numSplits(string s) {
        int n=s.length();
        int ans=0;
        vector<int>left(n,0);
       // vector<int>right(n,0);
        unordered_map<char,int>mp;
        set<int>l_used;
        int l_score=0,r_score=0;
        for(auto it:s){
            mp[it]++;
        }
        r_score=mp.size();
        for(int i=0;i<=n-2;i++){
            char ch=s[i];
            mp[ch]--;
            if(l_used.find(ch)==l_used.end()){
                l_used.insert(ch);
                l_score++;
            }
            if(mp[ch]==0){
                r_score--;
            }
            if(l_score==r_score){
                ans++;
            }
        }
       
        return ans;
    }
};