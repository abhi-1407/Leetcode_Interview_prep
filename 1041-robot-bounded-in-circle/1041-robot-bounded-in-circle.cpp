class Solution { 
public:
    bool isRobotBounded(string instructions) {
        pair<int,int> dir={0,1},pos{0,0};//initially the robot is facing north and is at (0,0)
        for(auto it:instructions)
        {
            if(it=='L')
                dir={-dir.second,dir.first};
            else if(it=='R')
                dir={dir.second,-dir.first};
            else
                pos={dir.first+pos.first,dir.second+pos.second};//add direction with position           
        }
        return ((pos.first==0 && pos.second==0)||(dir.first!=0)||(dir.second!=1));//check if we have arrived at (0,0) or if we have changed our direction then return 'true'
    }
};