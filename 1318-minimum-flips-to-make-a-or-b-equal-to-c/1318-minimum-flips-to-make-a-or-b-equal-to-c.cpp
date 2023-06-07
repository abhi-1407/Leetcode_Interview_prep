class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a>0 || b>0 || c>0)
        {
            int bit1=a&1;
            int bit2=b&1;
            int bit3=c&1;
            if(bit3==0)
            {
                if(bit1==0)
                {
                    flips+=(bit2==0)?0:1;
                }
                else
                {
                    flips+=(bit2==0)?1:2;
                }
            }
            else
            {
                if(bit1==0)
                {
                    flips+=(bit2==0)?1:0;
                }
                else
                {
                    flips+=(bit2==0)?0:0;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flips;
    }
};