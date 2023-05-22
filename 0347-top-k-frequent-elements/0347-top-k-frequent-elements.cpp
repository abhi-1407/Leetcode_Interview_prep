class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }        
        priority_queue<pair<int,int>> pq;
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
 
        }
        return ans;
        
        
    }
};