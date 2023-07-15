class Solution {
        int helper(int idx,vector<vector<int>>& events,int k,vector<int> &start,vector<vector<int>> &dp)
        {
            if(idx>=events.size() || k==0)
            return 0;
            if(dp[idx][k]!=-1)
                return dp[idx][k];
            int i=upper_bound(start.begin(),start.end(),events[idx][1])-start.begin();
            int op1=helper(idx+1,events,k,start,dp);
            int op2=events[idx][2]+helper(i,events,k-1,start,dp);
            return dp[idx][k]=max(op1,op2);
            
        }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        vector<int> start;
        for(auto it: events){
            start.push_back(it[0]);
        }
        return helper(0,events,k,start,dp);
    }
};