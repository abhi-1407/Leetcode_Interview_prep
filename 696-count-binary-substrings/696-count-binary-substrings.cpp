class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0;
        int curr=1;
        int sum=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i-1]==s[i])
            {
                 curr++;
            }
            else
            {
                sum+=min(curr,prev);
                prev=curr;
                curr=1;
            }
        }
        sum+=min(prev,curr);
        return sum;
        
    }
};