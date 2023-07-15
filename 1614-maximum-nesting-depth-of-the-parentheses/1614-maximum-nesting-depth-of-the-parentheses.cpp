class Solution {
public:
    int maxDepth(string s) {
        int maxi=0,cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                cnt++;
                maxi=max(maxi,cnt);
            }
            else if(s[i]==')')
            {
                cnt--;
            }
        }
        return maxi;
    }
};