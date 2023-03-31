
class Solution {
public:
    int MOD=1e9+7;
    bool doesContainApples(vector<string> &pizza, int startX, int startY, int endX, int endY) {
        for (int x=startX; x<=endX; x++) {
            for (int y=startY; y<=endY; y++) {
                if (pizza[x][y] == 'A') return true;
            }
        }
        return false;
    }
    int dp(vector<string>& pizza, int startX, int startY, int endX, int endY, int k, vector<vector<vector<int>>> &memo) {
        if (k==0) return 1;
        if (memo[startX][startY][k] != -1) return memo[startX][startY][k];
        long long count = 0;
        for (int cut=startX; cut<=endX; cut++) { // Horizontal cut
            if (doesContainApples(pizza, startX, startY, cut-1, endY) && doesContainApples(pizza, cut, startY, endX, endY)) 
                count += dp(pizza, cut, startY, endX, endY, k-1, memo)%MOD;
        }
        for (int cut=startY; cut<=endY; cut++) { // Vertical cut
            if (doesContainApples(pizza, startX, startY, endX, cut-1) && doesContainApples(pizza, startX, cut, endX, endY)) 
                count += dp(pizza, startX, cut, endX, endY, k-1, memo)%MOD;
        }
        return memo[startX][startY][k] = count%MOD;
    }
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m=pizza[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return dp(pizza, 0, 0, n-1, m-1, k-1, memo);
    }
};