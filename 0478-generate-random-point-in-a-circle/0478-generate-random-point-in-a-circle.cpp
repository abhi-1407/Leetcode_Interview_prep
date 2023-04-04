class Solution {
    double x,y,r;
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius,x=x_center,y=y_center;
        
    }
    
    vector<double> randPoint() {
        vector<double> ans(2);
        double rr=sqrt((((double)rand())/(RAND_MAX)))*r;
        double theta=2*M_PI*(((double)rand())/(RAND_MAX));
        ans[0]=x+rr*cos(theta);
        ans[1]=y+rr*sin(theta);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */