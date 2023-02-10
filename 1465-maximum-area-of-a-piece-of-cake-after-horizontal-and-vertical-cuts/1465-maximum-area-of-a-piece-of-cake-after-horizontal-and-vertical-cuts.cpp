class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxlen=INT_MIN,maxbred=INT_MIN;
        for(int i=0;i<horizontalCuts.size()-1;i++)
        {
            maxlen=max(abs(horizontalCuts[i]-horizontalCuts[i+1]),maxlen);
        }
        for(int i=0;i<verticalCuts.size()-1;i++)
        {
            maxbred=max(abs(verticalCuts[i]-verticalCuts[i+1]),maxbred);
        }
        
        return (1ll*maxlen*maxbred) % 1000000007;
    }
};