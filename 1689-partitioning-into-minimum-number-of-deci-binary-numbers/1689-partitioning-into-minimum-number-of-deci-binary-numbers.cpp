class Solution {
public:
    int minPartitions(string n) {
        int ans=INT_MIN;
        for(auto it:n){
            ans=max(ans,it-'0');
        }
        return ans;
    }
};