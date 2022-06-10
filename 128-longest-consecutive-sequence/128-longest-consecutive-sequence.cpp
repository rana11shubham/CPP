class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        int count =0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int count_temp=1;
            if(mp.find(temp-1)==mp.end()){
                int j=temp+1;
                while(mp.find(j)!=mp.end()){
                    temp++;
                    j=j+1;
                    count_temp++;
                }
                count=max(count,count_temp);
            }
            else{
                continue;
            }
        }
        return count;
    }
};