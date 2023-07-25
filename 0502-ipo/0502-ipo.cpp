class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int ind=0;
        priority_queue<int> pq;
        while(k)
        {
            while(ind<n && vec[ind].first<=w)
            {
                pq.push(vec[ind].second);
                ind++;
            }
            if(!pq.empty())
            {
                w+=pq.top();
                pq.pop();
            }
            k--;
        }
        return w;
              
    }
};