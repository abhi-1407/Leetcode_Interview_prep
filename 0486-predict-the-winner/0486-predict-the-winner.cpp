class Solution {
    bool helper(int i,int j,vector<int> &nums,int s1,int s2,bool turn,vector<vector<vector<int>>> &dp)
    {
        if(i>j)
        {
            return s1>=s2;
        }
        bool ans=false;
        if(turn)
        {
            ans=(helper(i+1,j,nums,s1+nums[i],s2,!turn,dp)||helper(i,j-1,nums,s1+nums[j],s2,!turn,dp));
        }
        else
        {
           ans=(helper(i+1,j,nums,s1,s2+nums[i],!turn,dp)&&helper(i,j-1,nums,s1,s2+nums[j],!turn,dp));     
        }
        return ans;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        return helper(0,nums.size()-1,nums,0,0,true,dp);
    }
};