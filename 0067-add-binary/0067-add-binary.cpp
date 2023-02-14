class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        if(a.length()==0)
            return b;
        if(b.length()==0)
            return a;
        int i=a.length()-1,j=b.length()-1,carry=0;
        while(i>=0 || j>=0 || carry)
        {
            int val=carry;
            if(i>=0)
            {
                val+=(a[i]-'0');
                i--;
            }
            if(j>=0)
            {
                val+=(b[j]-'0');
                j--;
            }
            carry=val/2;
            ans+=((val%2)+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};