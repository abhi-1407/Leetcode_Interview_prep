class SnapshotArray {
    vector<map<int,int>> arr;
    int snaps;
public:
    SnapshotArray(int length) {
        arr.resize(length);
        for(int i=0;i<arr.size();i++)
        {
            arr[i][0]=0;
        }
        snaps=0;
    }
    
    void set(int index, int val) {
        arr[index][snaps]=val;
    }
    
    int snap() {
        
        snaps++;
        return snaps-1;
    }
    
    int get(int index, int snap_id) {
        if(arr[index].find(snap_id) == arr[index].end())
        {
            auto it = --arr[index].lower_bound(snap_id);
            return it->second;
        }
        return arr[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */