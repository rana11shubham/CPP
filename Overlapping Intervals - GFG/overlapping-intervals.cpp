// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
public:
    
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end(),comp);
        vector<int>ans=intervals[0];
        vector<vector<int>>final_ans;
        for(auto it:intervals){
            if(it[0]<=ans[1]){
                ans[1]=max(ans[1],it[1]);
            }
            else{
                final_ans.push_back(ans);
                ans=it;
            }
        }
        final_ans.push_back(ans);
        return final_ans;
         
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends