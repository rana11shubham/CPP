class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i=32;
        int cnt=0;
        while(i--){
            uint32_t t=1;
            t&=n;
            if(t==1)
                cnt++;
            n>>=1;
        }
        return cnt;
    }
};