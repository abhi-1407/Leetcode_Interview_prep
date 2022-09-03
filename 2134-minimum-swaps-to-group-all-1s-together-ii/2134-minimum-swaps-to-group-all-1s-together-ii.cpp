class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(auto it:nums)
        {
            if(it==1)
                count++;
        }
        if(count==0)
            return 0;
        nums.insert(nums.end(),nums.begin(),nums.end());
        int i=0,j=0;
        int temp=0;
        int mini=INT_MAX;
        while(j<2*n)//as array is circular in nature
        {
            if(nums[j]==1)
            {
                temp++;
            }
            if((j-i+1)==count)
            {                
                mini=min(mini,count-temp);
                temp-=(nums[i]==1);//slide the window by one
                i++;
            }
            j++;
        }
        return mini;
        
    }
};