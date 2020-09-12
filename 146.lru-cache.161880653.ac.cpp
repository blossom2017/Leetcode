class LRUCache {
public:
    struct dllnode
    {
      int key;
        int value;
        dllnode * pre;
        dllnode * post;
    };
    int cap;
    int count=0;
    dllnode * head ;
    dllnode * tail;
    map<int,dllnode*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head = new dllnode;
        tail = new dllnode;
        head->pre = NULL;
        head->post = tail;
        tail->pre = head;
        tail->post = NULL;
        
        
    }
    void addnode(dllnode * node)
    {
        node->pre = head;
        node->post = head->post;
        head->post->pre = node;
        head->post=node;
    }
    dllnode * remove(dllnode * node)
    {
        dllnode * prev = node->pre;
        dllnode* next = node->post;
        prev->post = next;
        next->pre = prev;
        return node;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            dllnode * x=remove(mp[key]);
            addnode(x);
             return mp[key]->value;
        }
            
           
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            mp[key]= new dllnode;
            mp[key]->value= value;
            mp[key]->key = key;
            addnode(mp[key]);
            count++;
            cout<<"hhhh"<<key<<" ";
            if(count>cap)
            {
                cout<<"lll"<<count<<" "<<cap;
                count--;
               dllnode* x =remove(tail->pre);
                cout<<x->key<<" ";
                mp.erase(x->key);
            }
        }
        else 
        {
            cout<<"hereee";
            mp[key]->value= value;
            dllnode * x = remove(mp[key]);
            addnode(x);
            
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
