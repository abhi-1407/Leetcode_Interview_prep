class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0;
        for(auto it:s)
        {
            if(it=='a')
                a++;
            else if(it=='b')
                b++;
            else
                c++;
        }
        if(a<k || b<k || c<k)
        {
            return -1;
        }
        int n=s.length();
        a-=k;
        b-=k;
        c-=k;
        int mx=0,i=0,j=0;
        int WindowCountA=0,WindowCountB=0,WindowCountC=0;
        while(j<n)
        {
            if(s[j]=='a')
                WindowCountA++;
            else if(s[j]=='b')
                WindowCountB++;
            else
                WindowCountC++;
            
            while(a < WindowCountA || b < WindowCountB || c < WindowCountC)
            {
                if(s[i] == 'a'){
                    WindowCountA--;
                }
                else if(s[i] == 'b'){
                  WindowCountB--;
                }
                else{
                    WindowCountC--;
                }
                i++;
            }
            mx = max(mx,j-i+1);
            j++;
        }
        return n - mx;
    }
};