class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> ans(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<n;i++) {
            q.push({nums[i],i});
        }
        while(k--){
            auto num = q.top();
            q.pop();
            q.push({num.first*multiplier,num.second});
        }
        while(q.size()){
            auto it = q.top();
            q.pop();
            ans[it.second] = it.first;
        }
        return ans;
    }
};