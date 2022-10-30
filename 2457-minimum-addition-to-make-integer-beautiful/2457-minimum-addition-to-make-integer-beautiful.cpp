class Solution {
    long long helper(long long num)
    {
        long long temp=0;
        while(num)
        {
            int d=num%10;
            temp+=d;
            num=num/10;            
        }    
        return temp;
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long n0=n,base=1;
        while(helper(n)>target)
        {
            n=n/10+1;
            base *=10;
        }
        return n*base-n0;
    }
};