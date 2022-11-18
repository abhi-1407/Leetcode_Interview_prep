/* Intuition:
If there's no intersection b/w the points then the x length/y length would come out to be negative,and hence we'll take common area as 0 in that case
min and max's difference would always come out to be 0 or negative
*/
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int A1=(ay2-ay1)*(ax2-ax1);
        int A2=(by2-by1)*(bx2-bx1);
        int common=0;
        int yover=(min(by2,ay2)-max(ay1,by1));
        int xover=(min(ax2,bx2)-max(bx1,ax1));
        if(xover>0 and yover>0)
            common=xover*yover;
        return A1+A2-common;
    }
};