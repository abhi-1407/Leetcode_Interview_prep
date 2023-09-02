class Solution {
    int helper(int index,unordered_set<string> &st,string s,vector<int> &dp)
    {
        if(index>=s.length())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int nottake=1+helper(index+1,st,s,dp);
        int take=INT_MAX;
        string temp="";
        for(int i=index;i<s.length();i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end())
            {
                take=min(take,helper(i+1,st,s,dp));
            }
        }
        return dp[index]=min(take,nottake);
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for(auto it:dictionary)
            st.insert(it);
        int n=s.length();
        vector<int> dp(n+1,-1);
        return helper(0,st,s,dp);
    }
};