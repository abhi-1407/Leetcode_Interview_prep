class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty() || s[i]=='A' || s[i]=='C')
                st.push(s[i]);
            else if(s[i]=='B' && st.top()=='A' || s[i]=='D' && st.top()=='C')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();
    }
};