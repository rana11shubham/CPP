class Solution {
public:
    int findNthDigit(int n) {
        long long range=9;
        long long i=1;
        long digit=1;
        while(range<n){
            digit++;
            i*=10;
            range+=((long long)9*i*digit);  
        }
        int temp_digit=1;
        i=1;
        while(temp_digit<digit){
            n-=(9*temp_digit*i);
            i*=10;
            temp_digit++;
        }
        cout<<n<<endl;
        //long long start=pow(10,digit-1);
        int index = (n-1) % digit;
        int offset = (n-1) / digit;
        long start = pow(10, digit - 1);
        return to_string(start + offset)[index] - '0';
        
        
    }
};