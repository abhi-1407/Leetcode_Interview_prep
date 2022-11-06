class Solution {
public:
    string orderlyQueue(string s, int k) {
if(k>1){
            sort(s.begin(),s.end()); 
            return s;
        }
        string ans=s;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            s+=s[i]; //append char to the end
            string str=s.substr(i+1);
            if(str<ans) ans=str;
        }
        return ans;
    }
};