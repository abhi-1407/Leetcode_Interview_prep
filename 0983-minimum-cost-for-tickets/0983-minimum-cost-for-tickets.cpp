
class Solution {

    int helper(vector<int> &days,vector<int> &costs,int index,vector<int> &dp)
    {
        if(index==days.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int oneday=1e9,sevendays=1e9,thirtydays=1e9;
        oneday=costs[0]+helper(days,costs,index+1,dp);
        int seven=(upper_bound(days.begin(),days.end(),days[index]+6)-days.begin());
        sevendays=costs[1]+helper(days,costs,seven,dp);
        int thirty=(upper_bound(days.begin(),days.end(),days[index]+29)-days.begin());
        thirtydays=costs[2]+helper(days,costs,thirty,dp);
        return dp[index]=min(oneday,min(sevendays,thirtydays));
        
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
     vector<int> dp(days.size(),-1);
     return helper(days,costs,0,dp);   
    }
};