class Solution {
public:
    // int maxProduct(vector<int>& nums) {
    //     int max_overall=nums[0];
    //     int max_here=nums[0];
    //     int min_here=nums[0];
    //     for(int i=1;i<nums.size();i++)
    //     { 
    //         int temp=max_here;
    //         max_here=max({nums[i],nums[i]*max_here,nums[i]*min_here});//{} is mandatory if no. of variables is more than two
    //         min_here=min({nums[i],nums[i]*temp,nums[i]*min_here});
    //         max_overall=max(max_overall,max_here);
    //     }
    //     return max_overall;
    // }
    int maxProduct(vector<int>& nums)
    {
        int n=nums.size();
        int lmax=INT_MIN,rmax=INT_MIN,prod=1;
        for(int i=0;i<n;i++)
        {            
            prod*=nums[i];
            lmax=max(lmax,prod);
            if(prod==0)
                prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--)
        {
            prod*=nums[i];
            rmax=max(rmax,prod);
            if(prod==0)
                prod=1;
        }
        return max(rmax,lmax);
    }
};