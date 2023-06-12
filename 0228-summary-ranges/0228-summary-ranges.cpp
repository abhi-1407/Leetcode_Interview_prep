class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)
            return ans;
        int i=0,j=0;
        for(long long k=nums[0];k<=nums[nums.size()-1] && j<nums.size();k++)
        {
            if(nums[j]!=k)
            {
                string temp="";
                if(nums[i]!=nums[j-1])
                temp=to_string(nums[i])+"->"+to_string(nums[j-1]);
                else
                temp=to_string(nums[i]);   
                ans.push_back(temp);
                k=nums[j];
                i=j;
            }
            if(j==nums.size()-1)
            {
                string temp="";
                if(nums[i]!=nums[j])
                temp=to_string(nums[i])+"->"+to_string(nums[j]);
                else
                temp=to_string(nums[i]);   
                ans.push_back(temp);
            }
            j++;
        }
        return ans;
    }
};