class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
       sort(asteroids.begin(),asteroids.end());
       long long sum=mass,i=0;
       while(i<asteroids.size())
       {
           if(sum<asteroids[i])
               return false;
           sum+=asteroids[i];
           i++;
       }
       return true;
    }
};