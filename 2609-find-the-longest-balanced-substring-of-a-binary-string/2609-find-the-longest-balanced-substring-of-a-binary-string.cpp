class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int i=0,maxi=0,n=s.length(),countzero=0,countone=0;
        while(i<n)
        {
            while(i<n && s[i]=='1')
                i++;
            countzero=0,countone=0;
            while(i<n and s[i]=='0')
            {
                countzero++;
                i++;
            }
            while(i<n and s[i]=='1')
            {
                countone++;
                i++;
            }
            maxi=max(maxi,2*min(countone,countzero));
            
        }
        return maxi;
    }
};