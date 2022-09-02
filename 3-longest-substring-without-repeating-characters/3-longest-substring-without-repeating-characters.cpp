class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int l=0,r=0,maxlen=0;
      set<char> Set;
      while(r<s.length())
      {
         if(Set.find(s[r])==Set.end())//check if the character is unique or not
         {
            Set.insert(s[r]);//insert this character
            maxlen=max(maxlen,r-l+1);//compute maximum length now and update if needed
            r++;//increment the counter
         }
         else
         {
             Set.erase(s[l]);//else remove the last character
             l++;//increment the left pointer
         }
      }          
      return maxlen;//return maximum length 
        
    }
};