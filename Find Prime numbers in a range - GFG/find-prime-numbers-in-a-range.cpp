// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    #define limit 1000000
    vector<int>primes;
    void generate_prime(int N){
        primes.resize(N+1,1);
        for(int i=2;i*i<=N;i++){
            if(primes[i]==1){
                for(int j=i*i;j<=N;j+=i){
                    primes[j]=0;
                }
            }
        }
    }
    vector<int>print_primes(int n){
        vector<int>ans;
        for(int i=2;i<=n;i++){
            if(primes[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> primeRange(int M, int N) {
        generate_prime(N+1);
        vector<int>output;
        // if(M==1)
        //     M+=1;
        // vector<int>prime=print_primes(sqrt(N));
        // int range=N-M+1;
        // vector<int>ans(range,0);
        // vector<int>output;
        // for(auto it:prime){
        //     int firstMultiple=(M/it)*it;
        //     if(firstMultiple<M)firstMultiple+=it;
        //     for(int i=max(firstMultiple,it*it);i<=N;i+=it){
        //         ans[i-M]=1;
        //     }
        // }
        // for(int i=M;i<=N;i++){
        //     if(ans[i-M]==0){
        //         output.push_back(i);
        //     }
        // }
        for(int i=max(2,M);i<=N;i++)
            if(primes[i]==1)
                output.push_back(i);
        
        return output;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends