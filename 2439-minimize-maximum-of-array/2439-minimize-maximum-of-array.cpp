/* Least possible maximum is the average of all the numbers as the total remains constant*/
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
       long long res=0,total=0;
       for(int i=0;i<nums.size();i++)
       {
            total+=nums[i];
            long long val=ceil((total)/(i+1.0));
            res=max(res,val);
       }
       return res;
    }
};