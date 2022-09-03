class Solution {
    int count_digits(int n)
    {
        int count=0;
        while(n)
        {
            n=n/10;
            count++;
        }
        return count;
        
    }
    void helper(vector<int> &ans,int temp,int size,int diff)
    {
        if(count_digits(temp)==size)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<10;i++)
        {
            int last_digit=temp%10;//last digit of the current digit
            if(abs(last_digit-i)==diff)
            {
                helper(ans,temp*10+i,size,diff);
            }
        }
        
        
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<10;i++)
            helper(ans,i,n,k);
        return ans;
    }
};