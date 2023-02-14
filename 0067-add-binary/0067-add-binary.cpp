class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        if(a.length()==0)
            return b;
        if(b.length()==0)
            return a;
        int i=a.length()-1,j=b.length()-1,carry=0;
        while(i>=0 && j>=0)
        {
            int val=carry+(a[i]-'0')+(b[j]-'0');
            ans.push_back(((val%2)+'0'));
            carry=(val/2);
            i--;
            j--;
        }
        while(i>=0)
        {
            int val=carry+(a[i]-'0');
            ans.push_back(((val%2)+'0'));
            carry=(val/2);
            i--;
        }
        while(j>=0)
        {
            int val=carry+(b[j]-'0');
            ans.push_back(((val%2)+'0'));
            carry=(val/2);
            j--;
        }
        if(carry>0)
        ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
