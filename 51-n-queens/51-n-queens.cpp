class Solution {
public:
    vector<vector<string>>ans;
    bool isValid(vector<vector<char>>&board,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')
                return false;
        }
         for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q')
                return false;
        }
        return true;
        
    }
    void solve(vector<vector<char>>&board,int row,int n){
        // Base cases
        if(row==n){
            vector<string>temp;
            for(auto it:board){
                string temp1="";
                for(auto it1:it){
                    temp1+=it1;
                }
                 temp.push_back(temp1);
            }
            ans.push_back(temp);
        }
        
        for(int c=0;c<n;c++){
            if(isValid(board,row,c,n)){
                board[row][c]='Q';
                solve(board,row+1,n);
                board[row][c]='.';
            }
            
        }
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
          solve(board,0,n);   
        return ans;
    }
};