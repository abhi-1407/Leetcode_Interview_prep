class TimeMap {

public:
    unordered_map<string,map<int,string>> obj;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        obj[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        
        auto it=obj[key].upper_bound(timestamp);
        if(it==obj[key].begin())
        return "";
        
        return prev(it)->second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */