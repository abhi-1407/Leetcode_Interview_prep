class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++)
    {
        temp1.push_back(nums[i]);
    }
    for(int i=n;i<2*n;i++)
    {
        temp2.push_back(nums[i]);
    }
    int i=0,j=0,index=0;
    while(index<2*n)
    {
        nums[index++]=(temp1[i++]);
        nums[index++]=(temp2[j++]);
    }
    return nums;
    
    }
};