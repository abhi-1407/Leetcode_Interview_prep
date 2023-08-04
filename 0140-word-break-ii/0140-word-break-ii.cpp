class Solution {
    void helper(vector<string> &ans,string temp,unordered_set<string> &st,string s,int index)
    {
        if(index==s.length())
        {
            ans.push_back(temp);
            return;
        }
        string t="";
        for(int i=index;i<s.length();i++)
        {
            t+=s[i];
            if(st.find(t)!=st.end())
            {
                if(index==0)
                {
                    helper(ans,t,st,s,i+1);
                }
                else
                {
                    helper(ans,temp+" "+t,st,s,i+1);   
                }
            }
        }
    }   
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto it:wordDict)
            st.insert(it);
        vector<string> ans;
        string temp="";
        helper(ans,temp,st,s,0);
        return ans;
    }
};