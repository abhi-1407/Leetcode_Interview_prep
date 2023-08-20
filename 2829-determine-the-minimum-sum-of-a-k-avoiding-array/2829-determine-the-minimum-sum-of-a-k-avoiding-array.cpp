class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        int count=n,sum=0;
        int i;
        for(i=1;i<=n;i++)
        {
            if(st.count(k-i)<=0)
            {
                st.insert(i);
                sum+=i;
            }
        }
        while(st.size()<n)
        {
            if(st.count(k-i)<=0)
            {
                st.insert(i);
                sum+=i;
            }
            i++;
        }
        return sum;
    }
};