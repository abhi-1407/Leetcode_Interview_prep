class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> mpp1,mpp2,mpp3,mpp4;
        for(int i=0;i<s1.length();i++)
        {
            if(i%2==0)
                mpp1[s1[i]]++;
            else
                mpp2[s1[i]]++;
        }
        for(int i=0;i<s2.length();i++)
        {
            if(i%2==0)
                mpp3[s2[i]]++;
            else
                mpp4[s2[i]]++;
        }
        return (mpp1==mpp3 && mpp2==mpp4);
    }
};