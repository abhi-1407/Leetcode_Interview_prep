class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       priority_queue<int> pq;
       int mini=INT_MAX;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]%2==0)
           {
               pq.push(nums[i]);
               mini=min(nums[i],mini);
           }
           else
           {
               pq.push(nums[i]*2);
               mini=min(nums[i]*2,mini);
           }
       }
       int ans=INT_MAX;
       while(!pq.empty())
       {
           int ele=pq.top();
           pq.pop();
           ans=min(ans,ele-mini);
           if((ele%2)!=0)
               break;
           mini=min(mini,ele/2);
           pq.push(ele/2);
       }
        return ans;
    }
};