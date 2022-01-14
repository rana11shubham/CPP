class Solution {
public:
    bool isValid(vector<int>arr,int X,int m,int k){
        int flower=0,bouq=0;
        for(auto it:arr){
            if(it<=X){
                flower++;
            }
            else{
                flower=0;
            }
            if(flower==k){
                bouq++;
                flower=0;
            }
            if(bouq==m){
                return true;
            }
        }
        return bouq==m?true:false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m*k >n){ // Base condition
            return -1;
        }
        int s=INT_MAX,e=INT_MIN,ans=-1;
        for(auto it:bloomDay)
            s=min(it,s),e=max(e,it);
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isValid(bloomDay,mid,m,k)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};