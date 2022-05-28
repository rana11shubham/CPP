// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<int,int>mp;
    int minThrow(int N, int arr[]){
        for(int i=0;i<2*N;i+=2){
            mp[arr[i]]=arr[i+1];
        }
        vector<bool>vis(31,false);
        queue<int>q;
        q.push(1);
        vis[1]=true;
        int step=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int it=q.front();
                q.pop();
                if(it==30){
                    return step;
                }
                for(int k=1;k<=6;k++){
                    int new_step=it+k;
                    if(mp.find(new_step)!=mp.end() && !vis[mp[new_step]]){
                        q.push(mp[new_step]);
                        vis[mp[new_step]]=1;
                    }
                    else{
                        q.push(new_step);
                        vis[new_step]=1;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends