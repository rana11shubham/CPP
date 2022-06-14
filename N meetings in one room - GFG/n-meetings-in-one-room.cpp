// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{   struct room{
    int start_time;
    int end_time;
    int meeting_number;
};
    public:
    // static bool comp(struct room room1,struct room room2){
    //     if(room1.end_time<room2.end_time)
    //         return true;
    //     else if(room1.end_time>room1.end_time)
    //         return false;
    //     else if(room1.meeting_number<room2.meeting_number)
    //         return true;
    //     return false;
    // }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {  
        // struct room room1[n+1];
        vector<pair<int,int>>room1;
        for(int i=0;i<n;i++){
            room1.push_back({end[i],start[i]});
        }
        sort(room1.begin(),room1.end());
        int limit=room1[0].first;
        int count=1;
        for(int i=1;i<n;i++){
            if(room1[i].second>limit){
                 count++;
                limit=room1[i].first;
            }
            
        }
        return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends