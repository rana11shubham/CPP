// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        unordered_map<char,vector<char>>mp;
        vector<int>inorder(K,0);
        vector<int>vis(K,0);
        string ans="";
        for(int i=0;i<N-1;i++){
            int j=i+1;
            string cur=dict[i];
            string next=dict[j];
            int cur_len=cur.length();
            int next_len=next.length();
            for(int k=0;k<min(cur_len,next_len);k++){
                if(cur[k]!=next[k]){
                    mp[cur[k]].push_back(next[k]);
                    inorder[next[k]-'a']++;
                    break;
                }
            }
        }
            // for(auto it:inorder)
            //     cout<<it<<endl;
            for(int i=0;i<K;i++){
                if(!vis[i]){
                    if(inorder[i]==0){
                        queue<int>q;
                        q.push(i);
                        vis[i]=1;
                       
                        while(!q.empty()){
                            auto u=q.front();
                            q.pop();
                            char temp=u+'a';
                           ans+=temp;
                            for(auto it:mp[temp]){
                                if(!vis[it-'a']){
                                    vis[it-'a']=1;
                                }
                                inorder[it-'a']--;
                                if(inorder[it-'a']==0){
                                    q.push(it-'a');
                                }
                            }
                        }
                    }
                }
            }
            
       // cout<<ans;
        return ans;
        
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends