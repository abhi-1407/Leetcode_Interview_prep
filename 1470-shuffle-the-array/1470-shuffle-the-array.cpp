class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(nums.size());
    int i=0,j=n,index=0;
    while(j<2*n)
    {
        ans[index++]=nums[i++];
        ans[index++]=nums[j++];
    }
    return ans;
    
    }
};