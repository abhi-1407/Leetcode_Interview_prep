class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
              vector <int> pos,neg;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<0)
                neg.push_back(nums[i]);
             else 
                pos.push_back(nums[i]);
            
        }
        
        int p=0, n=0;
        vector<int>ans;
        while(p < pos.size() && n < neg.size())
        {
			// You can add condition here for unequal no of possitive and negative array, that if one vector ends, then remaning elements get copied into ans vector
            ans.push_back(pos[p++]);        
            ans.push_back(neg[n++]);
        }
        return ans;
    }
        
};