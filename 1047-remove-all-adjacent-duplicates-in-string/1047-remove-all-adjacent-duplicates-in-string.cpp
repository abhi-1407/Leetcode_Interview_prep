class Solution {

public:
    string removeDuplicates(string s) {
    stack<char> st;
    if(s.length()==1 || s.length()==0)
        return s;
    st.push(s[0]);    
    for(int i=1;i<s.length();i++)
    {
      if(st.empty())
          st.push(s[i]);
      else if((st.top()==s[i])&&(!st.empty()))
          st.pop();
      else
      st.push(s[i]);
      
    }
    string ans="";
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};