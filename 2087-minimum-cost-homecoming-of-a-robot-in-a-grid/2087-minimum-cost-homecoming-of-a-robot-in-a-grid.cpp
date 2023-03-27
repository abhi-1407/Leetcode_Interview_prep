class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int i=startPos[0],j=startPos[1],ans=0;
        while(i>homePos[0])
        {
            i-=1;
            ans+=rowCosts[i];
        }
        while(i<homePos[0])
        {
            i+=1;
            ans+=rowCosts[i];
        }
        while(j<homePos[1])
        {
            j+=1;
            ans+=colCosts[j];
        }
        while(j>homePos[1])
        {
            j-=1;
            ans+=colCosts[j];
        }
        return ans;
    }
};