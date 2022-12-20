class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n)
            return "0";
        if(k==0)
            return num;
        string ans="";
        stack<char> st;
        st.push(num[0]);
        int lim=k;
        for(int i=1;i<num.size();i++)
        {
            while(lim>0 && !st.empty() && num[i]<st.top())
                {
                    st.pop();
                    lim--;
                }
                st.push(num[i]);               
        }                                 
        while(!st.empty() && lim>0)//in case all the elements are in inc. order
        {
            lim--;
            st.pop();
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int index=0;
        while(ans[index]=='0' && index<ans.size())
        {
            index++;
        }
        return ans.substr(index,ans.size())==""?"0":ans.substr(index,ans.size());
    }
};