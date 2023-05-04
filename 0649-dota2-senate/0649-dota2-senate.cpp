class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int n=senate.size();
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='R')
                r.push(i);
            else
                d.push(i);
        }
        while(!r.empty() && !d.empty())
        {
            int p1=r.front();
            r.pop();
            int p2=d.front();
            d.pop();
            if(p1 > p2)
            {
                d.push(p2+n);
            }
            else
            {
                r.push(p1+n);
            }
        }
        return r.size() > d.size() ? "Radiant" : "Dire";
    }
};