// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n=nums.size();
	    int ans=1;
	    int max_lis=1;
	    int max_lis1=1;
	    vector<int>dp1(n+1,1),dp2(n+1,1);
	    // Finding out the LIS from left to right
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j])
	                dp1[i]=max(dp1[i],dp1[j]+1);
	        }
	        max_lis=max(dp1[i],max_lis);
	    }
	    // Finding out the LIS from right to left
	    for(int i=n-2;i>=0;i--){
	        for(int j=i+1;j<n;j++){
	            if(nums[i]>nums[j])
	                dp2[i]=max(dp2[i],dp2[j]+1);
	        }
	        max_lis1=max(dp2[i],max_lis1);
	    }
	    int final_ans=0;
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if(nums[i]>nums[j]){
	                final_ans=max(final_ans,dp1[i]+dp2[j]);
	            }
	        }
	    }	
	    return max(final_ans,max(max_lis,max_lis1));
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends