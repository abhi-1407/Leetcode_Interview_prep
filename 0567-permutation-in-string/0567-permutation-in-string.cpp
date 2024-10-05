class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;
        int n=s1.length();
        vector<int> mpp1(26,0),mpp2(26,0);
        for(int i=0;i<n;i++)
        {
            mpp1[s1[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            mpp2[s2[i]-'a']++;
        }
        for(int i=0;i<s2.length()-s1.length();i++)
        {
            if(mpp1==mpp2)
                return true;
            mpp2[s2[i]-'a']--;
            mpp2[s2[i+n]-'a']++;
        }
        if(mpp1==mpp2)
            return true;
        return false;
    }
};