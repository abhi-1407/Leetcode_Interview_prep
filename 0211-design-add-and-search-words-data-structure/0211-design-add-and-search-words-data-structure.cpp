class Node{
  Node* links[26];
  bool flag=false;
  
  public:
  
  void createNode(char c,Node *n)
  {
      links[c-'a']=n;
  }

  bool exists(char c)
  {
      return links[c-'a']!=NULL;
  }
  Node* getNode(char c)
  {
      return links[c-'a'];
  }
  void setEnd()
  {
      flag=true;
  }
  bool getEnd()
  {
      return flag;
  }
    
 
};
class Trie {
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
         Node *temp=root;
         for(int i=0;i<word.size();i++)
         {
             if(!(temp->exists(word[i])))
             temp->createNode(word[i],new Node());
             temp=temp->getNode(word[i]);//now new temp points to the next addr
         }
         temp->setEnd();
    }
    
    bool search(string word,int index,Node *temp) {
        if(index==word.length())
            return temp->getEnd();
         if(word[index]=='.')
             {
                 for(int i=0;i<26;i++)
                 {
                     if((temp->exists(i+'a')) && search(word,index+1,temp->getNode(i+'a')))
                         return true;
                 }
                 return false;
             }
             else
             {
                 if(!temp->exists(word[index]))
                 return false;
                 return search(word,index+1,temp->getNode(word[index]));
             }
        return false;
    }
    bool helper(string word)
    {
        return search(word,0,root);
    }
    
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class WordDictionary {
    Trie t;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.helper(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */