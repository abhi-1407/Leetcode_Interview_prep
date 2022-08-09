class Solution {
//     int MaxEle(vector<int> nums,int start,int k)
//     {
//         int i=start,maxi=INT_MIN;
//         while(k--)
//         {
//             maxi=max(maxi,nums[i++]);
//         }
//         return maxi;
//     }
    
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         for(int i=0;i+k-1<nums.size();i++)
//         {
//             ans.push_back(MaxEle(nums,i,k));
//         }
//         return ans;
//    };
     
    
public:
   
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<k;i++)// for the first three elements we will try maintaing the decreasing order
        {
             //always keep the condition for dq.empty() in the first place else you'll get a runtime error
            while(!dq.empty() && dq.back()<nums[i] )//remove the element if the front is smaller 
            {
                dq.pop_back();
            } 
            dq.push_back(nums[i]);//now push it
                       
         }
        ans.push_back(dq.front());//max element for the first window is at the front
        for(int i=k;i<nums.size();i++)
        {
            if(dq.front()==nums[i-k])dq.pop_front();//if the element which is greater was a part of previous window then we have to remove it from                                                          the front
          while(!dq.empty() && dq.back()<nums[i])// same as previous
          {
              dq.pop_back();   
          }
            dq.push_back(nums[i]);
            ans.push_back(dq.front());            
        }
        return ans;
    }   
       
};