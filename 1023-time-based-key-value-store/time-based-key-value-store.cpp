class TimeMap {
public:
    map<string, vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &v = mp[key];

        int low = 0;
        int high = v.size() - 1;
        int index = -1;

        while(low<=high) {
            int mid = low + (high - low)/2;
            if (v[mid].first <= timestamp) {
                index = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (index == -1) {
            return "";
        }

        return v[index].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */