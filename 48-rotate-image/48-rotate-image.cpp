class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        // vector<vector<int>>ans(r,vector<int>(c,0));
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         int temp=matrix[i][j];
        //         ans[j][r-i-1]=temp;
        //     }
        // }
        // matrix=ans;
        for(int i=0;i<r;i++){
            for(int j=i+1;j<c;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};