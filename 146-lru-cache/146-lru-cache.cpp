class Node{
  public:
    int key;
    int val;
    Node* prev;
    Node* next;
};

class LRUCache {
public: 
    unordered_map<int,Node*>lru;
    int s;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
    s=capacity;
    head=new Node();
    tail=new Node();
    head->next=tail;
    tail->prev=head;
    }
    
    void addNode(Node* &node){
        Node*temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }
    
    void deleteNode(Node* &node){
        if(node->prev){
            node->prev->next=node->next;
        }
        if(node->next){
            node->next->prev=node->prev;
        }
        node->next=0;
        node->prev=0;
    }
    int get(int key) {
        if(lru.find(key)==lru.end())
            return -1;
        Node* temp=lru[key];
        if(temp!=0){
            int ans=temp->val;
            deleteNode(temp);
            addNode(temp);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
          Node* node=lru[key];
            if(node!=0){
                node->val=value;
                deleteNode(node);
                addNode(node);
                return;
            }
            Node* newNode=new Node();
            newNode->key=key;
            newNode->val=value;
            lru[key]=newNode;
            addNode(newNode);
            if(s>0){
                s--;
                return;
            }
            if(s==0){
                Node* tailNode=tail->prev;
                deleteNode(tailNode);
                lru[tailNode->key]=0;
                return;
            }
        }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */