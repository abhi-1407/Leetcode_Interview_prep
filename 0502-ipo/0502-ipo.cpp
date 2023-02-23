class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int,int>> temp;
        for(int i=0;i<profits.size();i++)
        {
            temp.push_back({capital[i],profits[i]});
        }
        sort(temp.begin(),temp.end());
        int total=0,index=0;
        while(k)
        {
            while(index<profits.size() && temp[index].first<=w)
            {
                pq.push(temp[index].second);
                index++;
            }
            if(pq.empty())
                break;
            w+=pq.top();
            pq.pop();
            k=k-1;
        }
        return w;       
    }
};