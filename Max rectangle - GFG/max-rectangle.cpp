// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int area(int arr[],int m){
        int left[m]={0};
        int right[m]={0};
        stack<int>st;
        for(int i=0;i<m;i++){
            while(st.empty()!=true and arr[i]<=arr[st.top()])
                st.pop();
            if(st.empty()){
                left[i]=i+1;
            }
            else{
                left[i]=i-st.top();
            }
            st.push(i);
        }
        while(st.empty()==false)
            st.pop();
        for(int i=m-1;i>=0;i--){
            while(st.empty()!=true and arr[i]<=arr[st.top()])
                st.pop();
            if(st.empty()){
                right[i]=m-i;
            }
            else{
                right[i]=st.top()-i;
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,(right[i]+left[i]-1)*arr[i]);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0){
                   ans=max(ans,area(M[i],m)); 
                    continue;
            }
            for(int j=0;j<m;j++){
                if(M[i][j]==1)
                    M[i][j]+=M[i-1][j];
            }
            ans=max(ans,area(M[i],m));
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends