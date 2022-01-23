class Solution {
public:
    string fractionToDecimal(int num, int den) {
     unordered_map<long long,int>mp;
     int flag=0;
     if(num<0 && den>=0)
         flag=1;
    else if(num>0 && den<0){
        flag=1;
    }
       long long numerator=num;
       long long denominator=den;
        numerator=abs(numerator);
        denominator=abs(denominator);
        long long dividend=numerator/denominator;
        long long rem=numerator%denominator;
        string ans;
        ans=to_string(dividend);
        if(rem==0){
            if(flag==1)
            return "-"+ans;
            return ans;
        }
        ans.push_back('.');
        while(rem!=0){
            numerator =rem*10;
            if(mp.find(numerator)!=mp.end()){
                int pos=mp[numerator];
                ans=ans.substr(0,pos)+'('+ans.substr(pos)+')';
                break;
            }
            mp[numerator]=ans.size();
            dividend=numerator/denominator;
            ans.push_back(dividend+'0');
            rem=numerator%denominator;
            
        }
        if(flag==1){
            ans.insert(ans.begin(),'-');
        }
        return ans;
    }
};