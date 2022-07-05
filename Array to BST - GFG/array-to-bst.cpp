// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void constructBST(vector<int>&nums,vector<int>&ans,int s,int e){
        if(s>e)
            return;
        int mid=(s+e)/2;
        ans.push_back(nums[mid]);
        constructBST(nums,ans,s,mid-1);
        constructBST(nums,ans,mid+1,e);
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        constructBST(nums,ans,0,n-1);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends