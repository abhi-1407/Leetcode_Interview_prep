class Solution {
    
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
/* if the no. of rotations are a lot then ultimately remainder of that value with n would be give the same ans*/
        k=k%n;
        vector<int> temp(n);
        for(int i=0;i<n;i++)
        {
            temp[(i+k)%n]=nums[i];
        }
        nums=temp;
    }
};