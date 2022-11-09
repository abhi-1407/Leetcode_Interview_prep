/* We keep popping elements till we find a larger element, and then we push this new entry into the stack, also once we have popped the new element would never need it again so there's no need to push it into the stack again (think abt this a bit) */
class StockSpanner {
      stack<pair<int,int>> st;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int ans=0;
        while(!st.empty())
        {
            if(st.top().first <= price)
            {
                ans+=st.top().second;
                st.pop();                
            } 
            else
            {
                break;
            }
        }
        st.push({price,ans+1});
        return ans+1;  
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */