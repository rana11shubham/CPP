class Solution {
public:
    vector<vector<int>>dp;
    static bool comp(vector<int>&a,vector<int>&b){
            if(a[1]<b[1])
                return true;
            else if(a[1]==b[1])
                return a[0]<b[0];
            return false;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(),comp);
        priority_queue<pair<int,int>>pq;
        int time=0,count=0;
        for(auto it:courses){
           pq.push({it[0],it[1]});
            time+=it[0];
            if(time>it[1]){
                time-=pq.top().first;
                pq.pop();
            }
           
        }
        return pq.size();
        
    }
};