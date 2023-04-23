class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size(), i = 0;
        unordered_map<int, int> m;
        vector<int> ans;
        
        for(int j=0; j<n; j++) {
            m[nums[j]]++;
            if(j - i + 1 == k) {
                int cnt = x, f = 1;
                for(int val=50; val>=1; val--) {
                    if(m.find(-val) != m.end()) {
                        cnt -= m[-val];
                        if(cnt <= 0) {
                            ans.push_back(-val);
                            f = 0;
                            break;
                        }
                    }
                }
                if(f) ans.push_back(0);
                m[nums[i]]--;
                if(m[nums[i]]==0)
                    m.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};