class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long int possibility=1<<k;
        int n=s.length();
        set<string>ss;
        for(int i=0;i<n-k+1;i++){
            string temp="";
            for(int j=i;j<i+k;j++){
                temp+=s[j];
            }
            ss.insert(temp);
        }
        cout<<ss.size();
        return ss.size()==possibility;
    }
};