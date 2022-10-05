class Solution {
    bool solver(vector<int> &m,int index,int sides[])
    {
        if(index==m.size())
        {
            for(int i=0;i<4;i++)
            {
                if(sides[i]!=0)
                    return false;
            }
            return true;
        }        
        for(int i=0;i<4;i++)
        {
            if(m[index]<=sides[i])
            {
            sides[i]-=m[index];
            if(solver(m,index+1,sides))return true;
            sides[i]+=m[index];
            }
            
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int sum=0;
        for(auto it:matchsticks)
        {
            sum+=it;
        }
        if(sum%4!=0 || matchsticks.size()<4)
        {
            return false;
        }
        int sides[4];
        for(int i=0;i<4;i++)
        {
            sides[i]=sum/4;
        }
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return solver(matchsticks,0,sides);
        
        
    }
};