class Solution {
    /* 10^8 never gets accepted */
//         int maxProduct(vector<int>& nums) {
//         int maxprod=INT_MIN;
//         for(int i=0;i<nums.size();i++)
//         {
//             int prod=1;
//             for(int j=i;j<nums.size();j++)
//             {
//                 prod*=nums[j];
//                 maxprod=max(maxprod,prod);
//             }
            
//         }
//         return maxprod;
//     }
public:
    int maxProduct(vector<int>& nums) {
        int maxprod1=INT_MIN,maxprod2=INT_MIN,prod=1;
        for(int i=0;i<nums.size();i++)
        {
            
            prod*=nums[i];
            maxprod1=max(maxprod1,prod);
            if(nums[i]==0)
                prod=1;
            
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            
            prod*=nums[i];
            maxprod2=max(maxprod2,prod);
            if(nums[i]==0)
                prod=1;
            
        }
        return max(maxprod1,maxprod2);
    }
    
};