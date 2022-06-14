// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       long long ans=0;
       vector<int>left;
       vector<int>right;
       int max_ele=arr[0];
       for(int i=1;i<n-1;i++){
           max_ele=max(max_ele,arr[i]);
           left.push_back(max_ele);
       }
       max_ele=arr[n-1];
       for(int i=n-2;i>=1;i--){
           max_ele=max(max_ele,arr[i]);
           right.push_back(max_ele);
       }
       reverse(right.begin(),right.end());
       for(int i=0;i<left.size();i++){
           int temp=min(left[i],right[i]);
           ans+=abs(temp-arr[i+1]);
       }
       
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends