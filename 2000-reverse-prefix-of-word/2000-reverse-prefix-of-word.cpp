class Solution {
    int findIndex(string word,char ch)
    {
        int index=-1;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==ch)
                return i;
        }
        return index;
    }
    
    void reverseHelper(string &word,int index)
    {
        for(int i=0,j=index;i<=j;i++,j--)
        {
            char ch=word[i];
            word[i]=word[j];
            word[j]=ch;
        }
    }
public:
    string reversePrefix(string word, char ch) {
        int index=findIndex(word,ch);
        reverseHelper(word,index);
        return word;
    }
};