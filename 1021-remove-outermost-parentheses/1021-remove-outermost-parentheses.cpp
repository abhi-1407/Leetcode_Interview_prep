class Solution {
public:
    string removeOuterParentheses(string s) {
        int opened=0;
        string ans="";
        for(auto it : s)
        {
            if(it=='(' and opened++>0)
            {
                ans+=it;
            }
            else if(it==')' and opened-->1)
            {
                ans+=it;
            }
        }
        return ans;
    }
};