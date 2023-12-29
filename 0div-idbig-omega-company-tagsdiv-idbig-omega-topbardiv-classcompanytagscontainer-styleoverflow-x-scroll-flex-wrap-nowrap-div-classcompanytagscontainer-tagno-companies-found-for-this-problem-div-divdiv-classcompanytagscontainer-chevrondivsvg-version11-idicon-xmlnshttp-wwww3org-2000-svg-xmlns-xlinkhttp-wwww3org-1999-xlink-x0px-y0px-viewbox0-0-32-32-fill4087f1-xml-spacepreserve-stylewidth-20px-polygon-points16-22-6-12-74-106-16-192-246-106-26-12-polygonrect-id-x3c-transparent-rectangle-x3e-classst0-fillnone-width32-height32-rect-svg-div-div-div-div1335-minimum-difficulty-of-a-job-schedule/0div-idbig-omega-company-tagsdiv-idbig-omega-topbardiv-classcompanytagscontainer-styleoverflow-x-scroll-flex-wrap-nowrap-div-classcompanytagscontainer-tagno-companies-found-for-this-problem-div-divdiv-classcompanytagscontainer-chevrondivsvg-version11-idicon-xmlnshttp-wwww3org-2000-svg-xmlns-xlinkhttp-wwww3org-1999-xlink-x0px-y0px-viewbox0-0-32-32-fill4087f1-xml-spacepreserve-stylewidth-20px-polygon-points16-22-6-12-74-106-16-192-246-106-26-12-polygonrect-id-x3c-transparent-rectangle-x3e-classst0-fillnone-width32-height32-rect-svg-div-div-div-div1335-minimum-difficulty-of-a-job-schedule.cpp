class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& jd, int i, int d) {
        
        if(n-i < d || d == 0)    return INT_MAX;
        if(d == 1)    return dp[i][d] = *max_element(jd.begin()+i, jd.end());
        
        if(dp[i][d] != INT_MAX)  return dp[i][d];

        int ans = 0, curr = 0;

        for(int j=i; j<n; j++) {
            ans = solve(jd,j+1,d-1);
            if(ans == INT_MAX)  break;
            curr = max(curr, jd[j]);
            dp[i][d] = min(dp[i][d], curr + ans);
        }

        return dp[i][d];
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        n = jobDifficulty.size();
        dp = vector (n, vector<int> (d+1,INT_MAX));

        int ans = solve(jobDifficulty,0,d);

        return ans == INT_MAX ? -1 : ans;
    }
};