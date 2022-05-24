class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        int count=0;
        vector<bool>visited(v+1,false);
        for(int i=1;i<=v;i++){
            if(!visited[i]){
                count++;
                queue<int>q;
                q.push(i);
                visited[i]=true;
                while(q.empty()!=true){
                    auto u=q.front();
                    q.pop();
                    for(int j=1;j<=v;j++){
                        if(isConnected[u-1][j-1] && !visited[j]){
                            q.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
        }
        return count;
    }
};