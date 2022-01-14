class Solution {
public:
    bool isValid(vector<int>&arr,int X,int n,int k){
        int quotient=0;
        for(auto it:arr){
          int temp=ceil(it/X);
          if(temp<(double)it/X){
              temp+=1;
          }
          quotient+=temp;
           if(quotient>k)
               return false;
        }
       
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
           int n=nums.size();
        int s=1,e=INT_MIN,ans=-1;
        for(auto it:nums)
           e=max(e,it);
        while(s<=e){
            int mid=s+(e-s)/2;
            //cout<<mid<<endl;
            if(isValid(nums,mid,n,threshold)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    } 
    
};