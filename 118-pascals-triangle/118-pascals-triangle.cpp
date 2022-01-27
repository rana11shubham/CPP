class Solution {
public:
    vector<vector<int>>ans;
    vector<int>solve(int n){
    if(n==1){
        vector<int>temp;
        temp.push_back(1);
        return temp;
        }
        else if(n==2){
        vector<int>temp;
        temp.push_back(1);
        temp.push_back(1);
        }    
        vector<int>temp=solve(n-1);
        vector<int>ans1;
        ans1.push_back(1);
        for(int i=0;i<temp.size()-1;i++){
            ans1.push_back((temp[i]+temp[i+1]));
        }
        ans1.push_back(1);
        ans.push_back(ans1);
        return ans1;
    }
    vector<vector<int>> generate(int numRows) {
        ans.push_back({1});
        auto it=solve(numRows);
        return ans;
    }
};