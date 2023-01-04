class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mpp;
        for(auto it:tasks)
        {
            mpp[it]++;
        }
        int count=0;
        for(auto it:mpp)
        {
            int freq=it.second;
            if(freq==1)
            return -1;
            if(freq>1 && freq%3==0)
            {
                count+=(freq/3);
                freq=freq%3;
            }
            else
            {
                count+=(freq/3)+1;
                freq=freq%3;
            }           

        }            
        return count;
        
        
    }
};