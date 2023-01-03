class Solution {
    bool isPossible(int maxi,vector<int> &weights,int days)
    {
        int counter=1,sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            if(sum>maxi)
            {
                counter++;
                sum=weights[i];
            }
        }
        return counter<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN,high=0,ans=-1;
        for(auto it:weights)
        {
            low=max(low,it);//if the ship carries only one weight,so we will take the largest weight
            high+=it;//max when all have to be carried in one ship
        }
        while(low<=high)
        {
            int mid=low+((high-low)>>1);
            if(isPossible(mid,weights,days))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};