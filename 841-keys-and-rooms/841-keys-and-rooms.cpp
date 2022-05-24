class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count=0;
        int n=rooms.size();
        vector<bool>visited(n,0);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        count++;
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            for(auto it:rooms[u]){
                if(!visited[it]){
                    visited[it]=true;
                    count++;
                    q.push(it);
                }
            }
        }
        return count==n;
    }
};