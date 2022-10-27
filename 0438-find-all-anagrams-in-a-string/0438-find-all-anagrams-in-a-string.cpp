class Solution {
    
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0,k=p.size();
        vector<int> ans;
        vector<int> mpp1(26,0),mpp2(26,0);
        for(auto i:p)
            mpp1[i-'a']++;
        while(j<s.size())
        {
            mpp2[s[j]-'a']++;
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)//window found
            {
                
                if(mpp1==mpp2)
                {
                    ans.push_back(i);                    
                }
                mpp2[s[i]-'a']--;
                i++;
                j++;
            }
            
        }
        return ans;        
    }
};