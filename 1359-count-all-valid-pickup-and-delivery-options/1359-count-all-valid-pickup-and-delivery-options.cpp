class Solution {
const int mod = 1e9 + 7;
public:
    int countOrders(int n) {
        if(n == 1)
            return 1;
        else if (n == 2)
            return 6;
        long long res = 6;
        for(int i = 3; i <= n; i++)
        {
            res = (res * i * (2*i - 1))%mod;
        }
        return (int)res;
    }
};