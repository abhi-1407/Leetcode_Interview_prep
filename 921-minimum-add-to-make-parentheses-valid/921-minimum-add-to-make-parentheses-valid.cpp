class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening=0,closing=0;
        for(int i=0;i<s.length();i++)
        {
            if(opening==0 && s[i]==')')
                closing++;
            else if(s[i]==')' && opening>0)
                opening--;
            else
                opening++;
        }
        return opening +closing;
        
    }
};