class LRUCache {
public:
    int capacity;
    list<int>lru;
    unordered_map<int, pair<int, list<int>::iterator>>mp;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // If element is not found
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        lru.erase(mp[key].second);
        lru.push_front(key);
        mp[key].second = lru.begin();
        return mp[key].first;   
    }
    
    void put(int key, int value) {
        // If we reach the size limit
        if (mp.find(key) != mp.end()) {
            lru.erase(mp[key].second);
        }else if (lru.size() == capacity) {   
            int lru_key  = lru.back();
            lru.pop_back();
            mp.erase(lru_key);
        }
        lru.push_front(key);
        mp[key] = {value, lru.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */