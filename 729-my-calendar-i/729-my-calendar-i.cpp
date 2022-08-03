class MyCalendar {
    unordered_map<int,int> cal; //unordered map to store start and end dates
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        /* if the start of the event is in between a scheduled event or the end is in between a scheduled event or
        if both start and end are in between a scheduled event, in that case just return false */
        for(auto it:cal)
        {
            if((start < it.second && start >= it.first) || (start < it.first && end>=it.second) || (end<=it.second && end>it.first))
                return false;
        }
        cal[start]=end;//put the event into the map
        return true;//return true as the event has been scheduled successfully
        
            
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */