class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=INT_MAX;
        int sum1=0;
        int i=0,j=0;
        int sze=n-k;
        int s=0;
        s=accumulate(cardPoints.begin(),cardPoints.end(),s);
        cout<<s<<endl;
        if(k==n)
            return s;
        while(j<n){
            if(j-i+1==sze){
                sum1+=cardPoints[j];
                sum=min(sum1,sum);
                 cout<<sum<<endl;
                sum1-=cardPoints[i];
                j++;
                i++;
            }
            else{
                sum1+=cardPoints[j];
                j++;
            }
           
        }
        return s-sum;
    }
};