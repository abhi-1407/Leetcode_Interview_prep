class Solution {
public:
    int findComplement(int num) {
        for(long long i=1;i<=num;i*=2)
        {
            num^=i;
        }
        return num;
    }
};