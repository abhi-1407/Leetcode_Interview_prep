class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if((hand.size() % groupSize)!=0)
            return false;
        map<int,int> mpp;
        for(auto it:hand)
        {
            mpp[it]++;
        }
        /* donot use for(auto it:mpp) as , if say the first elements freq is not zero even after 1 iteration then also it would move onto the next element, try this for 1,1,2,2,3,3 */
        for(auto it=mpp.begin();it!=mpp.end();)
        {
            if(it->second>0)
            {
                int ele=it->first;
                for(int i=0;i<groupSize;i++)
                {
                   if(mpp[i+ele]>0)
                      mpp[i+ele]--;
                   else
                       return false;
                }                
            }
            else
                it++;
        }
        return true;
    }
};