class Solution {
public:

    
    string longestPalindrome(string s) {
        int n=s.length();
        int max_len=0;
        int start=0;
       string best_string="";
        for(int mid=0;mid<n;mid++){
            for(int i=0;mid-i>=0 and mid+i<n;i++){
                if(s[mid-i]!=s[mid+i])
                    break;
                else{
                    int len=2*i+1;
                    if(max_len<len){
                        max_len=len;
                        best_string=s.substr(mid-i,max_len);
                    }
                }
            }
        }
        for(int mid=0;mid<n-1;mid++){
            for(int i=1;mid-i+1>=0 and mid+i<n;i++){
                if(s[mid-i+1]!=s[mid+i])
                    break;
                else{
                    int len=2*i;
                    if(max_len<len){
                        max_len=len;
                        best_string=s.substr(mid-i+1,max_len);
                    }
                }
            }
        }
        return best_string;
    }
};