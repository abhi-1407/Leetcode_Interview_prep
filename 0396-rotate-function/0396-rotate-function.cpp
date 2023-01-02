class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,f=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            f+=i*nums[i];
        }
        int l=1,n=nums.size(),r=0,nf=f;
        while(l<n)
        {
            r=l+n-1;
            int removed=(l-1)*nums[l-1];
            int added=r*nums[r%n];
            nf=nf-removed+added-sum;
            f=max(f,nf);
            l++;
        }
        return f;
    }
};