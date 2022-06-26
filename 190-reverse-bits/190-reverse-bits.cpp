class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=32;
        uint32_t ans=0;
        while(i--){
            uint32_t a=1;
            a=a&n;
            a=a<<i;
            cout<<a<<endl;
            n=n>>1;
            ans|=a;
           // cout<<n<<endl;
        }
        return ans;
    }
};