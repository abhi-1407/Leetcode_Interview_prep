class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0,n=secret.length(),cow=0;
        unordered_map<char,int> mpp1,mpp2;
        /*ones in the right place are bulls, rest are cows */
        /*no of cows can be rearranged to make a bull so if there are 2 cows in sec and 3 in pattern then 2 can be rearranged to become bulls and hence only 2 should be returned*/ 
        for(int i=0;i<n;i++)
        {
            
            if(secret[i]==guess[i])
            {
                a++;               
            }
            else
            {
                mpp1[secret[i]]++;
                mpp2[guess[i]]++;
            }            
        }
        for(auto it:mpp1)
        {
            if(mpp2.find(it.first)!=mpp2.end())
            {
                cow+=min(it.second,mpp2[it.first]);
            }            
        }
        return to_string(a)+"A"+to_string(cow)+"B";  
    }
};