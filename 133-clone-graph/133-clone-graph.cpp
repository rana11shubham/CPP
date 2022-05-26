/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        queue<Node*>q;
        unordered_map<Node*,Node*>mp;
        mp[node]=new Node(node->val);
          q.push(node);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            vector<Node*>adj;
            for(auto x:it->neighbors){
                if(mp.find(x)!=mp.end()){ // SUppose it is already present in the map
                   adj.push_back(mp[x]);
                    mp[it]->neighbors.push_back(mp[x]);
                }
                else{
                    q.push(x);
                    mp[x]=new Node(x->val);
                     mp[it]->neighbors.push_back(mp[x]);
                }
            }
        }
        return mp[node];
    }
};