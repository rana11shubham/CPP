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
        int ans=n;
        int i=0,j=0;
        int m=ss.size();
        while(i<m){
            int largest_ele=ss[i]+n-1;
            while(j<m && ss[j]<=largest_ele){
                j++;
            }
            
            ans=min(ans,n-(j-i));
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
    