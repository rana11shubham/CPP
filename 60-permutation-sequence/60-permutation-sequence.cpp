class Solution {
public:
    // vector<string>ans;
    // void generate_permutation(string s,int idx)
    // {
    //     if(idx==s.length())
    //     {
    //         ans.push_back(s);
    //         return;
    //     }
    //     for(int i=idx;i<s.length();i++){
    //         swap(s[idx],s[i]);
    //         generate_permutation(s,idx+1);
    //         swap(s[idx],s[i]);
    //     }
    // }
    string getPermutation(int n, int k) {
        // string s="";
        // for(int i=1;i<=n;i++)
        //     s+=('0'+i);
        // generate_permutation(s,0);
        // sort(ans.begin(),ans.end());
        // return ans[k-1];
        vector<int>num;
        int fact=1;
        for(int i=1;i<=n;i++){
            num.push_back(i);
            fact*=i;
        }
        fact=fact/n;
        string res="";
        k=k-1;
        while(true){
            res+=to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)
                break;
            k=k%fact;
            fact=fact/num.size();
        }
        return res;
    }
};