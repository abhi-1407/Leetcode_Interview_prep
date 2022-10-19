class Solution {
    struct comparator{
    bool operator()(pair<int,string> p1,pair<int,string> p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
};
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator> pq;
        vector<string> ans;
        for(auto it:words)
        {
            mpp[it]++;
        }
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }
        while(k--)
        {
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;        
    }
};