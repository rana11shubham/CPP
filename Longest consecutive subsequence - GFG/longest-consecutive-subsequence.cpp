// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int N)
    {
      unordered_map<int,int>mp;
        
        for(int i=0;i<N;i++){
            mp[nums[i]]=1;
        }
        int count =0;
        for(int i=0;i<N;i++){
            int temp=nums[i];
            int count_temp=1;
            if(mp.find(temp-1)==mp.end()){
                int j=temp+1;
                while(mp.find(j)!=mp.end()){
                    temp++;
                    j=j+1;
                    count_temp++;
                }
                count=max(count,count_temp);
            }
            else{
                continue;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends