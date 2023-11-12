class SnapshotArray {
   int id=0; 
   vector<map<int, int>> id_v;

public:
    SnapshotArray(int length) { 
        id_v.assign(length, {{0,0}});   
    }
    
    void set(int index, int val) {
        id_v[index][id]=val;
    }
    
    int snap() {
       return id++; 
    }
    
    int get(int index, int snap_id) {
        auto i = id_v[index].upper_bound(snap_id);
        i--;
        return  i->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */