class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int count = 0,prod = 1;
        for (int low = 0, high = 0; high < nums.size(); high++) {
            prod *= nums[high];
            while (low <= high && prod >= k) {
                prod /= nums[low++];
            }
            count += (high - low + 1);
        }
        return count;
    }
};