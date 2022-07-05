class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto it:nums){
            mp[it]=1;
        }
        int ans=0;
        for(auto it:mp){
            int x=it.first;
            int temp=x;
            if(mp.find(x-1)==mp.end()){
                while(mp.find(temp+1)!=mp.end()){
                    mp[x]=1+mp[x];
                    temp=temp+1;
                }
            ans=max(ans,mp[x]);
            }
        }
        for(auto it:mp)
            cout<<it.second<<endl;
        return ans;
    }
};