class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        for(auto it:s)
        {
            if(it=='1')
                ones++;
        }
        
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            ans+='0';
        }
        
        if(ones==0)
            return ans;
        
        ans[s.length()-1]='1';
        ones--;
        for(int i=0;i<s.length();i++)
        {
            if(ones==0)
                break;
            ans[i]='1';
            ones--;
        }
        
        return ans;
    }
};