class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int i=0,j=0,maxi=0;
        while(j<s.size())
        {
            mpp[s[j]]++;
            if(j-i+1==mpp.size())
            {
                maxi=max(maxi,j-i+1);
                
            }
            else if(j-i+1 > mpp.size())
            {
                while(j-i+1>mpp.size())
                {
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0)
                        mpp.erase(s[i]);
                    i++;
                }
                
            }
            j++;
        }
        return maxi;
    }
};