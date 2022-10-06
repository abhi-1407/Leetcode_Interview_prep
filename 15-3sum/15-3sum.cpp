class Solution {
//      sort(nums.begin(),nums.end());
//         unordered_map<int,int> mpp;
//         set<pair<pair<int,int>,int>> s;
//         vector<vector<int>>  ans;
//         for(int i=0;i<nums.size();i++)
//         {
//             mpp[nums[i]]=i;
//         }
//         vector<vector<int>> v;
//         for(int i=0;i<nums.size()-2;i++)
//         {
//             for(int j=i+1;j<nums.size()-1;j++)
//             {
//                 int CurrSum=nums[i]+nums[j];
//                 if((mpp.find(-CurrSum)!=mpp.end())&& (mpp[-CurrSum]>i) && (mpp[-CurrSum]>j))
//                 {
//                     s.insert({{nums[i],nums[j]},nums[mpp[-CurrSum]]});
//                 }
//             }
           
//         }    
    
//      for(auto it:s)
//      {
//          int a=it.first.first;
//          int b=it.first.second;
//          int c=it.second;
//          vector<int> temp;
//          temp.push_back(a);
//          temp.push_back(b);
//          temp.push_back(c);
//          ans.push_back(temp);
//      }
//      return ans;
    
   
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //  sort(nums.begin(),nums.end());
    //  vector<vector<int>> ans;
    //  for(int i=0;i<nums.size()-2;i++)
    //  {
    //      if(i>0 and nums[i-1]==nums[i])continue;
    //      int l=i+1;
    //      int h=nums.size()-1;
    //      while(l<h)
    //      {
    //          if(nums[l]+nums[h]+nums[i]==0)
    //          {
    //              vector<int> temp;
    //              temp.push_back(nums[i]);
    //              temp.push_back(nums[l]);
    //              temp.push_back(nums[h]);
    //              ans.push_back(temp);
    //              while(l<h && nums[l]==nums[l+1])l++;
    //              while(l<h && nums[h]==nums[h-1])h--;
    //              l++;
    //              h--;
    //              //break;
    //          }
    //          else if(nums[l]+nums[h]+nums[i] < 0)
    //          {
    //              l++;
    //          }
    //          else
    //          {
    //              h--;
    //          }
    //      }
    //  }
    //  return ans;
    
     vector<vector<int>> threeSum(vector<int>& nums){
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
       for(int i=0;i<nums.size()-2;i++)
       {
           if(i>0 and nums[i]==nums[i-1])
           continue;               
           int l=i+1;
           int h=nums.size()-1;           
           while(l<h)
           {
               if(nums[l]+nums[h]+nums[i]==0)
               {
                   vector<int> temp;
                   temp.push_back(nums[l]);
                   temp.push_back(nums[i]);
                   temp.push_back(nums[h]); 
                   ans.push_back(temp);
                   while(l<h && nums[l]==nums[l+1])l++;
                   while(l<h && nums[h]==nums[h-1])h--;
                   l++;
                   h--;
               }
               else if(nums[l]+nums[h]+nums[i] > 0)
               {
                   while(l<h && nums[h]==nums[h-1])h--;
                   h--;
               }
               else
               {
                   while(l<h && nums[l]==nums[l+1])l++;
                   l++;
               }
           }
           
       }
         return ans;
        
    }
    
       

};