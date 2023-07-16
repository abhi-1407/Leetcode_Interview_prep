class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),maxi=1,j=0,i=0;
        while(j<n)
        {
            if(nums[j]-nums[i] > 2*k )i++;
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};