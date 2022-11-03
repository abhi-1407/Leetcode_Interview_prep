class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        int ans=0,maxi=0;
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            reverse(temp.begin(),temp.end());
            if(mpp[temp]>0)
            {
                ans+=4;
                mpp[temp]--;
            }
            else
            {
                mpp[words[i]]++;
            }
        }
        for(auto it:mpp)
        {
            if(it.first[0]==it.first[1] && mpp[it.first]>0)
                return ans+mpp[it.first]*2;
        }
        return ans;
    }
};