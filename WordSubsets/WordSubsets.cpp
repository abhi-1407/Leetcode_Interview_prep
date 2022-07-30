vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
{
        unordered_map<char,int> mpp1;
        for(int i=0;i<words2.size();i++)
        { 
            unordered_map<char,int> temp;
            for(int j=0;j<words2[i].size();j++)
            {
                temp[words2[i][j]]++;
                mpp1[words2[i][j]]=max(mpp1[words2[i][j]],temp[words2[i][j]]);
            }
            
            
        }
        vector<string> ans;
        for(int i=0;i<words1.size();i++)
        {
            unordered_map<char,int> mpp2;
            for(int j=0;j<words1[i].size();j++)
            {
                mpp2[words1[i][j]]++;
            }
            bool flag=true;
            for(auto it: mpp1)
            {
                if(mpp2.find(it.first)==mpp2.end())
                {
                    
                    flag=false;
                    break;
                }
                else 
                {
                    if(mpp2[it.first]<it.second)
                    {
                        flag=false;
                        break;
                    }
                    
                }
            }
            if(flag)
            {
                ans.push_back(words1[i]);
            }
        
        
       
        }
    return ans;
}