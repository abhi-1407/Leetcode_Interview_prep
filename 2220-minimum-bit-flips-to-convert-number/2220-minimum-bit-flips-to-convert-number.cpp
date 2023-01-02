class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start,y=goal,count=0;
        while(x or y)
        {
            if((x&1)!=(y&1))
                count++;
            x=x>>1;
            y=y>>1;
        }
        return count;
    }
};