// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {   // Graph Approach
        // int indegree[n]={0};
        // int outdegree[n]={0};
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=0;j<n;j++){
        //         sum+=M[i][j];
        //         indegree[j]+=M[i][j];
        //     }
        //     outdegree[i]=sum;
        // }
        // for(int i=0;i<n;i++){
        //     if(indegree[i]==n-1 and outdegree[i]==0)
        //         return i;
        // }
        // return -1;
        // Stack based approach
        // stack<int>s;
        // for(int i=0;i<n;i++)
        //     s.push(i);
        // int celeb=0;
        // while(s.size()>1){
        //     int x=s.top();
        //     s.pop();
        //     int y=s.top();
        //     s.pop();
        //     if(M[x][y]){
        //         s.push(y);
        //     }
        //     else{
        //         s.push(x);
        //     }
        // }
        // celeb=s.top();
        // s.pop();
      //  cout<<celeb<<endl;
      // Two pointer approach
      int s=0,e=n-1;
      while(s<e){
          if(M[s][e]==1){
              s++;
          }
          else{
              e--;
          }
      }
      int celeb=s;
        for(int i=0;i<n;i++){
            if(i!=celeb and (M[celeb][i]==1 || M[i][celeb]==0))
                return -1;
        }
        return celeb;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends