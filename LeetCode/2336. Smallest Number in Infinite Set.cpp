class SmallestInfiniteSet {
    unordered_map<int, bool> mp;
    priority_queue<int> pq;
    int currentInt;
public:
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++){
            pq.push(i * -1);
            mp[i] = true;
        }
    }
    
    int popSmallest() {
        int num = pq.top() * -1; pq.pop();
        mp[num] = false;
        return num;
    }
    
    void addBack(int num) {
        if(mp.find(num) == mp.end() || mp[num] == false){
            pq.push((-1) * num);
            mp[num] = true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */