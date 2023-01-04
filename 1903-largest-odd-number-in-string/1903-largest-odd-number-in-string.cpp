class Solution {
public:
    string largestOddNumber(string num) {
        int maxi=INT_MIN;
        string s="";
        for(int i=num.size()-1;i>=0;i--)
        {
            int n=num[i]-'0';
            if((n&1)==1)
            {
                s+=(num[i]);
            }
            else
            {
                if(s.size()>0)
                    s+=num[i];
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};