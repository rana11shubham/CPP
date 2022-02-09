class Solution {
public:
   vector<vector<int>>result;
    void solve(vector<int>&A,int B,int pos,vector<int>&ans){
        if(B==0){
            sort(ans.begin(),ans.end());
            result.push_back(ans);
            return;
        }
        while(pos<A.size() && B-A[pos]>=0){
            ans.push_back(A[pos]);
            solve(A,B-A[pos],pos,ans);
            pos++;
             ans.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
         int n=A.size();
        vector<int>ans;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        solve(A,B,0,ans);
        return result;
    }
};