class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mpp;
        int i=0,j=0;
        int wordsize=1;
        while(j<s.size())
        {
            if(s[j]==' ')
            wordsize++;
            j++;
        }
        if(wordsize!=pattern.size())
            return false;
        j=0;
        while(i<pattern.size() && j<s.size())
        {
            char ch=pattern[i++];
            string temp="";
            while(s[j]!=' ' && j<s.length())
            {
                temp+=s[j];
                j++;
            }
                j++;
            if(mpp.find(ch)==mpp.end())
            {
                mpp[ch]=temp;
            }
            else if(mpp[ch]!=temp)
                return false;          
        }
        set<string> st;
        for(auto it:mpp)
        {
            if(st.find(it.second)!=st.end())
                return false;
            st.insert(it.second);
        }
        return true;
        
    }
};