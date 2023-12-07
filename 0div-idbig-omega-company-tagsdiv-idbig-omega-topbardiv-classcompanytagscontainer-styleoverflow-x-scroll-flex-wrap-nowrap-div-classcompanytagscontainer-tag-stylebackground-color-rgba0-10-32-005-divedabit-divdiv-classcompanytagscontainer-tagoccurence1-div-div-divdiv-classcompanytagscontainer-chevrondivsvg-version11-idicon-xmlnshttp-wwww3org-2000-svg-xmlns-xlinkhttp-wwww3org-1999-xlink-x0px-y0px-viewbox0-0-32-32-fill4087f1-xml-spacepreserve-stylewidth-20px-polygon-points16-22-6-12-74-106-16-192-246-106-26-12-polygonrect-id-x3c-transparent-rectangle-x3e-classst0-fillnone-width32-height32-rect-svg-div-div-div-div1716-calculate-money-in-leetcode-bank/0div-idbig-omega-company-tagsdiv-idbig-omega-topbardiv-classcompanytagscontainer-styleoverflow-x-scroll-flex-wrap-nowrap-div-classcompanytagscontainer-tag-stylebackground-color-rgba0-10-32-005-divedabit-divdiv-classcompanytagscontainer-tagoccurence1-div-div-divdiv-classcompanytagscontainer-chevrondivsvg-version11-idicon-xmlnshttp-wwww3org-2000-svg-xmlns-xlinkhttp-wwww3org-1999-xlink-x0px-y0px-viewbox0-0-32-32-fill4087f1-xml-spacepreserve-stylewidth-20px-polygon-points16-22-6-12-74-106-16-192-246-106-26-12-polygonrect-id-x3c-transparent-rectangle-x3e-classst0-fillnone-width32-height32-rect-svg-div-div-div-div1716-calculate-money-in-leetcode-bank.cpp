class Solution {
public:
    int totalMoney(int n) {
        int start=1;
        int sum=0;
        int count=n%7==0?n/7:(n/7+1);
        while(count>=0)
        {
            int end=n>=7?7:n%7;
            int s=start;
            while(end>0)
            {
                sum+=s;
                s++;
                end--;
            }
            n-=7;
            start++;
            count--;
        }
        return sum;
    }
};