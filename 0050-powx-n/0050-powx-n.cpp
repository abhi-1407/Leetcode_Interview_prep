class Solution {
    double helper(double x,long long n)
    {
        if(n==0)
            return (double)1;
        if(n%2==0)
        {
            double h=helper(x,n/2);
            return h*h;
        }
        else
            return x*helper(x,n-1);
    }
public:
    double myPow(double x, int n) {
        double ans=helper(x,abs(n));
        if(n<0)
        {
            return (double)1/(double)ans;
        }
        return (double)ans;
            
    }
};


