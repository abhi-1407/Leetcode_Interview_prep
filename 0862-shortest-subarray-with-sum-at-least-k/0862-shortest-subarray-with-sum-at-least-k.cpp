class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
         int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq;
        int minLength = n + 1;

        for (int i = 0; i <= n; ++i) {
            // Remove all elements that make the subarray sum >= k
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            // Maintain monotonicity
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return minLength == n + 1 ? -1 : minLength;

    }
};