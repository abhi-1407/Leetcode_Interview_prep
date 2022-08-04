class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,int> mpp1,mpp2;
        for(int i=0;i<s.length();i++)
        {
           mpp1[s[i]]=i+1;
           mpp2[t[i]]=i+1;
        }
        for(int i=0;i<s.length();i++)
        {
           if(mpp1[s[i]]!=mpp2[t[i]])
               return false;
        }
        
        return true;
           
    }
};