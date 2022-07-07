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
        int n1=left.size();
        int n2=right.size();
        
        double median=getMedian();
        if(n1==0 and n2==0){
            left.push(x);
        }
        else if(n1==n2){
            if(median>x){
                left.push(x);
            }
            else{
                right.push(x);
            }
        }
        else if(n1>n2){
            if(median>x){
                right.push(left.top());
                left.pop();
                left.push(x);
            }
            else{
                right.push(x);
            }
        }
        else{
            if(median>x){
                left.push(x);
            }
            else{
                left.push(right.top());
                right.pop();
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
        int n1=left.size();
        int n2=right.size();
        if(n1==0 and n2==0){
            return 0.0;
        }
        else if(n1>n2){
            return left.top();
        }
        else if(n1<n2){
            return right.top();
        }
        
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