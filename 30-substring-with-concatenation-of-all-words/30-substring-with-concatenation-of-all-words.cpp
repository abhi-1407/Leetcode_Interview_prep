class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      string temp="";
      unordered_map<string,int> mpp;
      for(auto it: words)
          mpp[it]++;
      int wordcount=words.size();
      int wordsize=words[0].size();
      vector<int> ans;
      int TotalCount=wordsize*wordcount;
      /* total length of the words are more than the string length then return an empty vector */
      if(TotalCount > s.size())
      return ans;
        
     /* donot forget this "=" as otherwise it will miss one index i.e the last index after which occurence is not possible */
      for(int i=0;i<=s.length()-TotalCount;i++)
      {
          unordered_map<string,int> temp;
          for(int j=0;j<wordcount;j++)
          {
              int StartingIndex=i+j*wordsize;
              string tempWord=s.substr(StartingIndex,wordsize);
              if(mpp.find(tempWord)==mpp.end())
              break;              
              temp[tempWord]++;
              if(temp[tempWord]> mpp[tempWord])
              break;                  
              if(j+1==wordcount)//we have successfully found the word
              {
                  ans.push_back(i);
              }
          }
      }
        return ans;
    }
};