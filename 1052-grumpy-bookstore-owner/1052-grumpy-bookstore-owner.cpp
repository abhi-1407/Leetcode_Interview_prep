class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int totalSum=0,n=customers.size();
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            totalSum+=customers[i];
        }
        int i=0,j=0,ans=0;
        while(j<n)
        {
           if(grumpy[j]==1)
           {
               totalSum+=customers[j];
           }
           if(j-i+1==minutes)
           {
               ans=max(ans,totalSum);
               if(grumpy[i]==1)
               {
                   totalSum-=customers[i];
               }
               i++;
           }
            j++;
        }
        return ans;
    }
};
