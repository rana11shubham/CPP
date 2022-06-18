class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int i=0,j=n-1;
        char ans='1';
        while(i<=j){
            int mid=i+(j-i)/2;
            if(letters[mid]<=target)
            {
                i=mid+1;
            }
            else{
                ans=letters[mid];
                j=mid-1;
            }
        }
        if(ans=='1'){
            if(letters[0]==target)
                return letters[n-1];
            else return letters[0];
        }
        return ans;
    }
};