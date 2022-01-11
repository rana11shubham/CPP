// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int bs(int A[],int l,int h,int key){
        int loc=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(A[mid]==key){
                return mid;
            }
            else if(A[mid]>key){
                h=mid-1;
            }
            else l=mid+1;
        }
        return loc;
    }
    int search(int A[], int l, int h, int key){
    //complete the function here
        int min_loc=-1;
        int n=h+1;
        while(l<=h){
            if(A[l]<=A[h]){
                min_loc= l;
                break;
            }
            int mid=l+(h-l)/2;
            if(A[mid]<A[(mid-1+n)%n] && A[mid]<A[(mid+1-n)%n])
            {    min_loc=mid;
                if(key==A[mid])
                    return mid;
                break;}
            else if(A[mid]<A[l]){
                h=mid-1;
            }
            else l=mid+1;
        }
        int optL=bs(A,0,min_loc-1,key);
        int optR=bs(A,min_loc+1,n-1,key);
        if(optL==-1)
            return optR;
        return optL;
       
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends