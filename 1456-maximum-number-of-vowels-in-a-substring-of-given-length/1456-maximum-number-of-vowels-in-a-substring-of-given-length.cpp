class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int> mpp;
        int maxi=INT_MIN;
        int i=0,j=0;
        while(j<s.length())
        {
            mpp[s[j]]++;
            if(j-i+1==k)
            {
                int vcount=mpp['a']+mpp['e']+mpp['i']+mpp['o']+mpp['u'];
                maxi=max(vcount,maxi);
                mpp[s[i]]--;
                i++;
            }
            j++;
        
        }
        return maxi==INT_MAX?-1:maxi;
    }
};