class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxi=0,d=0;
        for(int i=0;i<special.size()-1;i++)
        {
            int diff=special[i+1]-special[i]-1;
            maxi=max(diff,maxi);
        }
        d=max(special[0]-bottom,top-special[special.size()-1]);
        return max(d,maxi);
    }
};