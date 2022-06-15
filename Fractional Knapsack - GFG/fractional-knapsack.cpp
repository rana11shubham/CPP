// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(pair<double,Item> s1,pair<double,Item> s2){
        return s1.first>s2.first;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>>profit;
        for(int i=0;i<n;i++){
            Item it;
            it.value=arr[i].value;
            it.weight=arr[i].weight;
            profit.push_back({(double)arr[i].value/arr[i].weight,it});
        }
        double ans=0;
        sort(profit.begin(),profit.end(),comp);
        for(int i=0;i<n;i++){
            if(profit[i].second.weight<=W){
                ans+=profit[i].second.value;
                W-=profit[i].second.weight;
            }
            else if(W>0 && profit[i].second.weight>W){
                ans+=(profit[i].first)*(W);
                break;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends