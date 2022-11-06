class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long i=0,j=costs.size()-1,ans=0;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        while(k--)
        {
            while(i<=j and pq1.size()<candidates)
            {
                pq1.push(costs[i++]);
            }
            while(j>=i and pq2.size()<candidates)
            {
                pq2.push(costs[j--]);
            }
            int a=pq1.size()==0 ? INT_MAX:pq1.top();//just in case if the top has nothing 
            int b=pq2.size()==0 ? INT_MAX:pq2.top();//just in case if the top has nothing 
            if(a<=b)
            {            
                ans+=pq1.top();
                pq1.pop();
            }
            else
            {
                ans+=pq2.top();
                pq2.pop();
            }
        }
        return ans;
        
    }
};