class Solution {
    bool isPossible(int mid,int h,vector<int> &piles)
    {
        long long ans=0;
        for(int i=0;i<piles.size();i++)
        {
            ans+=ceil(1.0*piles[i]/mid);
        }
        return ans<=h;            
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int s=1,ans=-1,e=*max_element(piles.begin(),piles.end());
       while(s<=e)
       {
           int mid=s+(e-s)/2;
           if(isPossible(mid,h,piles))
           {
               ans=mid;
               e=mid-1;
           }
           else
           {
               s=mid+1;
           }
       }
       return ans;
        
    }
};