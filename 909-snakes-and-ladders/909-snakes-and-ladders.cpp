class Solution {
public:
    unordered_map<int,int>mp;
    int snakesAndLadders(vector<vector<int>>& board) {
        mp.clear();
        int n=board.size();
        int count=1;
        if(n%2==0){
        for(int i=n-1;i>=0;i--){
            if(i%2==0)
                count+=n-1;
            for(int j=0;j<n;j++){
                if(i%2==0){
                    if(board[i][j]!=-1){
                        mp[count]=board[i][j];
                    }
                     if(j==n-1){
                        count=count+n+1;
                    }
                    count--;
                   
                }
                else{
                    if(board[i][j]!=-1){
                        mp[count]=board[i][j];
                    }
                    count++;
                }
                
            }
        }
    }
        else{
            for(int i=n-1;i>=0;i--){
            if(i%2==1)
                count+=n-1;
            for(int j=0;j<n;j++){
                if(i%2==1){
                    if(board[i][j]!=-1){
                        mp[count]=board[i][j];
                    }
                     if(j==n-1){
                        count=count+n+1;
                    }
                    count--;
                    
                }
                else{
                    if(board[i][j]!=-1){
                        mp[count]=board[i][j];
                    }
                    count++;
                   
                }
                
            }
        }   
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        int s=(n*n)+1;
        vector<bool>vis(s,false);
        queue<int>q;
        q.push(1);
        vis[1]=true;
        int step=0;
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;i++){
                int it=q.front();
                q.pop();
                if(it==n*n){
                    return step;
                }
                for(int k=1;k<=6;k++){
                    int new_step=it+k;
                    if(new_step>n*n)
                        break;
                    if(mp.find(new_step)!=mp.end()){
                        if(!vis[mp[new_step]]){
                        q.push(mp[new_step]);
                        vis[mp[new_step]]=1;
                        }
                    }
                    else{
                        if(!vis[new_step]){
                            q.push(new_step);
                        vis[new_step]=1;
                    }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};