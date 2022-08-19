class Solution {
public:
    bool isPossible(vector<int>& nums) {
       unordered_map<int,int> mpp1;
       unordered_map<int,int> mpp2;
       for(auto it:nums)
       {
           mpp1[it]++;
       }
       for(int i=0;i<nums.size();i++)
       {
           if(mpp1[nums[i]]==0)
               continue;
           mpp1[nums[i]]--;
           if(mpp2[nums[i]-1] > 0)
           {
               mpp2[nums[i]-1]--;
               mpp2[nums[i]]++;
           }
           else if(mpp1[nums[i]+1]!=0 and mpp1[nums[i]+2]!=0)
           {
               mpp1[nums[i]+1]--;
               mpp1[nums[i]+2]--;
               mpp2[nums[i]+2]++;
           }
           
           else
           {
               cout<<nums[i]<<" "<<i<<endl;
               return false;
           }
       }
        return true;
           
    }
};