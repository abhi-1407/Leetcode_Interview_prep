class Solution {
public:
    bool isPowerOfThree(int n) {
        long int i=1;
        while(i<n){
            i=i*3;
        }
        if(i==n)
            return true;
       else 
           return false;
       
    }
};