class Solution {
public:
    double average(vector<int>& salary) {
        int ans=0;
        for(auto it:salary)
        ans+=it;
        int mini=INT_MAX,maxi=INT_MIN;
        for(auto it:salary)
        {
            mini=min(it,mini);
            maxi=max(it,maxi);
        }
        
        return ((double)(ans-(mini+maxi))/(double)(salary.size()-2));
    }
};