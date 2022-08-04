class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char> mpp1,mpp2;
        
        for(int i=0;i<s.length();i++)
        {
           if(!mpp1[s[i]] and !mpp2[t[i]])
           {
               mpp1[s[i]]=t[i];
               mpp2[t[i]]=s[i];
           }
           else if(mpp1[s[i]]!=t[i])
               return false;
        }
        
        return true;
           
    }
};