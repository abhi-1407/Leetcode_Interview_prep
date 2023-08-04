class Solution {
    bool helper(int index,string &s,unordered_set<string> &st,vector<int> &dp)
    {
        if(index==s.length())
            return true;
        if(dp[index]!=-1)
            return dp[index];
        string temp="";
        for(int i=index;i<s.length();i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end() && helper(i+1,s,st,dp))
            {
                return dp[index]=true;
            }
        }
        return dp[index]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto it:wordDict)
            st.insert(it);
        vector<int> dp(s.length(),-1);
        return helper(0,s,st,dp);
    }
};