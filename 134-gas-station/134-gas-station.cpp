class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum1=0,sum2=0;
    for(int i=0;i<gas.size();i++)
    {
        sum1+=gas[i];
        sum2+=cost[i];
    }
    if(sum2>sum1)
        return -1;
    
    int sum=0;
    int index=0;
    for(int i=0;i<gas.size();i++)
    {
        sum+=gas[i]-cost[i];
        if(sum<0)
        {
            index=i+1;
            sum=0;
        }
    }
    return index;
    }
};