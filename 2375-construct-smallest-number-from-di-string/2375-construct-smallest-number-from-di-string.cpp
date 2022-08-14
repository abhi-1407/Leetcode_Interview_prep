class Solution {
public:
    string smallestNumber(string pattern) {
        string ans;
        stack<int> st;
        for(int i=0;i<=pattern.size();i++)
        {
            st.push(i+1);
            /* reverse the string when we encounter and I */
            if(i==pattern.size() || pattern[i]=='I')
            {
                while(!st.empty())
                {
                    ans+=to_string(st.top());
                    st.pop();                    
                }
            }
        }
        return ans;
        
    }
};