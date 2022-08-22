class Solution {
public:
    bool isPowerOfFour(int n) {
        long int i=1;
        while(i<n)
        {
            i=i*4;
        }
        if(i==n)
            return true;
        else 
            return false;
        
        
    }
};