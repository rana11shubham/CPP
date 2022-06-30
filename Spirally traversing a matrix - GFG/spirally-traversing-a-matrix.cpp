// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int>ans;
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {  
        int minr=0,minc=0,maxr=r-1,maxc=c-1;
        int cnt=r*c;
        int counter=0;
        while(counter<cnt){
            // Right
            for(int i=minc;i<=maxc && counter<cnt;i++){
                ans.push_back(matrix[minr][i]);
                counter++;
            }
            minr++;
            // Down
            for(int i=minr;i<=maxr && counter<cnt;i++){
                ans.push_back(matrix[i][maxc]);
                counter++;
            }
            maxc--;
            // Left
            for(int i=maxc;i>=minc && counter<cnt;i--){
                ans.push_back(matrix[maxr][i]);
                counter++;
            }
            maxr--;
            // Top
            for(int i=maxr;i>=minr && counter<cnt;i--){
                ans.push_back(matrix[i][minc]);
                counter++;
            }
            minc++;
        }
          
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends