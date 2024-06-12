class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3]={0,0,0};
        int i=0;
        while(i!=nums.size())
        {
            if(nums[i]==0)
            { 
             arr[0]++;
             i++;
            }
            else if(nums[i]==1)
            {   arr[1]++;
                i++;
            }
            else
            {
             arr[2]++;
             i++;
            }
        }
    i=0;
       while(arr[0]>0)
       {
           nums[i++]=0;
           arr[0]--;
       }
       while(arr[1]>0)
       {
           nums[i++]=1;
           arr[1]--;
       }
       while(arr[2]>0)
       {
           nums[i++]=2;
           arr[2]--;
       }
    
    }
};