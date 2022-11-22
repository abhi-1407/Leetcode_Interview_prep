class Solution {
public:
    int isSquare(int x)
    {
        int s=sqrt(x);
        if(s*s==x)
        return 1;
        else
        return 0;
    }
    int numSquares(int n) {
        if(isSquare(n))
            return 1;
        for(int i=1;i<=(int)sqrt(n);i++)
        {
            if(isSquare(n-(i*i)))
                return 2;
        }
        //lagrange four square theorem
        //The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7)
        while(n%4==0)
        {
            n/=4;
        }
        if(n%8==7)
        return 4;
        else
        return 3;
        
            
    }
};