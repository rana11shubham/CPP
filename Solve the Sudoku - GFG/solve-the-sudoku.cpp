// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool isValid(vector<vector<int>>&grid,int row,int col,int x){
         for(int i=0;i<9;i++){
            if(grid[i][col]==x ||grid[row][i]==x)
                return false;
        }
        int rdx=(row/3)*3;
        int cdx=(col/3)*3;
        for(int i=rdx;i<rdx+3;i++){
            for(int j=cdx;j<cdx+3;j++){
                if(grid[i][j]==x)
                        return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>>&grid,int row, int col){
        if(row==9){
            return true;
        }
        if(col==9){
          return solve(grid,row+1,0);
        }
        if(grid[row][col]!=0){
           return solve(grid,row,col+1);
        }
        for(int i=1;i<=9;i++){
            if(isValid(grid,row,col,i)){
                grid[row][col]=i;
                bool temp=solve(grid,row,col+1);
                if(temp==true)
                return true;
                
            }
            
     }
               grid[row][col]=0;
                return false;
      
    }
    bool SolveSudoku(int grid[N][N])  
    {  vector<vector<int>>dp(9,vector<int>(9));
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                dp[i][j]=grid[i][j];
            
        bool temp= solve(dp,0,0);
        // for(int i=0;i<9;i++)
        //     cout<<dp[0][i];
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                grid[i][j]=dp[i][j];
     return temp;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends