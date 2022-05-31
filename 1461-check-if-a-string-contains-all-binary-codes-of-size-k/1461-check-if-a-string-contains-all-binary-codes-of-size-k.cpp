class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long int possibility=1<<k;
        int n=s.length();
        unordered_set<string>ss;
        for(int i=0;i<n-k+1;i++){
            ss.insert(s.substr(i,k));
        }
        return ss.size()==possibility;
    }
};