class Solution {
    static bool fn(string a,string b)
    {
        return a.size()<b.size();
    }
    bool compare(string &next,string &prev)
    {
        if(next.length()!=prev.length()+1)
            return false;
        int i=0,j=0,count=0;
        while(i<prev.length() && j<next.length())
        {
            if(prev[i]!=next[j])
            {
                count++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
            
        }
        if(i<prev.length() || j<next.length())
        {
            count++;
        }
        return count==1;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),fn);
        int n=words.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(compare(words[i],words[prev]) && dp[i] < 1+dp[prev])
                {
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};