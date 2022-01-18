class Solution {
public:
    int numSplits(string s) {
        int n=s.length();
        vector<int>left(n,0);
        vector<int>right(n,0);
        unordered_map<char,int>mp;
        for(int i=1;i<n;i++){
            if(mp.find(s[i-1])!=mp.end()){
                mp[s[i-1]]++;
                left[i]=left[i-1];
            }
            else{
                left[i]=left[i-1]+1;
                mp[s[i-1]]++;
            }
        }
        mp.clear();
        for(int i=n-2;i>=0;i--){
            char ch=s[i+1];
            if(mp.find(ch)!=mp.end()){
                mp[ch]++;
                right[i]=right[i+1];                   
            }
            else{
                right[i]=right[i+1]+1;
                mp[ch]++;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(left[i]==right[i-1]){
                ans++;
            }
        }
        return ans;
    }
};