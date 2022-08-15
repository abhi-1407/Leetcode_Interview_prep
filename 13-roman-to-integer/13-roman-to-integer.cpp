class Solution {
public:
    int romanToInt(string s) {
        
        int n=s.length();
        int val=0;
        map<char,int> roman;
        roman.insert({'I',1});
        roman.insert({'V',5});
        roman.insert({'X',10}); 
        roman.insert({'L',50});
        roman.insert({'C',100});
        roman.insert({'D',500});
        roman.insert({'M',1000});

        string ans="";
        for(int i=0;i<n;i++)
        {
            if(i<n-1)
            {
            if(s[i]=='I' && s[i+1]=='V')
            {
                ans+="IIII";
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='X')
            {
                ans+="VIIII";
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='L')
            {
                ans+="XXXX";
                i++;
            }
            else if(s[i]=='X' &&s[i+1]=='C')
            {
                ans+="LXXXX";
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='D')
            {
                ans+="CCCC";
                i++;
            }
            else if(s[i]=='C' &&s[i+1]=='M')
            {
                ans+="DCCCC";
                i++;
            }
            else
            {
                 ans.push_back(s[i]);
            }
            }
            else
            {
                ans.push_back(s[i]);
            }
                
                
            
        }
        for(int i=0;i<ans.length();i++)
        {
            val+=roman[ans[i]];
        }
        return val;
    }
};