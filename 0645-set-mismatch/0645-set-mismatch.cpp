class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       long long n=nums.size(),sum=0,prod=0;
       vector<int> ans;
       sum=(n*(n+1))/2;
       prod=(n*(n+1)*(2*n+1))/6;
       for(auto it:nums)
       {
           sum-=it;
           prod-=it*it;
       }
       int missingno=(sum+(prod)/sum)/2;
       int repeatingno=missingno-sum;
       ans.push_back(repeatingno); 
       ans.push_back(missingno);
       return ans;
   }
};