class Solution {
public:
    int minOperations(string s) {
        int num1=0,num2=1;
        string s1="",s2="";
        for(int i=0;i<s.length();i++)
        {
            s1+=to_string(num1);
            s2+=to_string(num2);
            num1=!num1;
            num2=!num2;
        }
        int count1=0,count2=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=s1[i])
                count1++;
            if(s[i]!=s2[i])
                count2++;
        }
        return min(count1,count2);
    }
};