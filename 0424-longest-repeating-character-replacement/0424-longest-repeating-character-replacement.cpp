class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,maxi=0;
        unordered_map<char,int> mpp;
        int tempk=k;
        int ans=0;
        while(j<s.length())
        {
            mpp[s[j]]++;
            int maxi=INT_MIN;
            for(auto it:mpp)
            {
                maxi=max(it.second,maxi);
            }
            while(((j-i+1)-maxi)>k)
            {
                mpp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};