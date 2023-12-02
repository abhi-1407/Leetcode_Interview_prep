class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>c(26,0);
        for(auto &it:chars)
        {
            c[it-'a']++;
        }

        int result=0;

        for(string &s:words)
        {
            bool status=true;
            vector<int>w(26,0);
            for(char &c:s)
            {
                w[c-'a']++;
            }

            for(int i=0;i<26;i++)
            {
                if(w[i]>c[i])
                {
                    status=false;
                    break;
                }
            }

            if(status)
            {
                result+=s.size();
            }
        }
        return result;
    }
};