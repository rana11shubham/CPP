class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<n;i++){
            if(heights[i]-heights[i-1]>0){
                pq.push(heights[i]-heights[i-1]);
                if(pq.size()>ladders){
                    int x=pq.top();
                    pq.pop();
                    bricks-=x;
                    if(bricks<0){
                        cout<<i-1<<endl;
                        return i-1;
                    }
                   
                        
                        
                }
            }
        }
            return n-1;
        
        
    }
};