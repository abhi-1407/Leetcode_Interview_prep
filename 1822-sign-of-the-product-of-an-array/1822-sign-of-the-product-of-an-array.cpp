class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=1;
        for(auto it:nums)
        {
            if(it==0)
                return 0;
            else if(it<0)
                neg*=-1;
        }
        return neg;
    }
};