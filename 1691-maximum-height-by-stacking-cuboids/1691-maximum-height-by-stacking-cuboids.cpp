class Solution {
public:
    int maxHeight(vector<vector<int>>& box) {
        vector<int>dp;
        int n=box.size();
        if(n==1)
            return max({box[0][0],box[0][1],box[0][1]});
        sort(box.begin(),box.end(),[](auto &a,auto &b){
            return a[0]+a[1]+a[2]<b[0]+b[1]+b[2];
        });
        for(auto& it:box){
            sort(it.begin(),it.end());
            dp.push_back(it.back());
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(box[i][0]>=box[j][0] && box[i][1]>=box[j][1] && box[i][2]>=box[j][2]){
                    dp[i]=max(dp[i],dp[j]+max({box[i][0],box[i][1],box[i][2]}));
                }
                  ans=max(dp[i],ans);
            }
        }
        return ans;
    }
};