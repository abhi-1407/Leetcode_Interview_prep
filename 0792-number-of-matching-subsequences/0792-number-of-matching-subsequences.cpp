class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mpp;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]].push_back(i);
        }
        for(auto it:words)
        {
            string temp=it;
            int start=-1;
            bool flag=true;
            for(auto i:temp)
            {
                if(mpp.find(i)==mpp.end())
                {
                    flag=false;
                    break;
                } 
                if(upper_bound(mpp[i].begin(),mpp[i].end(),start)==mpp[i].end())
                {
                    flag=false;
                    break;
                }
                start=mpp[i][upper_bound(mpp[i].begin(),mpp[i].end(),start)-mpp[i].begin()];
            }
            if(flag)
            {
                ans++;
            }
        }
        return ans;
    }
};
