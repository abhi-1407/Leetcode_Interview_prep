class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0,tw=0;
        for(auto it:bills)
        {
            if(it==5)
                f++;
            else if(it==10)
            {
                if(f>0)
                f--;
                else
                return false;
                t++;
            }
            else
            {
                if(t>0)
                {
                    t--;
                    f--;
                }
                else 
                {
                    f=f-3;
                }
            }
            if(f<0)
                return false;
            
        }
        return true;
    }
};