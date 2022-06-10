// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long solve(long long arr[],long long start,long long mid,long long end){
        long long count=0;
        long long temp[end-start+1];
        long long i=start,j=mid, k=start-start;
        while(i<mid and j<=end){
            if(arr[i]>arr[j]){
                temp[k]=arr[j];
                j++;
                k++;
                count+=(mid-i);
            }
            else{
                temp[k]=arr[i];
                i++;
                k++;
            }
        }
        while(i<mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
        while(j<=end){
            temp[k]=arr[j];
            j++;
            k++;
            
        }
        for(int x=start;x<=end;x++){
            arr[x]=temp[x-start];
            //cout<<arr[x]<<" ";
        }
       // cout<<endl;
      return count;
    }
    long long int mergeSort(long long arr[],long long start,long long end){
        long long count=0;
        if(start<end){
            long long mid=(start+end)/2;
            count+=mergeSort(arr,start,mid);
            count+=mergeSort(arr,mid+1,end);
            count+=solve(arr,start,mid+1,end);
        }
        return count;
    }
   
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
       // return count;
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