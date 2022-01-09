class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(auto it:nums)
            s.insert(it);
        vector<int>ss;
        for(auto it:s)
            ss.push_back(it);
        sort(ss.begin(),ss.end());
        int ans=INT_MAX;
        int i=0;
        for(int it:ss){
            int upper=(it)+n-1;
             auto upper_loc = upper_bound(ss.begin(), ss.end(), upper);
            int temp=upper_loc-ss.begin();
            ans=min(ans,n-(temp-i));
            i++;
        }
         return ans;
        }
    
};


// 4,2,5,3--> no change
// 1,2,3,5,6--> 
//     1.) max-min>n-1
//     2.) max-min<n-1
//     3.) max-min=n-1 --> return 0.
//     max-min>n-1
//     max-min<n-1
//     1 1 1 2
//     1<3
    