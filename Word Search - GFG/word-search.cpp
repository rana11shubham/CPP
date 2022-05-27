// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int r,int c,vector<vector<char>>&board,string word,int pos){
        if(pos==word.length())
            return true;
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[pos])
        {
            return false;
        }
        char temp=board[r][c];
        board[r][c]='#';
        bool result=dfs(r+1,c,board,word,pos+1)||dfs(r-1,c,board,word,pos+1)||dfs(r,c+1,board,word,pos+1)||dfs(r,c-1,board,word,pos+1);
        board[r][c]=temp; 
    return result; 
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && dfs(i,j,board,word,0))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends