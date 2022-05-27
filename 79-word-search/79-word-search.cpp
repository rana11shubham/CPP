class Solution {
public:
    bool dfs(int r,int c,vector<vector<char>>&board,string word,int pos){
        if(pos==word.length())
            return true;
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || word[pos]!=board[r][c])
            return false;
        char temp=board[r][c];
        board[r][c]='#';
        
        bool result=dfs(r-1,c,board,word,pos+1)||dfs(r+1,c,board,word,pos+1)||dfs(r,c-1,board,word,pos+1)||dfs(r,c+1,board,word,pos+1);
        board[r][c]=temp;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j] && dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};