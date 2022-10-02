class LRUCache {
public:
    
    class node {
        
        public :
        int key ;
        int val ;
        node* next ;
        node* prev ;
        node(int _key, int _val) {
            
            key = _key ;
            val = _val ;
        }
    } ;
    node* head = new node(-1,-1) ;
    node* tail = new node(-1,-1) ;
    
    int cap ; // total item in cache allowed.
    unordered_map<int,node*>m ;
    
    LRUCache(int capacity) {
        cap = capacity ;
        head -> next = tail  ;
        tail-> prev = head ;
    }
    
    void addnode(node* newnode) {
        
        // store the address of next node first else we will lose it
        node* nextnode = head->next ;
        
        head->next = newnode ;
        newnode->prev = head ;
        
        newnode->next = nextnode ;
        nextnode->prev = newnode ;
    }
    
    void deletenode(node* delnode) {

        // i just need to know the address of prev node and next node of my delete node
        // i will just join them , right ? 
        
        node* prevdel = delnode->prev ;
        node* nextdel = delnode->next ;
        
        prevdel->next = nextdel ;
        nextdel->prev = prevdel ;
        // delete delnode ;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) { // that means key is present in cache
            
            node* nodeAddress = m[key] ;
            int res = nodeAddress->val ; // stored the value of the key
            
            // now erase that key from map as now this is last recently used 
            // so this will have new address , right ? . it will present just next to head
            // node
            
            m.erase(key) ;
           
            // delete that key of that node from the doubly LL
            deletenode(nodeAddress) ;
            
            // add that node to next to head 
             addnode(nodeAddress) ;
            
            // add the key and its new address in the map 
            m[key] = head->next ;
            
            return res ;
            
        }
        return  -1 ; // if not found in map 
        
    }
    
    void put(int key, int value) {
        
        // check if that key already exists 
        // if exists , then remove it from map and LL so that we can add
        //  this key val pair in the map and LL
        
        if(m.find(key) != m.end()) {  // key exist already
            
            // store its address(needed to delete its node from LL)
            // to delte from map , we only require key 
            
            node* existingNodeAddress = m[key] ;
            m.erase(key) ;
            deletenode(existingNodeAddress) ;
        }
        
        // check if map is already full
        if(m.size() == cap) {
          
           // to clear space in cache , remove least recently used item and that is 
           // present left to tail fr  om cache(map) and from LL.
           
            m.erase(tail->prev->key) ;
            
            // now also delete it from LL
            deletenode(tail->prev) ;       
        }
         addnode(new node(key,value)) ; // added in LL
          m[key] = head->next ;          // added in cache(map).
         
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
