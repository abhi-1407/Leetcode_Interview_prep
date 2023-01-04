class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
       for(int i=0;i<strs[0].size();i++)
       {
           bool incr=true;
           for(int j=1;j<strs.size();j++)
           {
               
               if(strs[j-1][i]>strs[j][i])
               {
                   incr=false;
                   break;
               }
           }
           if(incr==false)
               count++;
       }
        return count;
    }
};