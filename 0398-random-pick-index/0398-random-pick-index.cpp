class Solution {
    unordered_map<int,vector<int>> mpp;
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> ans=mpp[target];
        int index=rand()%(ans.size());
        return ans[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */