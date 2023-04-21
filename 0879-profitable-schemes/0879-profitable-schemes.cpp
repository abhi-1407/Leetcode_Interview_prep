//always try to reduce your values else it would be very diff to memoize if large no of combinations are possible
class Solution {
    int mod=pow(10,9)+7;
    int helper(int index,vector<pair<int,int>> &vec,int cap,int prof,vector<vector<vector<int>>> &dp)
    {
        if(index==vec.size())
        {
            if(prof<=0 && cap>=0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[index][cap][prof]!=-1)
            return (dp[index][cap][prof])%mod;
        int p=(vec[index].first)%mod;
        int s=(vec[index].second)%mod;
        int pick=0,notpick=0;
        if(s<=cap)
        {
            pick=(helper(index+1,vec,cap-s,prof-p<0?0:prof-p,dp))%mod;
        }
        notpick=(helper(index+1,vec,cap,prof,dp))%mod;
        return dp[index][cap][prof]=(pick%mod+notpick%mod)%mod;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<pair<int,int>> vec;
        vector<vector<vector<int>>>dp(profit.size()+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        for(int i=0;i<group.size();i++)
            vec.push_back({profit[i],group[i]});
        return helper(0,vec,n,minProfit,dp);
        
    }
};