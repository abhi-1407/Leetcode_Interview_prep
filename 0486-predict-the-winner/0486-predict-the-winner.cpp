class Solution {
    bool helper(int i,int j,vector<int> &nums,int s1,int s2,bool turn)
    {
        if(i>j)
        {
            return s1>=s2;
        }
        bool ans=false;
        if(turn)
        {
            ans=(helper(i+1,j,nums,s1+nums[i],s2,!turn)||helper(i,j-1,nums,s1+nums[j],s2,!turn));
        }
        else
        {
           ans=(helper(i+1,j,nums,s1,s2+nums[i],!turn)&&helper(i,j-1,nums,s1,s2+nums[j],!turn));     
        }
        return ans;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return helper(0,nums.size()-1,nums,0,0,true);
    }
};