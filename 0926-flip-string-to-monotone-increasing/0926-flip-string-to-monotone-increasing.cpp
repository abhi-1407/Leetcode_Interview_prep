class Solution {
public:
    int minFlipsMonoIncr(string s)
    {
        int ones=0,zeros=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                ones++;
            else
                zeros++;
            zeros=min(ones,zeros);
        }        
        return zeros;
    }
};