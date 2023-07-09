class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        unordered_map<char,int> mpp;
        for(auto it:s)
            mpp[it]++;
        for(char c1='a';c1<='z';c1++)
        {
            for(char c2='a';c2<='z';c2++)
            {
                if(mpp[c1]==0 || mpp[c2]==0 || c1==c2)
                    continue;
                for(int rev=1;rev<=2;rev++)
                {
                    int cnt1=0,cnt2=0;
                for(auto i:s)
                {
                    cnt1+=c1==i;
                    cnt2+=c2==i;
                    if(cnt1<cnt2)
                    {
                        cnt1=0;
                        cnt2=0;
                    }
                    if(cnt1>0 && cnt2>0)
                    {
                        ans=max(ans,cnt1-cnt2);
                    }
                }
                reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};