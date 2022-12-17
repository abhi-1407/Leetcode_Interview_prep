class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        long long sum1=nums[0],index=0,sum2=0,n=nums.size();
        for(int i=1;i<n;i++)
        {
            sum2+=nums[i];
        }
        long long s2=sum2; 
        long long s1=sum1;
        s1/=1;
        n-1!=0?s2/=n-1:s2=0;
        long long diff=abs(s2-s1);
        for(int i=1;i<n;i++)
        {
            sum1=sum1+nums[i];
            sum2=sum2-nums[i];
            long long s2=sum2; 
            long long s1=sum1;
            s1/=i+1;
            n-i-1!=0 ? s2/=n-i-1 : s2=0;
            if(diff>abs(s1-s2))
            {
              diff=abs(s1-s2);
              index=i;
            }
        }
        return index;
    }
};