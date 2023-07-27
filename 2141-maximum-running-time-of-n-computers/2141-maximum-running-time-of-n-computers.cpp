class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        int m = b.size();
        sort(b.begin(),b.end());
        long long sum = accumulate(begin(b),end(b),0LL);
        int i=m-1;
        while(i>=0 && sum/n < b[i] ){
            sum -= b[i];
            n--;i--;
        }
        return sum/n;
    }
};