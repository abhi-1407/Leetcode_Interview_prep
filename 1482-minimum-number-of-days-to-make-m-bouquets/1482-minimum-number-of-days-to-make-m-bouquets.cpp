class Solution {
    bool isPossible(vector<int>& bloomDay,int mid,int k,int m)
    {
        long long sum=0,i=0,count=0;
        while(i<bloomDay.size())
        {
            if(bloomDay[i]<=mid)//flower has bloomed
            {
                count++;
                if(count==k)
                {
                    count=0;
                    sum++;
                }
                if(sum==m)
                    return true;
                i++;
            }
            else
            {
                count=0;
                i++;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size(),low=*min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end()),ans=-1;
        if((unsigned)m*k>n)
            return -1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,mid,k,m))
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