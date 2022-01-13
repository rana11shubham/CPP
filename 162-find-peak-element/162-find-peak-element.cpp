class Solution {
public:
    int findPeakElement(vector<int>& arr) {
    int n=arr.size();
     if(n==1)
    return n-1;
    int i=0,j=n-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(mid>0 && mid<n-1){
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]<arr[mid-1]){
            j=mid-1;
        }
        else i=mid+1;
        }
        else{
            if(mid==0){
                if(arr[mid]>arr[mid+1]){
                    return mid;
                }
                else i=mid+1;
            }
            else{
                if(arr[mid]>arr[mid-1])
                    return mid;
                else j=mid-1;
            }
        }
    }
    return 0;   
    }
};