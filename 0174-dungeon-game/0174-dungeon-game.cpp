class Solution {
    int helper(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>> &dp)
    {
        if(i>=dungeon.size()||j>=dungeon[0].size())
            return INT_MAX;
        if(i==dungeon.size()-1 && j==dungeon[0].size()-1){
             return dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int health=min(helper(i+1,j,dungeon,dp),helper(i,j+1,dungeon,dp));
        if(health==INT_MAX)
            return 1;
        return dp[i][j]=health-dungeon[i][j] >0 ? health-dungeon[i][j] : 1;        
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size()==0||dungeon[0].size()==0)
            return 0;
        vector<vector<int>> dp(dungeon.size(),vector<int>(dungeon[0].size(),-1));
        return helper(0,0,dungeon,dp);
    }
};