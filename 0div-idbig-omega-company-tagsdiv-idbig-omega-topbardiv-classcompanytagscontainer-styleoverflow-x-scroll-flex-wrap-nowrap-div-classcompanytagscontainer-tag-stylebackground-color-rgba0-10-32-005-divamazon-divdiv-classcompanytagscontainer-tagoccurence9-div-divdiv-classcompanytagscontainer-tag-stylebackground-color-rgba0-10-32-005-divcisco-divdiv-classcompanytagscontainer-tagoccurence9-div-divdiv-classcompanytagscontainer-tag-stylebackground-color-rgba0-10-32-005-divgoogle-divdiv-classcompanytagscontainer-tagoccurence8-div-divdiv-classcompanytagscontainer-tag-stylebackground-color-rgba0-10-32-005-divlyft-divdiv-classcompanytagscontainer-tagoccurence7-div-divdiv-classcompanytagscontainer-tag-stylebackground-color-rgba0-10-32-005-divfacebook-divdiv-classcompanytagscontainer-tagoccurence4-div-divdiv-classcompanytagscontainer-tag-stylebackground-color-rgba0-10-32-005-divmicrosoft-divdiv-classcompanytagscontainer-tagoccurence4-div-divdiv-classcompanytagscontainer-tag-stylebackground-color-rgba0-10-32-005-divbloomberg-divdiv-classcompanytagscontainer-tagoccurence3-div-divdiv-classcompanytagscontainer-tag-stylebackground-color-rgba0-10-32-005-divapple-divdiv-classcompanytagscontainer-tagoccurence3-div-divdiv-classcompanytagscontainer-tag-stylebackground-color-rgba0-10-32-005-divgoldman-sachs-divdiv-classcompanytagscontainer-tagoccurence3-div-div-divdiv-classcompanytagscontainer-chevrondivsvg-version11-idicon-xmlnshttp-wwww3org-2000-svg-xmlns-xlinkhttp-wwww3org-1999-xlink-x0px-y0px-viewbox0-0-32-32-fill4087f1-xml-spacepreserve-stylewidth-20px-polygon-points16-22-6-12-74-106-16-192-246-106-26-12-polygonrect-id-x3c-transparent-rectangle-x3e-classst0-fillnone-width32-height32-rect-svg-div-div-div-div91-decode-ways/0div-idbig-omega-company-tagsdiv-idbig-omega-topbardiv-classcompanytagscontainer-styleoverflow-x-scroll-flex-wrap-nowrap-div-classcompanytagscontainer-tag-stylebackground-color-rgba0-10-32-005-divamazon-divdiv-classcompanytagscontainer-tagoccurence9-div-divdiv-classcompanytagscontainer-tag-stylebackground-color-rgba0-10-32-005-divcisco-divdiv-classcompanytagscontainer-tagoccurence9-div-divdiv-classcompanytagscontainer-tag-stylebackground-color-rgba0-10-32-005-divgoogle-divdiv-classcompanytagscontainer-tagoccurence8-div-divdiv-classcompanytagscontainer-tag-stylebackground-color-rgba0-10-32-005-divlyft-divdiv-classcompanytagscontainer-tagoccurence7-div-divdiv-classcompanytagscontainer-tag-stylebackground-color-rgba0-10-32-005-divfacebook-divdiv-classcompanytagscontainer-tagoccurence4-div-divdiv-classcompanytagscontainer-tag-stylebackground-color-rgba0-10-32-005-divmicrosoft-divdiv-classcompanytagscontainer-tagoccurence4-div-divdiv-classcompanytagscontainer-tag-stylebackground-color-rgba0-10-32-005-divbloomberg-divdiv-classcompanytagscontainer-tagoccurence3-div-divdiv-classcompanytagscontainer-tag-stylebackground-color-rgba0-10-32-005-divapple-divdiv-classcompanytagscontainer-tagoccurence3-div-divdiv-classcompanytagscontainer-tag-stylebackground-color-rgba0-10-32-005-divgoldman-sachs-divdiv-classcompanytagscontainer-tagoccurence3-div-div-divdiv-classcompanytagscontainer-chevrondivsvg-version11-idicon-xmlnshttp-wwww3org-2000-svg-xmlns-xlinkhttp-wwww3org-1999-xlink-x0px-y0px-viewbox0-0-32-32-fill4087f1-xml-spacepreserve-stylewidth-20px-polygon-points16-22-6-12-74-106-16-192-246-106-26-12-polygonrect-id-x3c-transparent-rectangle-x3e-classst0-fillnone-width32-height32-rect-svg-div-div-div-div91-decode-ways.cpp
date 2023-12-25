class Solution {
public:
    int helperDP(string s)
    {
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            int way1=0,way2=0;
            if(s[i]!='0')
            {
                way1=dp[i+1];
            }
            if((i+1<n)&&((s[i]=='1'&& s[i+1]<='9') || (s[i]=='2' && s[i+1] <='6')))
            {
                way2=dp[i+2];
            }
            dp[i]=way1+way2;
        }
        return dp[0];
    }
public:
    int numDecodings(string s) {
        int n=s.length();
         return helperDP(s);
        
    }
};