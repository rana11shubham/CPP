// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
   static bool comp(vector<int>&a,vector<int>&b){
       if(a[0]<b[0])
            return true;
        else if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return false;
   }
public:
    
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end(),comp);
         vector<int>result(2,0);
         vector<vector<int>>ans;
         result[0]=intervals[0][0];
         result[1]=intervals[0][1];
         for(int i=1;i<intervals.size();i++){
             if(result[1]>=intervals[i][0]){
                 result[1]=max(result[1],intervals[i][1]);
             }
             else{
                 ans.push_back(result);
                 result=intervals[i];
             }
         }
         ans.push_back(result);
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