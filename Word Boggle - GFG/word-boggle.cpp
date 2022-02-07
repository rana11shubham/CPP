// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    bool exist(vector<vector<char>>&board,string word){
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(dfs(board,i,j,word,n,m)){
                    return true;
                }
    
        return false;
    }
    bool dfs(vector<vector<char>>&board,int i,int j,string word,int n,int m){
        if(word.size()==0)return true;
        if(i>=n || i<0 || j>=m || j<0 || word[0]!=board[i][j])return false;
        char temp=board[i][j];
        board[i][j]='!';
        string str=word.substr(1);
        bool ans=dfs(board,i-1,j-1,str,n,m);
        ans|=dfs(board,i-1,j,str,n,m);
        ans|=dfs(board,i-1,j+1,str,n,m);
        ans|=dfs(board,i,j-1,str,n,m);
        ans|=dfs(board,i,j+1,str,n,m);
        ans|=dfs(board,i+1,j-1,str,n,m);
        ans|=dfs(board,i+1,j,str,n,m);
        ans|=dfs(board,i+1,j+1,str,n,m);
        board[i][j]=temp;
        return ans;
        
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	   vector<string>ans;
	   for(auto word:dictionary){
	       if(exist(board,word)){
	           ans.push_back(word);
	       }
	   }
	   return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends