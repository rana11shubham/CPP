class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int ansF=-1,ansL=-1;
        int n=arr.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==x){
                ansF=mid;
                j=mid-1;
            }
            else if(arr[mid]>x)
                j=mid-1;
            else i=mid+1;
        }
        i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==x){
                ansL=mid;
                i=mid+1;
            }
            else if(arr[mid]>x)
                j=mid-1;
            else i=mid+1;
        }
        
       return{ansF,ansL};
    }
    
};