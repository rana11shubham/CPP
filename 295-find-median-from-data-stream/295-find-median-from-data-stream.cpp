class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int x) {
         int l_size=left.size();
        int r_size=right.size();
        double mid=findMedian();
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
    
    double findMedian() {
       double ans=0;
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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */