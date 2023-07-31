class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + (int)s1[i - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsSum = dp[n1][n2];
        int s1Sum = 0;
        int s2Sum = 0;

        for (char c : s1) {
            s1Sum += (int)c;
        }

        for (char c : s2) {
            s2Sum += (int)c;
        }

        return s1Sum + s2Sum - 2 * lcsSum;
    }
};
