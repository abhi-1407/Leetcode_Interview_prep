class Solution {
    vector<int> perm;
public:
    Solution(vector<int>& nums) {
        perm=nums;
    }
    
    vector<int> reset() {
        return perm;
    }
    
    vector<int> shuffle() {
        int leftsize=perm.size(),n=perm.size();
        vector<int> temp=perm;
        for(int i=n-1;i>=0;i--)
        {
            int rindex=rand()%leftsize;
            swap(temp[rindex],temp[i]);
            leftsize--;
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */