class Solution {
public:
    string breakPalindrome(string palindrome) {
    if(palindrome.size()==1)
        return "";
    /* As it is palindrome so the first half is smaller than the second half but since we want the lexiographically smallest string so we need to make changes only in the first half */
    for(int i=0;i<palindrome.size()/2;i++)
    {
        if(palindrome[i]!='a')
        {
            palindrome[i]='a';
            return palindrome;
        }
    }
    //if we are reaching till this point then all are a's only so lets make the last character as b
    palindrome[palindrome.size()-1]='b';
    return palindrome;
}
};