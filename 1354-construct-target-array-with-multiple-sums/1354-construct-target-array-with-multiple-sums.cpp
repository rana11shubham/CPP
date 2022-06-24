class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        if(n==1 && target[0]==1)
            return true;
        else if(n==1)
            return false;
        priority_queue<int>pq;
        unsigned int sum=0;
        for(int i:target){
            sum+=i;
            pq.push(i);
        }
        while (pq.top() != 1) {
            int x = pq.top();
            pq.pop();
            sum-=x;
            if (x<= sum || sum < 1) return false;
            x%= sum;
            sum+=x;
            pq.push(x?x: sum);
        }
        return true;
           
        }
};