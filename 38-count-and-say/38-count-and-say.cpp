class Solution {
    string helper(string s)
    {
        int count=1;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
           if(s[i]==s[i+1]) 
           {
               count++;
           }
           else if(i==s.length()-1)
           {
             
               ans.push_back(count+'0');
               ans.push_back(s[i]);
           }
           else
           {
               
               ans.push_back(count+'0');
               ans.push_back(s[i]);
               count=1;
           }
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s="1";
        for(int i=2;i<=n;i++)
        {
            string ans=helper(s);
            s=ans;
        }
        
        return s;
        
    }
};