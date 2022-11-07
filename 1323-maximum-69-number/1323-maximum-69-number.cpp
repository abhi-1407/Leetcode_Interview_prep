class Solution {
public:
    int maximum69Number (int num) {
        vector<int> s;
        while(num)
        {
            int n=num%10;
            s.insert(s.begin(),n);
            num/=10;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==6)
            {
                s[i]=9;
                break;
            }
        }        
        for(auto it:s)
        {
            num=num*10+it;            
        }
        return num;
    }
};