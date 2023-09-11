class Solution {

public:
    bool canMakeSubsequence(string str1, string str2) {
        int index1=0,index2=0;
        while(index1<str1.length() && index2<str2.length())
        {
            if(str1[index1]==str2[index2] || ((str1[index1]-'a'+1)%26==(str2[index2]-'a')%26))
            {
                index1++;
                index2++;
            }
            else
            {
                index1++;
            }
        }
        if(index2==str2.length())
            return true;
        if(index1==str1.length())
            return index2==str2.length();
        return true;
    }
};