class Solution {
public:
    int nthUglyNumber(int n) {
        long long num=1;
        set<long long> st;
        st.insert(num);
        for(int i=1;i<=n;i++)
        {
            num=*st.begin();
            st.erase(st.begin());
            st.insert(num*2);
            st.insert(num*3);
            st.insert(num*5);
        }
        return num;
    }
};