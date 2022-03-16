class Solution {
public:
    #define INF 1000000007
    int jump(vector<int>& A) {
       int n=A.size();
        if(n==1)
            return 0;
       int curr_pos=A[0],next_pos=A[0];
        int jump=1;
        for(int i=1;i<n;i++){
            if(curr_pos<i){
                jump++;
                curr_pos=next_pos;
            }
            next_pos=max(next_pos,A[i]+i);
        }
        return jump;
    }
};