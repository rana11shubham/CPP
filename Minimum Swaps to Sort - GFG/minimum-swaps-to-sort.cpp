// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    pair<int,int>vc[n];
	    int index=0;
	    for(int i:nums){
	        vc[index].first=i;
	        vc[index].second=index;
	        index++;
	    }
	    int ans=0;
	    sort(vc,vc+n);
	    vector<int>visited(n,0);
	    for(int i=0;i<n;i++){
	        int cycle_len=0;
	        int j=i;
	        if(i==vc[i].second || visited[i])
	            continue;
	        while(!visited[j]){
	            visited[j]=1;
	            j=vc[j].second;
	            cycle_len++;
	        }
	        ans+=cycle_len-1;
	    }
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends