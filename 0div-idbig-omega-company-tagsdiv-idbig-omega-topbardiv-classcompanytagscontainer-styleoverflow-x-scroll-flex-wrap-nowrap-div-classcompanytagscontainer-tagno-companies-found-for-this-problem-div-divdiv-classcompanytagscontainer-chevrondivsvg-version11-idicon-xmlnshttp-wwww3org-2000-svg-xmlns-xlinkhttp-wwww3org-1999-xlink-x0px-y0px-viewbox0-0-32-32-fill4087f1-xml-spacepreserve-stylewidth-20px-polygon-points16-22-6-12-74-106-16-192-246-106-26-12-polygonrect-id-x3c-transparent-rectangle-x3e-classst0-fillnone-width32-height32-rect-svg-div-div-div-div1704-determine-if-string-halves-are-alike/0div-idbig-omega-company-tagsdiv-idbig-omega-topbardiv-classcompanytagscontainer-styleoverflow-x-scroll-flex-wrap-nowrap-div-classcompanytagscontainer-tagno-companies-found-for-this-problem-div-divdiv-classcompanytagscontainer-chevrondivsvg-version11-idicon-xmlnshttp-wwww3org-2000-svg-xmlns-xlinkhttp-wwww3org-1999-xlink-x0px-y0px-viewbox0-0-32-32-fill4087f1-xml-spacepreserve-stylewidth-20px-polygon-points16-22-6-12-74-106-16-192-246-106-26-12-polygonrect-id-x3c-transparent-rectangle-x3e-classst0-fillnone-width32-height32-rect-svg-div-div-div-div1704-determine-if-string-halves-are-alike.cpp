class Solution {
public:
    bool halvesAreAlike(string s) {
          transform(s.begin(), s.end(), s.begin(), ::toupper); 
    int a = s.size()/2-1;
    int b = a+1;
    int s1 = 0, s2 = 0;
    int i = 0;

    while(i <= a && b < s.size()){
    if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') s1++;
    if(s[b] == 'A' || s[b] == 'E' || s[b] == 'I' || s[b] == 'O' || s[b] == 'U') s2++;
    b++;
    i++;
    }
    if(s1 == s2) return true;
    return false;
    }
};