class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int index=0,count=0;
        while(index<costs.size() && coins>=costs[index])
        {
            coins-=costs[index];
            count++;           
            index++;
        }
        return count;
    }
};