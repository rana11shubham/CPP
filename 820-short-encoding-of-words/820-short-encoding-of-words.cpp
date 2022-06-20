class Solution {
public:
    unordered_map<string,string>mp;
    static bool comp(string s1,string s2){
        return s1.length()>s2.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        set<string>ss;
        for(auto it:words){
            string s=it;
            if(mp.find(s)!=mp.end()){
                ss.insert(mp[s]);
            }
            else{
            for(int i=s.length()-1;i>=0;i--){
                mp[s.substr(i)]=s;
                ss.insert(s);
            }
        }
    }
        int ans=0;
        for(auto it:ss)
            ans+=it.size();
        return ans+ss.size();
}
};