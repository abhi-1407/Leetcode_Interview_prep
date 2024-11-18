class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN,curr = 0;
        for(auto it:nums){
            curr += it;
            maxSum = max(maxSum,curr);
            if(curr < 0)
                curr = 0;
        }
        return maxSum;
    }
};