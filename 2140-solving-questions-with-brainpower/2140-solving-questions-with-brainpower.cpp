class Solution {
    long long helper(long long index,vector<vector<int>>& questions,vector<long long> &dp)
    {
        if(index>=questions.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        long long pick=-1e9;
        pick=questions[index][0]+helper(questions[index][1]+index+1,questions,dp);
        long long notpick=helper(index+1,questions,dp);
        return dp[index]=max(pick,notpick);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return helper(0,questions,dp);
    }
};