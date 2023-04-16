class Solution {
    unordered_set<string> test;
    void recursion(string s,int index,unordered_set<string> &stt)
    {   
        if(stt.find(s)!=stt.end())
            return;
        if(index==0)
        {
            if(helper(s)==0)
            {
                if(stt.find(s)==stt.end())
                    stt.insert(s);
            }
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            
            string a=s.substr(0,i);
            string b=s.substr(i+1);
            if(test.find(a+b)==test.end())
            {
                recursion(a+b,index-1,stt);
                test.insert(a+b);
            }
        }
    }
    
    int helper(string &s)
    {
        stack<char> st;
        for(auto it:s)
        {
            if(it=='(')
            {
                st.push(it);
            }
            else if(it==')')
            {
                if(st.size()==0)
                {
                    st.push(it);
                }
                else if(st.top()=='(')
                {
                    st.pop();
                }
                else if(st.top()==')')
                {
                    st.push(it);
                }
            }
        }
        return st.size();
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        int x=helper(s);
        unordered_set<string> stt;
        recursion(s,x,stt);
        vector<string> ans;
        for(auto it:stt)
        {
            ans.push_back(it);
        }
        return ans;
    }
};