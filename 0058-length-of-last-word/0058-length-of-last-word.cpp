class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int wl=0;
        for(int i=n;i>=0;i--)
        {
            if(s[i]>='A'&& s[i]<='z')
                wl++;
            if(s[i]==' ' && wl>=1)
                break;
        }
         return wl;
    }
};