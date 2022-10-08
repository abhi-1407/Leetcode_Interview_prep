class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         int diff=INT_MAX;
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             int ele=nums[i];
//             int j=i+1,k=n-1;
//             while(j<k)
//             {
//                 if(ele+nums[j]+nums[k]==target)
//                 {
//                     return target;
//                 }
//                 else if(abs((ele+nums[j]+nums[k])-target)<diff)
//                 {
//                     diff=abs((ele+nums[j]+nums[k])-target);
//                     ans=ele+nums[j]+nums[k];
//                 }
//                 if((ele+nums[j]+nums[k])>target)
//                 {
//                     k--;
//                 }
//                 else
//                 {
//                     j++;
//                 }
                    
//             }
//         }
//         return ans;
//     }
        sort(nums.begin(),nums.end());
int ans=INT_MAX,mini=INT_MAX;
for(int i=0;i<nums.size();i++)
{
    int j=i+1,k=nums.size()-1;
    while(j<k)
    {
        if(nums[i]+nums[j]+nums[k]==target)
        {
            return target;
        }
        if(abs(target-(nums[i]+nums[j]+nums[k]))<mini)
        {
            ans=nums[i]+nums[j]+nums[k];
            mini=abs(target-(nums[i]+nums[j]+nums[k]));
        }
        if(nums[i]+nums[j]+nums[k]>target)
            k--;
        else
            j++;        
    }
    
}
return ans;
}
};

