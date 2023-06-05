class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope=0;
        double x=(coordinates[coordinates.size()-1][0]-coordinates[0][0]);
        if(x!=0)
        slope=(coordinates[coordinates.size()-1][1]-coordinates[0][1])/x;
        else 
            slope=1e9;
        for(int i=0;i<coordinates.size()-1;i++)
        {
            double tempx=(coordinates[i+1][0]-coordinates[i][0]);
            double tempslope=0;
            if(tempx!=0)
                tempslope=(coordinates[i+1][1]-coordinates[i][1])/tempx;
            else
                tempslope=1e9;
            if(tempslope!=slope)
                return false;
        }
        return true;
        
    }
};