class Solution {
public:
    unordered_set<string>mp;
    long long distinctNames(vector<string>& ideas) {
        long long count=0;
        long long arr[26][26]={0};
        long charac[26]={0};
        for(auto it:ideas){
            charac[it[0]-'a']=1;
            mp.insert(it);
        }
        for(auto it:ideas){
            char temp=it[0];
            for(int i=0;i<26;i++){
                if(charac[i]==1){
                    it[0]=(i+'a');
                    if(mp.find(it)==mp.end()){
                        arr[temp-'a'][i]++;
                    }
                    it[0]=temp;
                }
            }
        }
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                count+=arr[i][j]*arr[j][i];
        return count;
    }
};