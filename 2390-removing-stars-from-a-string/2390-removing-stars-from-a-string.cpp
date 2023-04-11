class Solution {
public:
    string removeStars(string s) {
        string ans="";
        int i=0;
        stack<char> st;
        while(i<s.length())
        {
            if(s[i]>='a' && s[i]<='z')
            {
                st.push(s[i]);
            }
            else if(s[i]=='*')
            {
                st.pop();
            }
            i++;
        }
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};