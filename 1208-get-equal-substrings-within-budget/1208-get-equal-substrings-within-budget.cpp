class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0,maxi=0,cost=0;
        while(j<s.size())
        {
            cost+=abs(s[j]-t[j]);
            while(cost>maxCost)
            {
                cost-=abs(s[i]-t[i]);
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;    
        }
        return maxi;        
    }
};