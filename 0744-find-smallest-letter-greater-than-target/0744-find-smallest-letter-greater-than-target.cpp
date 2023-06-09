class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(),letters.end());
        int i=0;
        while(i<letters.size())
        {
            if(letters[i]<=target)
                i++;
            else
                break;
        }
        if(i==letters.size())
            return letters[0];
        else
            return letters[i];
    }
};