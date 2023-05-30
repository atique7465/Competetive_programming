class MyHashSet {
    unordered_map<int, bool> mp;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        mp[key] = true;
    }
    
    void remove(int key) {
        if(mp.find(key) != mp.end()) mp.erase(key);
    }
    
    bool contains(int key) {
        if(mp.find(key) != mp.end()) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */