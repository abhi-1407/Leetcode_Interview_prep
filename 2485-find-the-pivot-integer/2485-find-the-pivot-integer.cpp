class Solution {
public:
    int pivotInteger(int n) {
        int sum=(n*(n+1))/2;
        int curr=0;
        for(int i=1;i<=n;i++)
        {
            curr+=i;
            if(curr==sum+i-curr)
                return i;
        }
        return -1;
    }
};


    