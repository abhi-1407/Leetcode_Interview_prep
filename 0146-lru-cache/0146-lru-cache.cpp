class LRUCache {      
    public:
    int capacity,size;
    unordered_map<int,list<pair<int,int>> :: iterator>mpp;
    list<pair<int,int>> dll;
    
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        size=0;
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end())
            return -1;
        int val=mpp[key]->second;
        dll.erase(mpp[key]);
        dll.push_front({key,val});
        mpp[key]=dll.begin();
        return val;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            dll.erase(mpp[key]);
            dll.push_front({key,value});
            mpp[key]=dll.begin();
        }
        else
        {
            if(size==capacity)
            {
                auto it=dll.back();
                mpp.erase(it.first);
                dll.pop_back();
                dll.push_front({key,value});
                mpp[key]=dll.begin();
                
            }
            else
            {
                size++;
                dll.push_front({key,value});
                mpp[key]=dll.begin();
            }
        }
    }
};