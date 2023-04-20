#define ll long long 
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
       ll sum=0,n=nums.size();
       for(ll i=0;i<nums.size();i++)
       {
           if(nums[i]>0)
               sum+=nums[i];
           
           nums[i]=abs(nums[i]);
       }
       sort(nums.begin(),nums.end());
       vector<ll> ans;
       priority_queue<pair<ll,ll>> pq;
       pq.push({sum-nums[0],0});
       ans.push_back(sum);
       while(ans.size()<k)
       {
           auto it=pq.top();
           pq.pop();
           ll s=it.first;
           ll index=it.second;
           if(index+1<n)
           {
               pq.push({s-nums[index+1]+nums[index],index+1});
               pq.push({s-nums[index+1],index+1});
           }
           ans.push_back(s);
       }
       return ans.back();
    }
};