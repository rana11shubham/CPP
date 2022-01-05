// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i=0,j=0;
        int ans=0,sum=0;
        for(;j<N;j++){
            if(j-i+1<K){
                sum+=Arr[j];
                continue;
            }
            else if(j-i+1==K){
                sum+=Arr[j];
                ans=max(ans,sum);
                sum-=Arr[i];
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends