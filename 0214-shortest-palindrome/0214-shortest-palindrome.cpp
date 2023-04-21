class Solution {
    /* This was the point till which they were equal */
public:
    string shortestPalindrome(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        string str=s+"#"+temp;
        int n=str.length();
        vector<int> lps(n,0);
        int len=0,i=1;
        while(i<n)
        {
            if(str[i]==str[len])
            {
                lps[i]=len+1;
                len++;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    len=lps[len-1];
                }
            }
        }
        temp=s.substr(lps[n-1]);
        reverse(temp.begin(),temp.end());
        return temp+s;
        
        
    }
};