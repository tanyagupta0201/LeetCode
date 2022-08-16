class LRUCache {
public:
    
    class node 
    {
       public:
         int key, val;
         node *prev, *next;
        
         // constructor
         node(int _key, int _val)
         {
             key = _key;
             val = _val;
         }
    };
    
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    int cap; // capacity
    
    unordered_map<int, node*> mp; // key-node
        
    // initial set up for doubly linked list
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    // new node is always inserted after the head
    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;       
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node *delNode)
    {
        node *delprev = delNode->prev;
        node *delnext = delNode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key)
    {
        // if the key exists in the map
        if(mp.find(key) != mp.end())
        {
            // extract the node
            node *resNode = mp[key];
            int res = resNode->val;
            
            // Since we have got the key, it becomes LRU
            // So, delete it and add it to the front that is after head
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            
            mp[key] = head->next;
            
            // return the value present at that key
            return res;
        }
        
        // if the key does not exists, return -1
        return -1;
    }
    
    void put(int key, int value)
    {
        // Case 1
        // if the key already exists with some other value, update it with new value
        // first delete it and add it to the front and then give the new value
        if(mp.find(key) != mp.end())
        {
            node *existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        
        // Case 2
        // if the key is not present but the capacity is full
        if(mp.size() == cap)
        {
            // Remove LRU
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        // now add the node
        addNode(new node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */