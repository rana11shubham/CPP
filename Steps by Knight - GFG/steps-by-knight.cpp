// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   int start_r=KnightPos[0];
	   int start_c=KnightPos[1];
       vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	   int end_r=TargetPos[0];
	   int end_c=TargetPos[1];
	   int dist=0;
	   queue<pair<int,int>>q;
	   q.push({start_r,start_c});
	   vis[start_r][start_c]=1;
	   while(!q.empty()){
	       int n=q.size();
	       for(int i=0;i<n;i++){
	       auto it=q.front();
	       q.pop();
	       int r=it.first;
	       int c=it.second;
	       if(r==end_r && c==end_c)
	            return dist;
	       // Check all the possiblities
	       if(r-2>0 && c-1>0 && !vis[r-2][c-1]){
	           q.push({r-2,c-1});
	           vis[r-2][c-1]=1;
	       }
	       if(r-2>0 && c+1<=N && !vis[r-2][c+1]){
	           q.push({r-2,c+1});
	           vis[r-2][c+1]=1;
	       }
	       if(r-1>0 && c-2>0 && !vis[r-1][c-2]){
	           q.push({r-1,c-2});
	           vis[r-1][c-2]=1;
	       }
	       if(r-1>0 && c-2>0 && !vis[r-1][c-2]){
	           q.push({r-1,c-2});
	           vis[r-1][c-2]=1;
	       }
	       if(r+1<=N && c-2>0 && !vis[r+1][c-2]){
	           q.push({r+1,c-2});
	           vis[r+1][c-2]=1;
	       }
	       if(r+2<=N && c-1>0 && !vis[r+2][c-1]){
	           q.push({r+2,c-1});
	           vis[r+2][c-1]=1;
	       }
	       if(r+2<=N && c+1<=N && !vis[r+2][c+1]){
	           q.push({r+2,c+1});
	           vis[r+2][c+1]=1;
	       }
	       if(r-1>0 && c+2<=N && !vis[r-1][c+2]){
	           q.push({r-1,c+2});
	           vis[r-1][c+2]=1;
	       }
	       if(r+1<=N && c+2<=N && !vis[r+1][c+2]){
	           q.push({r+1,c+2});
	           vis[r+1][c+2]=1;
	       }
	   }
	   dist++;
	       
	 }
	  return dist;  
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends