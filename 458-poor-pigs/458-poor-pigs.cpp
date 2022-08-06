class Solution {
public:
    int poorPigs(int buckets, int mD, int mT) {
       // int t=mT/mD;
       // int m=1,ans=1;
       // for(int i=1;i<=1000;i++)
       // {
       //     if(ans>=buckets)
       //     {
       //         m=i-1;
       //         break;
       //     }
       //     ans*=(t+1);
       // }
       //  return m;
    return ceil(log(buckets) / log(mT / mD + 1));//solving expression using log
    }
};