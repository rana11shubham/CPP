// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    void insertHeap(int &x)
    {
        int l_size=left.size();
        int r_size=right.size();
        double mid=getMedian();
        if(l_size==r_size){
            if(mid>x){
                left.push(x);
            }
            else
                right.push(x);
        }
        else if(r_size>l_size){
            if(mid>x){
                left.push(x);
            }
            else{
                left.push(right.top());
                right.pop();
                right.push(x);
            }
        }
        else{
         if(mid>x){
                right.push(left.top());
                left.pop();
                left.push(x);
            }
            else{
                right.push(x);
            }
        }   
        }
    
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        double ans=0.0;
        int l_size=left.size();
        int r_size=right.size();
        if(l_size==0 and r_size==0)
            return ans;
        else if(l_size>r_size)
            return left.top();
        else if(r_size>l_size)
            return right.top();
        return (left.top()+right.top())/2.0;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends