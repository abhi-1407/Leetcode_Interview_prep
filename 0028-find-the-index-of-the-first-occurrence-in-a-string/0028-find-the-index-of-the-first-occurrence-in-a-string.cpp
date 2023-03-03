class Solution {
public:
    int strStr(string h, string n) {
        int m=n.size();
        for(int i=0;i<h.size();i++)
        {
            if(n[0]==h[i] && n==h.substr(i,m))
            {
                return i;
            }
        }
        return -1;
    }
};