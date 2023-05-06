class Solution {
    int mod=pow(10,9)+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1,ans=0;
        vector<int> pow;
        pow.push_back(1);
        for(int i=1;i<nums.size();i++)
        {
            pow.push_back((pow[i-1]*2)%mod);
        }
        while(l<=r)
        {
            if(nums[l]+nums[r]>target)
            {
                r--;
            }
            else
            {
                ans=(ans+pow[r-l]%mod)%mod;
                l++;
            }
        }
        return ans;
        
    }
};