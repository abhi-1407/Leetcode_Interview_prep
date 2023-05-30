class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mod=pow(10,9)+7;
        int mini=nums[0];
        int res=(((1LL*nums[0]*nums[0])%mod)*nums[0])%mod;
        for(int i=1;i<nums.size();i++)
        {
            mini=((mini*2)%mod)-nums[i-1]+nums[i];
            res=(res+(((1LL*nums[i]*nums[i])%mod)*mini)%mod)%mod;
        }
        return res;
        
    }
};