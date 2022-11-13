class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i=0;
        string temp;
        for(;i<s.length();i++)
        {
            string ans;
            if(s[i]==' ')
                continue;
            while(s[i]!=' ' and i<s.size())
            {
                ans+=s[i];
                i++;
            }
            st.push(ans);
        }
        while(!st.empty())
        {
            temp+=st.top();
            if(st.size()!=1)
            temp+=" ";
            st.pop();
        }
        return temp;
    }
};