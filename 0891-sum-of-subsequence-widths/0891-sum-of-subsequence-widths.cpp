class Solution {
    int mod=pow(10,9)+7;
public:
    int sumSubseqWidths(vector<int>& nums) {
        long long n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        vector<long long> power(n,1);
        for(int i=1;i<n;i++)
            power[i]=(power[i-1]*2)%mod;
        for(int i=0;i<n;i++)
        {
            long long left=((power[i])%mod*(nums[i]%mod))%mod;
            long long right=((power[n-i-1])%mod*(nums[i]%mod))%mod;
            ans=(ans+left-right)%mod;
        }
        return ans;
    }
};