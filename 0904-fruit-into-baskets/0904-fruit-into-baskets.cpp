class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int maxi=0,i=0,j=0;
        while(j<fruits.size())
        {
            mpp[fruits[j]]++;   
            if(mpp.size()==1)
            {
                maxi=max(maxi,mpp.begin()->second);
            }
            else if(mpp.size()==2)
            {
                int sum=0;
                for(auto it:mpp)
                    sum+=it.second;
                maxi=max(maxi,sum); 
            }            
            else if(mpp.size()>2)
            {
                while(mpp.size()>2)
                {
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]]==0)
                        mpp.erase(fruits[i]);     
                    i++;
                }
            }            
            j++;
        }
        return maxi;        
    }
};