class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i=0,j=0,n=customers.size(),maxi=INT_MIN,curr=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
                curr+=customers[i];
        }
        while(j<n)
        {
            if(grumpy[j]==1)
            {
                curr+=customers[j];
            }
            if(j-i+1==minutes)
            {
                maxi=max(maxi,curr);
                if(grumpy[i]==1)
                {
                    curr-=customers[i];
                }
                i++;
                
            }
            j++;
        }
        return maxi;
    }
};