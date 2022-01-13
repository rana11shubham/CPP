class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N=matrix.size();
        int M=matrix[0].size();
        int i=0,j=M-1;
        while(i<N && j>=0){
        if(matrix[i][j]==target){
            return 1;
        }
        else if(matrix[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
    }
};