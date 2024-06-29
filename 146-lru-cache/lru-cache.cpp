#include <unordered_map>
#include <list>

class LRUCache {
public:
    int capacity;
    std::list<int> lru; // stores keys to maintain LRU order
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> mp; // stores key-value pairs and iterators to the LRU list

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1; // key not found
        }
        lru.erase(mp[key].second);
        lru.push_front(key);
        mp[key].second = lru.begin();
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            lru.erase(mp[key].second);
        } else if (lru.size() == capacity) {
            int lru_key = lru.back();
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
