class Solution {
    bool helper(vector<int>& dist,double hour,int speed)
    {
        double ans=0;
        for(int i=0;i<dist.size()-1;i++)
        {
            if(dist[i]%speed==0)
            {
                ans+=dist[i]/speed;
            }
            else
            {
                ans+=(dist[i]/speed)+1;
            }
        }
        ans+=(double)dist[dist.size()-1]/speed;
        return ans<=hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1,high=pow(10,7)+1,ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(helper(dist,hour,mid))
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