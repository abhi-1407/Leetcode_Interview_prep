class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        string temp = s + s;
        for(int i=0;i<temp.size() - goal.size();i++){
            int start = i;
            int size = goal.size();
            if(temp.substr(start,size) == goal)
                return true;
        }
        return false;
    }
};