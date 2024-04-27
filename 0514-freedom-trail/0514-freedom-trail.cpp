class Solution {
    int helper(int stringIdx,int keyIdx,string ring,string key,int dp[101][101])
    {
        if(keyIdx==key.size())
            return 0;
        
        if(dp[stringIdx][keyIdx]!=-1)
            return dp[stringIdx][keyIdx];
        
        int mini=1e9;
        int size=ring.length();
        int idx=stringIdx;
        int count=0;
        
        do
        {
            if(ring[idx]==key[keyIdx])
            {
                mini=min(mini,1+count+helper(idx,keyIdx+1,ring,key,dp));
            }
            idx++;
            count++;
            idx=idx%size;
            
        }
        while(stringIdx!=idx);
        
        idx=stringIdx;
        count=0;
        do
        {
            if(ring[idx]==key[keyIdx])
            {
                mini=min(mini,1+count+helper(idx,keyIdx+1,ring,key,dp));
            }
            idx--;
            count++;
            idx+=size;
            idx=idx%size;
            
        }
        while(stringIdx!=idx);
        
        return dp[stringIdx][keyIdx]=mini;
    }
public:
    int findRotateSteps(string ring, string key) {
        int dp[101][101];
        memset(dp , -1 , sizeof(dp));
        return helper(0,0,ring,key,dp);
    }
};