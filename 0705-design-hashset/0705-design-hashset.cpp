class MyHashSet {
    vector<int> temp;
public:
    MyHashSet() {
        temp.resize(1e6+1,0);
    }
    
    void add(int key) {
        if(temp[key]==0)
        temp[key]++;
    }
    
    void remove(int key) {
        if(temp[key]==1)
            temp[key]--;
    }
    
    bool contains(int key) {
        return temp[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */