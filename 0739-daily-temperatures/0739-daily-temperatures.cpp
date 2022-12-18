class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else if(temperatures[i]>=temperatures[st.top()])
            {
                while(!st.empty() && temperatures[i]>=temperatures[st.top()])
                    st.pop();
                if(!st.empty())
                {
                    int ele=st.top();
                    ans[i]=ele-i;
                }
                st.push(i);
                
            }
            else
            {
                int ele=st.top();
                ans[i]=ele-i;
                st.push(i);
            }        
        }
        return ans;        
    }
};