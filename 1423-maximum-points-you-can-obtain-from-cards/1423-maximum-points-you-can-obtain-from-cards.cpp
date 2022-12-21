/* Intuition is that since we can pick only k cards in a row so we can simply consider all sliding windows of size n-k  and subtract it from the corresponding prefix sum and get the answer*/

/*if nk becomes 0 , when nk==n, then it would be wrong, so for k==cardPoints.size(), make a separate case */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int nk=n-k;//not k
        vector<int> prefix(n);
        prefix[0]=cardPoints[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=cardPoints[i]+prefix[i-1];
        }
        int total=prefix[n-1];
        if(nk==0)
            return total;
        int j=nk-1,i=0;
        int ans=0;
        while(j<n)
        {
            int sum=0;
            if(i>0)
            {
                sum=prefix[j]-prefix[i-1];
            }
            else
            {
               sum=prefix[j]; 
            }
            sum=total-sum;
            ans=max(ans,sum);
            i++;
            j++;
        }
        return ans;
    }
};