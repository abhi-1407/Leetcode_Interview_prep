class Solution {
private:
bool helper(int i,string s,set<string> mpp,int dp[])
{
    if(i==s.size())return true;
    string temp;
    if(dp[i]!=-1)
    return dp[i];
    for(int j=i;j<s.size();j++)
    {
        temp+=s[j];
        if(mpp.find(temp)!=mpp.end())
        {
            if(helper(j+1,s,mpp,dp))
            return dp[i]=true;
        }        
    }
    return dp[i]=false;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        int dp[301];
        for(int i=0;i<301;i++)
            dp[i]=-1;
        for(auto a:wordDict)
            st.insert(a);
        return helper(0,s,st,dp);
        
    }
};