class Solution {
public:
    int minSwaps(string s) {
      int count=0,maxcount=0;
      for(int i=0;i<s.length();i++)
      {
          if(s[i]==']')
              count++;
          else 
              count--;
          maxcount=max(maxcount,count);
      }
      return (maxcount+1)/2;
    }
};