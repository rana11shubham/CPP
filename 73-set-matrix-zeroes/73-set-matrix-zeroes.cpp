class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>row_hash,col_hash;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    row_hash.push_back(i);
                    col_hash.push_back(j);
                }
            }
        }
       
        for(auto it:row_hash){
            for(int i=0;i<col;i++)
                matrix[it][i]=0;
        }
        for(auto it:col_hash){
            for(int i=0;i<row;i++)
                matrix[i][it]=0;
        }
    }
};