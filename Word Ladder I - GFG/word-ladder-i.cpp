// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    unordered_map<string,bool>mp;
    set<string>word;
    void helper(string s,queue<string>&q){
        for(int i=0;i<s.length();i++){
            for(int j=0;j<26;j++){
                char c=j+'a';
                string temp=s.substr(0,i)+c+s.substr(i+1);
                if(word.find(temp)!=word.end() && !mp[temp]){
                    q.push(temp);
                    mp[temp]=true;
                }
            }
        }
    }
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
       for(auto it:wordList)
       {
           mp[it]=false;
           word.insert(it);
       }
       if(word.find(targetWord)==word.end())
        return 0;
       int count=1;
       queue<string>q;
       q.push(startWord);
       mp[startWord]=true;
       while(!q.empty()){
           int n=q.size();
           for(int i=0;i<n;i++){
               auto it=q.front();
               q.pop();
               if(it==targetWord)
                    return count;
               helper(it,q);
           }
           count++;
       }
       return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends