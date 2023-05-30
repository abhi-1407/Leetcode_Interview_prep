class MyHashSet {
    unordered_map<int,int> mpp;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        if(mpp[key]==1)
        return;
        mpp[key]++;
    }
    
    void remove(int key) {
        if(mpp[key]==1)
        mpp[key]--;
    }
    
    bool contains(int key) {
        return mpp[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */