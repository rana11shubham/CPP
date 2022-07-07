// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    vector<cpp_int>vc;
   cpp_int solve(int n){
       // Base case
       if(n<=1)
        return 1;
       cpp_int ans=0;
       if(vc[n]!=-1)
            return vc[n];
       for(int i=1;i<=n;i++){
           ans+=solve(i-1)*solve(n-i);
       }
       return vc[n]= ans;
   }
    cpp_int findCatalan(int n) 
    {   cpp_int ans=0;
        vc.resize(n+1,-1);
        return solve(n);
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends