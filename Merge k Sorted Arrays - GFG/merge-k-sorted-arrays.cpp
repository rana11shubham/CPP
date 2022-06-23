// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

class Pair{
    public: 
    int data;
    int row;
    int col;
    Pair(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};
class compare{
        public:
        bool operator()(Pair &p1,Pair &p2){
            return p1.data>p2.data;      
        }
    };
class Solution
{ 
    public:
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Pair,vector<Pair>,compare>pq;
        for(int i=0;i<K;i++){
            Pair p(arr[i][0],i,0);
            pq.push(p);
        }
        vector<int>result;
        while(pq.size()>0){
            auto it=pq.top();
            pq.pop();
            result.push_back(it.data);
            int new_idx=it.col+1;
            if(new_idx<K){
                pq.push( Pair(arr[it.row][new_idx],it.row,new_idx));
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends