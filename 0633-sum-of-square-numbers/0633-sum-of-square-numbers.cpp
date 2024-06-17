class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=sqrt(c),b=0;
        while(b <= a)
        {
     
        if(pow(a,2) + pow(b,2)==c)
        {
            return true;
        }
        else if(pow(a,2) + pow(b,2) < c)
        {
            b++;
        }
        else 
        {
            a--;
        }
            
        }
        return false;
    }
};