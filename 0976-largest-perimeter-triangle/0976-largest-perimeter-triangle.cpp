class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto it:nums)
        {
            pq.push(it);
        }
        int a=0,b=0,c=0;
        while(pq.size()>=3)
        {
            
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            c=pq.top();
            pq.pop();
            if(a <c+b and b < c+a and c < a+b)
                return a+b+c;
            pq.push(b);
            pq.push(c);
        }
        return 0;
        
    }
};