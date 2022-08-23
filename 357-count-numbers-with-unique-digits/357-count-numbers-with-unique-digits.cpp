class Solution {
    
    // for n=1 we have no as 10 so no of digitis=10
    // for n=2, we have 10 + 9*9
    // for n=3 we have 10 + 9*9 + 9*9*8
    // for n=4 we have 10 + 9*9 + 9*9*8 + 9*9*8*7
    //and so on...
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        int ans=10;//for n=1 or greater than 1 this much would be there
        int count=9;
        int temp=9;
        while(n-1>0)
        {
            temp*=(count--);//so that value is decremented once multiplied
            ans+=temp;//add it to ans
            n--;//reduce n
        }
        return ans;
        
    }
};