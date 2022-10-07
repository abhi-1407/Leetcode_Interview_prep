class MyCalendarThree {
    map<int,int> mpp;
    int maxi=0;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mpp[start]++;
        mpp[end]--;
        int count=0;
        for(auto it: mpp)
        {
            count+=it.second;
            maxi=max(count,maxi);
        }
        return maxi;        
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */