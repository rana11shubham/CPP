// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long s,long long mid,long long e)
    {
        long long count=0;
        long long temp[e-s+1];
        long long i=s,j=mid;
        long long k=0;
        while(i<mid and j<=e){
            if(arr[i]>arr[j]){
                count+=(mid-i);
                temp[k]=arr[j];
                j++;
                k++;
                
            }
            else {
                temp[k]=arr[i];
                i++;
                k++;
            }
        }
        while(i<mid)
        {
            temp[k]=arr[i];
            k++;
            i++;
        }   
        while(j<=e)
        {
            temp[k]=arr[j];
            k++;
            j++;
        }   
        
        for(int m=s;m<=e;m++){
            arr[m]=temp[m-s];
        }
        return count;
    }
    
    long long mergeSort(long long arr[],long long s,long long e){
        long long ans=0;
        if(s<e){
            long long mid=s+(e-s)/2;
            ans+=mergeSort(arr,s,mid);
            ans+=mergeSort(arr,mid+1,e);
            ans+=merge(arr,s,mid+1,e);
        }
        return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
        }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends