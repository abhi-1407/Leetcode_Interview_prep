class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,n=s.length(),count=0;
        int a=0,b=0,c=0;
        while(r<n)
        {      
            if(s[r]=='a')
                a++;
            else if(s[r]=='b')
                b++;
            else
                c++;  
            while(a>0 && b>0 && c>0)
            {
                if(s[l]=='a')
                    a--;
                else if(s[l]=='b')
                    b--;
                else
                    c--;
                count+=n-r;
                l++;
            }   
            r++;
        }
        return count;
    }
};