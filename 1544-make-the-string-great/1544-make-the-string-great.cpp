class Solution {
public:
    string makeGood(string s) {
        string ans="";
        int i=0;
        stack<char> st;
        while(i<s.length())
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                char ele=st.top();
                if(abs(ele-s[i])==32)
                    st.pop(); 
                else
                    st.push(s[i]);
            }
            i++;
            
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;        
    }
};