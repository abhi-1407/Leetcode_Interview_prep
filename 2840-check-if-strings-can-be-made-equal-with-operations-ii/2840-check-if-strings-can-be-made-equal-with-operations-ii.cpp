class Solution {
public:
    bool checkStrings(string s1, string s2) {
         int n=s1.size();
        map<char,int> m11, m12, m21, m22;
        for(int x=0; x<n; x++)
        {
            if(x%2)
            {
                m11[s1[x]]++;
                m21[s2[x]]++;
            }
            else
            {
                m12[s1[x]]++;
                m22[s2[x]]++;
            }
        }
        return m11==m21 && m12==m22;
    }
};