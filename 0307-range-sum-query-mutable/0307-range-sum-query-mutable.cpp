class NumArray {
    vector<int> tree;
    vector<int> temp;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        tree.resize(n+1,0);
        temp=nums;
        for(int i=0;i<nums.size();i++)
        {
            helper(i+1,nums[i]);
        }
    }
    void helper(int index,int diff)
    {
        while(index<tree.size())
        {
            tree[index]+=diff;
            index+=((index)&(-index));
        }
    }
    void update(int index, int val) {
        int diff=val-temp[index];
        temp[index]=val;
        helper(index+1,diff);
    }
    
    int sum(int index)
    {
        int sum=0;
        index=index+1;
        while(index>=1)
        {
            sum+=tree[index];
            index-=((index)&(-index));
        }
        return sum;
    }
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */